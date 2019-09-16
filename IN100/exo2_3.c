#include <uvsqgraphics.h>

int main () {
	init_graphics(800,600);
	
	POINT P1,P2;
	
	P1.x = 20; P1.y = 20;
	P2.x = P1.x + 100; P2.y = P1.y + 100;
	
	draw_rectangle(P1,P2,bleu);
	
	wait_escape();
	exit(0);
	
}
