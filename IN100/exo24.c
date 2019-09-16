#include <uvsqgraphics.h>

int main () {
	int taille = 200;
	init_graphics(taille,taille);
	
	POINT P1;
	P1.x=100;P1.y=100;
	
	for(int i = 10; i<=100; i=i+10){
		draw_circle(P1,i,blue);
	}
	
	wait_escape();
	exit(0);	
}
