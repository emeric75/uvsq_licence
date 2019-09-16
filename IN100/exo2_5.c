#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT P1,P2,P3,P4;
	P1.x= 95; P1.y=145;
	P2.x=145; P2.y=195;
	P3.x=145; P3.y=145;
	P4.x= 95; P4.y=195;
	
	draw_rectangle(P1,P2,blue);
	draw_line(P1,P2,red);
	draw_line(P3,P4,red);
	
	
	
	wait_escape();
	exit(0);	
}
