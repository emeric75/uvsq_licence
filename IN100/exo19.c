#include "uvsqgraphics.h"

int main()
{
	init_graphics(900,600);
	POINT v1,v2,v3,v4;
	v1.x = 300; v1.y = 0;
	v2.x = 300; v2.y = 600;
	v3.x = 600; v3.y = 0;
	v4.x = 600; v4.y = 600;
	draw_line(v1,v2,white);
	draw_line(v3,v4,white);
	
	POINT P;
	P=wait_clic();
	
	/*if(P.x < 300){
		draw_circle(P,50,blue);
	}
	if(P.x >= 300 && P.x < 600){
		draw_circle(P,50,white);
	}
	if(P.x >= 600){
		draw_circle(P,50,red);
	}*/
	
	if(P.x < 300){
		draw_circle(P,50,blue);
	}else{
		if(P.x < 600){
			draw_circle(P,50,white);
		}else{
			draw_circle(P,50,red);
		}
	}
	
	wait_escape();
	exit(0);
}
