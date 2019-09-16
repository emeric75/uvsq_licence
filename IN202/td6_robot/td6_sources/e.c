task main(){
	float degres = 360.0/(0.043*3.14159265359);
	int k=0;
	OnFwd(OUT_AB,-50);
	while(MotorRotationCount(OUT_A) > -degres){
		PlayToneEx(10*k,10,10,0);
		Wait(10);
		k++;
	}
	Off(OUT_AB);
}
