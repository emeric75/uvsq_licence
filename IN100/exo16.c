#include "uvsqgraphics.h"

int main()
{
	init_graphics(800,600);
	
	POINT v1,v2;
	v1.x=400;v1.y=0;
	v2.x=400;v2.y=600;
	draw_line(v1,v2,white);
	
	POINT t1,t2,t3;
	t1=wait_clic(); t2=wait_clic(); t3=wait_clic();
	if(t1.x < 400){
		if(t2.x < 400){
			if(t3.x < 400){
				draw_line(t1,t2,blue);
				draw_line(t2,t3,blue);
				draw_line(t3,t1,blue);
			}
		}
	}else{
		if(t2.x >= 400){
			if(t3.x >= 400){
				draw_line(t1,t2,blue);
				draw_line(t2,t3,blue);
				draw_line(t3,t1,blue);
			}
		}
	}
	wait_escape();
	exit(0);
}
