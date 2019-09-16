#include <uvsqgraphics.h>

int main () {
	int taille = 800;
	init_graphics(taille,taille);
	int delta = 5;
	
	
	POINT p1,p2,p3,p4;
	p1.x = 0;p1.y = 0;
	p2.x = WIDTH;p2.y = HEIGHT;
	p3.x = 0; p3.y= HEIGHT;
	p4.x = WIDTH; p4.y = 0;
	draw_line(p1,p2,blue);
	draw_line(p3,p4,blue);
	POINT c1,c2,c3,c4;
	
	for(int i = 0; i < taille; i = i+delta){
		c1.x = i+delta; c1.y = i-delta;
		c2.x = i-delta; c2.y = i+delta;
		c3.x = taille- i-delta; c3.y = i-delta;
		c4.x = taille- i+delta; c4.y = i+delta;
		draw_line(c1, c2, blue);
		draw_line(c3, c4, blue);
	}
	wait_escape();
	exit(0);
}
	
	
