#include <uvsqgraphics.h>

int main () {
	init_graphics(400,400);
	POINT h1,h2;
	h1.x=50;h1.y=0;
	h2.x=50;h2.y=400;
	
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	h1.x=h1.x+50; h2.x=h2.x+50;
	draw_line(h1,h2,red);
	
	POINT v1,v2;
	v1.x=0;v1.y=50;
	v2.x=400;v2.y=50;
	
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	v1.y=v1.y+50; v2.y=v2.y+50;
	draw_line(v1,v2,red);
	
	wait_escape();
	exit(0);
	
}
