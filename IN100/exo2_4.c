#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	POINT P1,P2;
	
	P1.x=200; P1.y=200;
	P2.x=300; P2.y=200;
	draw_line(P1,P2,red);
	
	P1.x=P2.x; P1.y=P2.y;
	P2.x=300; P2.y=300;
	draw_line(P1,P2,blue);
	
	P1.x=P2.x; P1.y=P2.y;
	P2.x=200; P2.y=300;
	draw_line(P1,P2,green);
	
	P1.x=P2.x; P1.y=P2.y;
	P2.x=200; P2.y=200;
	draw_line(P1,P2,yellow);
	
	
	wait_escape();
	exit(0);	
}
