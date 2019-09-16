#include "uvsqgraphics.h"

int main(){
	init_graphics(800,600);
	
	int r;
	POINT P1,P2,P3;
	
	r=50;
	P1.x = 200; P1.y = 300;
	P2.x = 500; P2.y = P1.y;
	P3.x = (P1.x + P2.x)/2; P3.y = (P1.y + P2.y)/2;
	
	draw_line(P1,P2,red);
	draw_circle(P1,r,red);
	draw_circle(P2,r,red);
	draw_circle(P3,r,red);
	
	wait_escape();
	exit(0);
	
}
