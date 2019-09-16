#include <uvsqgraphics.h>
int main () {
	init_graphics(600, 600);
	
	POINT pts[20];
	int rayons[20];
	for(int i = 0; i<20; i++){
		pts[i].x = alea_int(600);
		pts[i].y = alea_int(600);
		rayons[i] = alea_int(40);
	}
	
	for(int i=0; i<20; i++){
		draw_circle(pts[i], rayons[i], orange);
	}
	wait_escape();
}
