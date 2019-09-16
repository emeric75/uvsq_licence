#include <uvsqgraphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
#define ROTATE 1
#define CHANGE 2

POINT rot(POINT p, float angle, POINT or){
	float tx,ty;
	p.x = p.x-or.x;
	p.y = p.y-or.y;
	tx = cosf(angle)*p.x - sinf(angle)*p.y;
	ty = sinf(angle)*p.x + cosf(angle)*p.y;
	p.x = tx;
	p.y = ty;
	p.x = p.x + or.x;
	p.y = p.y + or.y;
	return p;
}
int main(){
	init_graphics(600,600);
	
	int key;
	int mode = ROTATE;
	
	POINT p1,p2,p3,p4,arrow;
	p1.x = 150; p1.y = 150;
	p2.x = 150; p2.y = 450;
	p3.x = 450; p3.y = 450;
	p4.x = 450; p4.y = 150;
	
	POINT or,or1,or2,or3,or4;
	or.x = 300;
	or.y = 300;
	
	
	printf("1:%d,%d\n", p1.x, p1.y);
	printf("2:%d,%d\n", p2.x, p2.y);
	printf("3:%d,%d\n", p3.x, p3.y);
	printf("4:%d,%d\n", p4.x, p4.y);
	printf("\n");
	while(1){
		or1.x = or.x + 10; or1.y = or.y;
		or2.x = or.x - 10; or2.y = or.y;
		or3.x = or.x; or3.y = or.y + 10;
		or4.x = or.x; or4.y = or.y - 10;
		key = get_key();
		if (key==113){
			fill_screen(black);
			if(mode == ROTATE){
				p1=rot(p1,-M_PI/16,or);
				p2=rot(p2,-M_PI/16,or);
				p3=rot(p3,-M_PI/16,or);
				p4=rot(p4,-M_PI/16,or);
			}else{
				or.x += 1;
			}
		}
		if (key==100){
			fill_screen(black);
			if(mode == ROTATE){
				p1=rot(p1,M_PI/16,or);
				p2=rot(p2,M_PI/16,or);
				p3=rot(p3,M_PI/16,or);
				p4=rot(p4,M_PI/16,or);
			}else{
				or.x -= 1;
			}
		}
		if(key==122){
			or.y += 1;
		}
		if(key==115){
			or.y -= 1;
		}
		draw_line(p1,p2,blue);
		draw_line(p2,p3,blue);
		draw_line(p3,p4,blue);
		draw_line(p4,p1,blue);
		draw_line(or1,or2,red);
		draw_line(or3,or4,red);
	}
	
	
	wait_escape();
	exit(0);
}
	
