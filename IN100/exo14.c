#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	
	POINT P1,P2;
	P1.x=400; P1.y=0;
	P2.x=400; P2.y=600;
	
	draw_line(P1,P2,white);
	
	POINT P = wait_clic();
	POINT P_miroir;
	P_miroir.x = P.x + 2*(400-P.x);
	P_miroir.y=P.y;
	if (P.x < 400){ 
		draw_circle(P_miroir,50,red);
	}
	else{
		draw_circle(P_miroir,50,blue);
	}
	
	wait_escape();
	exit(0);
}
