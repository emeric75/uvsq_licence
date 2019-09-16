#include <uvsqgraphics.h>

int main () {
	init_graphics(600,400);
	POINT h1,h2;
	h1.x=100;h1.y=0;
	h2.x=100;h2.y=400;
	
	draw_line(h1,h2,red);
	
	h1.x=h1.x+100; h2.x=h2.x+100;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+100; h2.x=h2.x+100;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+100; h2.x=h2.x+100;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+100; h2.x=h2.x+100;
	draw_line(h1,h2,red);
	
	POINT v1,v2;
	v1.x=0;v1.y=100;
	v2.x=600;v2.y=100;
	
	draw_line(v1,v2,red);
	
	v1.y=v1.y+100; v2.y=v2.y+100;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+100; v2.y=v2.y+100;
	draw_line(v1,v2,red);
	
	wait_escape();
	exit(0);
	
}
