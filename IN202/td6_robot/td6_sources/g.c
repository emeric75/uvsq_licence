float angle = 360.0*0.3/0.043;
float distance = 360.0/(4*0.043*3.14159265359);
int ok_turn = 1;
int ok_avancer = 0;
task a(){
	RotateMotor(OUT_A,50,angle/8);
}
task b(){
	RotateMotor(OUT_B,-50,angle/8);
}
task avancer(){
	ok_avancer = 0;
	RotateMotor(OUT_AB, 50, distance);
	ok_avancer = 1;
}
task quart(){
	ok_turn = 0;
	start a;
	start b;
	ok_turn = 1;
}

task main(){
	for(int i = 0; i<4; i++){
		while(ok_turn == 0);
		start avancer;
		while(ok_avancer == 0);
		start quart;
	}
}
