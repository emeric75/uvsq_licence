#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT P1,P2,c;
	P1.x=0; P1.y=0;
	P2.x=10; P2.y=10;
	
	draw_fill_rectangle(P1,P2,blue);
	c=wait_clic();
	while(c.x>=10 || c.y >= 10){
		draw_circle(c,50,blue);
		c=wait_clic();
	}
	
	wait_escape();
	exit(0);
}
