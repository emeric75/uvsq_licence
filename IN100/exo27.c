#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT P1,P2;
	COULEUR coul;
	P1.x=0;P1.y=0;
	P2.x=0;P2.y=HEIGHT;
	
	for(int i = 0; i < floor(WIDTH/100.0); i=i+1){
		P1.x=P1.x+100;
		P2.x=P2.x+100;
		if(i%2 == 0){
			coul = red;
		}else{
			coul = blue;
		}
		draw_line(P1,P2,coul);
	}
		
	wait_escape();
	exit(0);	
}
