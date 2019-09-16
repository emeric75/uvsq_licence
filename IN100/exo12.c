#include <uvsqgraphics.h>

int main () 
{
	init_graphics(800,600);
	
	int r = 200;
	POINT c;
	
	c=wait_clic();	
	draw_circle(c,r,blue);
	
	POINT h1,h2,m1,m2,b1,b2;
	float etage = 1.73205081*r/2;
	m1.x = c.x-r; m1.y = c.y;
	m2.x = c.x+r; m2.y = c.y;
	h1.x = c.x-r/2; h1.y = c.y + ((int)etage);
	h2.x = c.x+r/2; h2.y = c.y + ((int)etage);
	b1.x = c.x-r/2; b1.y = c.y - ((int)etage);
	b2.x = c.x+r/2; b2.y = c.y - ((int)etage);
	
	draw_line(h1,h2,red);
	draw_line(h2,m2,red);
	draw_line(m2,b2,red);
	draw_line(b2,b1,red);
	draw_line(b1,m1,red);
	draw_line(m1,h1,red);
	
	wait_escape();
	exit(0);
}
	
