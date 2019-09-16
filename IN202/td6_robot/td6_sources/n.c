int freq = 400;

task son(){
	while(1){
		PlayToneEx(freq,50 + 5*SensorUS(IN_4),25,0);
		Wait(50 + 5*SensorUS(IN_4));
	}
}
task update(){
	while(1){
		freq = 800 - 4 * SensorUS(IN_4);
		NumOut(LCD_LINE2,LCD_LINE3,SensorUS(IN_4),1);
	}
}
task main(){
	SetSensorLowspeed(IN_4);
	start son;
	start update;
	while(1){
		OnFwd(OUT_AB,50);
		while(SensorUS(IN_4) > 10){}
		Off(OUT_AB);
		while(SensorUS(IN_4) < 10){}
	}
}
