float angle = 360.0*0.3/0.043;
int rot,ok_a=0,ok_b=0,sens,ok_depl = 0;
task rot_ag()
{
	ok_a=0;
	RotateMotor(OUT_A,50,rot/720.0*angle);
	ok_a=1;
}
task rot_bg()
{
	ok_b = 0;
	RotateMotor(OUT_B,-50,rot/720.0*angle);
	ok_b = 1;
}
task rot_ad()
{
	ok_a=0;
	RotateMotor(OUT_A,-50,rot/720.0*angle);
	ok_a=1;
}
task rot_bd()
{
	ok_b = 0;
	RotateMotor(OUT_B,+50,rot/720.0*angle);
	ok_b = 1;
}
task rotate_alea(){
	rot = Random(71)+20;
	sens = Random(2);
	if(sens){
		start rot_ag;
		start rot_bg;
	}else{
		start rot_ad;
		start rot_bd;
	}
}

task rot_90g(){
	rot = 90;
	sens = 0;
	if(sens){
		start rot_ag;
		start rot_bg;
	}else{
		start rot_ad;
		start rot_bd;
	}
}
task rot_90d(){
	rot = 90;
	sens = 1;
	if(sens){
		start rot_ag;
		start rot_bg;
	}else{
		start rot_ad;
		start rot_bd;
	}
}

/*task test()
{
	while(!ok_depl){
		if(Sensor(IN_1)){
			Off(OUT_AB);
			PlayToneEx(750,500,10,0);
			Wait(500);
			start rot_90d;
			Wait(700);
			
		}
	}
}*/

task capteur_ultrason()
{
	while (!ok_depl){
		if(SensorUS(IN_4)<25){
			Off(OUT_AB);
			PlayToneEx(900,500,10,0);
			Wait(1000);
			start rot_90d;
			RotateMotor(OUT_C,-50,90);
			PlayToneEx(700,500,10,0);
			Wait(1000);
			OnFwd(OUT_AB,50);
			PlayToneEx(500,500,10,0);
			Wait(1000);
			start rot_90d;
			RotateMotor(OUT_C,50,90);
		}
	}
	
	
}

task main()
{
	SetSensorTouch(IN_1);
	SetSensorTouch(IN_2);
	SetSensorLowspeed(IN_4);
	while(1){
		start rotate_alea;
		while(ok_a == 0 || ok_b == 0);
		ok_a=0; ok_b = 0;
		OnFwd(OUT_AB,50);
		start capteur_ultrason;
		Wait(Random(3000)+1500);
		ok_depl = 1;
		Off(OUT_AB);
		ok_depl = 0;
	}
	ok_depl = 1;
}
