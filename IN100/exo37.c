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
	
	for(int i = 0; i < 10; i = i+1){
		p=wait_clic();
		draw_circle(points[9-i],20,black);
	}
	
	wait_escape();
	exit(0);
}
