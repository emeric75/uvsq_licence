int ok = 1;
task tourne(){
	float degres = 360.0/(0.043*3.14159265359);
	RotateMotor(OUT_AB,-50,degres);
	ok = 0;
}
task fait_du_son(){
	int k = 0;
	while(ok){
		PlayToneEx(10*k,10,10,0);
		Wait(10);
		k++;
	}
}
task main(){
	start tourne;
	start fait_du_son;
}

