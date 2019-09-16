#include <uvsqgraphics.h>

int main () {
	int taille = 200;
	init_graphics(taille,taille);
	
	
	POINT P1,P2,wait;
	P1.x=50;P1.y=50;
	P2.x=150;P2.y=150;
	draw_rectangle(P1,P2,blue);
	wait = wait_clic();
	int i = 0;
	while(wait.x >= 50 && wait.x <= 150 && wait.y >=50 && wait.y <= 150){
		if(i%2==0){
			draw_fill_rectangle(P1,P2,blue);
		}else{
			fill_screen(black);
			draw_rectangle(P1,P2,blue);
		}
		wait = wait_clic();
		i=i+1;
	}
	
	wait_escape();
	exit(0);	
}
