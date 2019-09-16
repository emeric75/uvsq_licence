#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	POINT P1,P2,P3,P4,P5,P6,P7,P8,P9,P10;
	P1.x = 100; P1.y = 100;
	P2.x = 300; P2.y = 100;
	P3.x = 100; P3.y = 200;
	P4.x = 300; P4.y = 200;
	P5.x = 100; P5.y = 300;
	P6.x = 300; P6.y = 300;
	P7.x = 100; P7.y = 400;
	P8.x = 300; P8.y = 400;
	P9.x = 100; P9.y = 500;
	P10.x = 300; P10.y = 500;
	
	draw_line(P1,P2,red);
	draw_line(P3,P4,blue);
	draw_line(P5,P6,green);
	draw_line(P7,P8,orange);
	draw_line(P9,P10,yellow);
	
	wait_escape();
	exit(0);
	
}
