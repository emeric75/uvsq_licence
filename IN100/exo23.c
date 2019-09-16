#include <uvsqgraphics.h>

int main () {
	int width,height,delta;
	width = 800;
	height = 600;
	delta = 40;
	init_graphics(width,height);
	while(1){
		POINT P1,P2;
		P1.x=0;P1.y=0;
		P2.x=0;P2.y=height;
		POINT t1,t2;
		while(P1.x<=width){
			for(int i = 0; i < alea_int(8)+1; i=i+1){
				t1.x = P1.x+i; t1.y=0;
				t2.x = P1.x+i; t2.y=HEIGHT;
				draw_line(t1,t2,rand());
			}
			P1.x=P1.x+delta;P2.x=P2.x+delta;
		}
		
		P1.x=0;P1.y=0;
		P2.x=width;P2.y=0;
		
		while(P1.y<=height){
			for(int i = 0; i < alea_int(8)+1; i=i+1){
				t1.x = 0; t1.y=P1.y+i;
				t2.x = WIDTH; t2.y=P1.y+i;
				draw_line(t1,t2,rand());
			}
			P1.y=P1.y+delta;P2.y=P2.y+delta;
		}
	}
	wait_escape();
	exit(0);	
}
