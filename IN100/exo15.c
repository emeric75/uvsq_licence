#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	
	POINT l1,l2;
	l1.x=400;l1.y=0;
	l2.x=400;l2.y=600;
	draw_line(l1,l2,white);
	
	POINT P1,P2;
	P1 = wait_clic(); P2 = wait_clic();
	if(P1.x < 400){
		if(P2.x < 400){
			draw_line(P1,P2,red);
		}
		else{
			draw_line(P1,P2,blue);
		}
	}else{
		if(P2.x < 400){
			draw_line(P1,P2,blue);
		}
		else{
			draw_line(P1,P2,red);
		}
	}
	wait_escape();
	exit(0);
}

