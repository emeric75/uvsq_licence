#include <uvsqgraphics.h>

int main () {
	int taille = 200;
	init_graphics(taille,taille);
	
	POINT P1,P2,wait;
	P1.x=50;P1.y=50;
	P2.x=150;P2.y=150;
	draw_rectangle(P1,P2,blue);
	
	for(int i = 0; i<10; i=i+1){
		wait = wait_clic();
		if(i%2==0){
			draw_fill_rectangle(P1,P2,blue);
		}else{
			fill_screen(black);
			draw_rectangle(P1,P2,blue);
		}
	}
	
	wait_escape();
	exit(0);	
}
