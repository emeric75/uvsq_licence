#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	
	POINT P1,P2;
	P1.x=400; P1.y=0;
	P2.x=400; P2.y=600;
	
	draw_line(P1,P2,white);
	
	POINT P = wait_clic();
	if (P.x < 400){
		draw_circle(P,50,blue);
	}
	else{
		draw_circle(P,50,red);
	}
	
	wait_escape();
	exit(0);
}
