#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT points[10];
	POINT p;
	
	for(int i = 0; i < 10; i = i+1){
		p = wait_clic();
		draw_circle(p,20,red);
		points[i] = p;
	}
	
	for(i = 0; i < 10; i = i+1){
		draw_circle(points[i],20,blue);
	}
	
	wait_escape();
	exit(0);	
}
