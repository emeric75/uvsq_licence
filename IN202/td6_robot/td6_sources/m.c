task main(){
	int freq = 600;
	OnFwd(OUT_AB,50);
	SetSensorColorFull(IN_3);
	while(Sensor(IN_3) !=  INPUT_WHITECOLOR){
		switch(Sensor(IN_3)){
			case INPUT_BLACKCOLOR: freq = 300; break;
			case INPUT_BLUECOLOR:  freq = 500; break;
			case INPUT_GREENCOLOR: freq = 700; break;
			case INPUT_YELLOWCOLOR:freq = 900; break;
			case INPUT_REDCOLOR:   freq = 1100; break;
			default: break;
		}
		PlayToneEx(freq,50,10,0);
		Wait(50);
	}
	Off(OUT_AB);
}
