#include <uvsqgraphics.h>

int main () {
	int width,height;
	width = 452;
	height = 320;
	init_graphics(width,height);
	
	POINT P1,P2;
	P1.x=0;P1.y=0;
	P2.x=0;P2.y=height;
	
	while(P1.x<=width){
		draw_line(P1,P2,white);
		P1.x=P1.x+100;P2.x=P2.x+100;
	}
	
	wait_escape();
	exit(0);	
}
