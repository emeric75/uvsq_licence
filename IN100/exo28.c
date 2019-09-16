#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT P1,P2,c;
	P1.x=WIDTH/2;P1.y=0;
	P2.x=WIDTH/2;P2.y=HEIGHT;
	
	draw_line(P1,P2,white);
	
	for(int i = 0; i < 5; i=i+1){
		c=wait_clic();
		if(c.x<WIDTH/2){
			draw_circle(c,50,red);
		}else{
			draw_circle(c,50,blue);
		}
	}
		
	wait_escape();
	exit(0);	
}
