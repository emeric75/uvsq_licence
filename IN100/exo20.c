#include "uvsqgraphics.h"

int main()
{
	init_graphics(900,600);
	POINT P;
	P=wait_clic();
	
	if(P.x % 2 == 0)
	{
		if(P.y % 2 == 0)
		{
			draw_circle(P,50,red);
		}else{
			draw_circle(P,50,yellow);
		}
	}else{
		if(P.y % 2 == 0)
		{
			draw_circle(P,50,blue);
		}else{
			draw_circle(P,50,green);
		}
	}
	wait_escape();
	exit(0);
}
