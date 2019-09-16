#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	
	POINT v1,v2;
	v1.x=400;v1.y=0;
	v2.x=400;v2.y=600;
	draw_line(v1,v2,white);
	
	POINT h1,h2;
	h1.x=0;h1.y=300;
	h2.x=800;h2.y=300;
	draw_line(h1,h2,white);
	
	POINT P;
	P=wait_clic();
	
	if((P.x < 400 && P.y >= 300) || (P.x >= 400 && P.y < 300)){
		draw_circle(P,50,blue);
	}else{
		draw_circle(P,50,red);
	}
	wait_escape();
	exit(0);
}
