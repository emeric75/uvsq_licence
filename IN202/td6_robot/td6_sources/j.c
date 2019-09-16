float degres = 360.0/(0.043*3.14159265359);
task main(){
	OnFwd(OUT_AB,50);
	SetSensorColorFull(IN_3);
	while(Sensor(IN_3) != INPUT_BLACKCOLOR ){} // && MotorRotationCount(OUT_A) < degres);
	Off(OUT_AB);
}
