float angle = 360.0*0.3/0.043;
int pos_min;
task roue_Ag()
{
	RotateMotor(OUT_A,50, ((pos_min - 90.0))/360.0*angle);
}

task roue_Bg()
{
	RotateMotor(OUT_B,-50,((pos_min - 90.0))/360.0*angle);
}

task roue_Ad()
{
	RotateMotor(OUT_A,-50,((pos_min - 90.0))/360.0*angle);
}

task roue_Bd()
{
	RotateMotor(OUT_B,50,((pos_min - 90.0))/360.0*angle);
}

task main(){
	int min = 35;
	pos_min = -1;
	SetSensorLowspeed(IN_4);
	RotateMotor(OUT_C, -50, 90);
	for(int a = 0; a<180; a+=25){
		RotateMotor(OUT_C, 10, 25);
		if(SensorUS(IN_4)<35){
			PlayToneEx(500,250,10,0);
			if(SensorUS(IN_4)<min){
				min = SensorUS(IN_4);
				pos_min = a;
			}
			Wait(500);
		}
		//Wait(100);
	}
	//RotateMotor(OUT_C, -50, 90);
	/*if(pos_min != -1){
		for(int a = 180; a>pos_min; a-=15){
		RotateMotor(OUT_C, -10, 15);
		Wait(100);
		}	
	}*/
	if(pos_min -90 >= 0){
		start roue_Ag;
		start roue_Bg;
	}
	else{
		start roue_Ad;
		start roue_Bd;
	}
	RotateMotor(OUT_C, -50, 90);
}
