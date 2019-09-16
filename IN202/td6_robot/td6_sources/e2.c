task main(){
	float degres = 360.0/(0.043*3.14159265359);
	OnFwd(OUT_AB,-50);
	while(MotorRotationCount(OUT_A) < degres);
	Off(OUT_AB);
}
