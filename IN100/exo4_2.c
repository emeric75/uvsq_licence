#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	int i;
	POINT p;
	for(i=0 ; i<10 ; i=i+1){
		p=wait_clic();
		fill_screen(black);
		draw_circle(p,100,green);
	}
	
	wait_escape();
	exit(0);
}
