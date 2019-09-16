#include <uvsqgraphics.h>

int main () 
{
	init_graphics(1000,800);
	
	POINT h1,h2,m1,m2,b1,b2;
	int r;
	r=100;
	float etage = 1.73205081*r/2;
	float etage2 = 2*etage;

	h1.x=600; h1.y=600;
	h2.x=h1.x+r; h2.y=600;
	m1.x=h1.x-r/2; m1.y= h1.y-((int)etage);
	m2.x=h2.x+r/2; m2.y=h2.y-((int)etage);
	b1.x=h1.x; b1.y=h1.y-((int)etage2);
	b2.x=h2.x; b2.y=h2.y-((int)etage2);
	
	draw_line(h1,h2,blue);
	draw_line(h2,m2,blue);
	draw_line(m2,b2,blue);
	draw_line(b2,b1,blue);
	draw_line(b1,m1,blue);
	draw_line(m1,h1,blue);
	
	POINT c;
	c.x=m1.x+r;c.y=m1.y;
	
	draw_circle(c,r,blue);
	
	wait_escape();
	exit(0);	
}
