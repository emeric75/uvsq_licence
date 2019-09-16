#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	
	POINT p;
	
	p = wait_clic();
	draw_circle(p,100,green);
	p = wait_clic();
	
	draw_circle(p,100,green);	
	
	p = wait_clic();
	draw_circle(p,100,green);
		
	p = wait_clic();
	draw_circle(p,100,green);
		
	p = wait_clic();
	draw_circle(p,100,green);
		
	p = wait_clic();
	draw_circle(p,100,green);
		
	p = wait_clic();
	draw_circle(p,100,green);	
	
	p = wait_clic();
	draw_circle(p,100,green);	
	
	p = wait_clic();
	draw_circle(p,100,green);	
	
	p = wait_clic();
	draw_circle(p,100,green);
	
	wait_escape();
	exit(0);
}
