#include "uvsqgraphics.h"

void mon_draw_triangle(POINT P1, POINT P2, POINT P3, COULEUR C){
	draw_line(P1,P2,C);
	draw_line(P2,P3,C);
	draw_line(P3,P1,C);
}

void mon_draw_triangle_from_clic(COULEUR C){
	POINT P1,P2,P3;
	P1 = wait_clic();
	P2 = wait_clic();
	P3 = wait_clic();
	
	mon_draw_triangle(P1,P2,P3,C);
}

int main(){
	init_graphics(600,600);
	POINT P1,P2,P3;
	for(int i = 0; i<10; i++){
		P1 = wait_clic();
		P2 = wait_clic();
		P3 = wait_clic();
		mon_draw_triangle(P1,P2,P3,rouge);
	}
	for(int i = 0; i<10; i++){
		mon_draw_triangle_from_clic(bleu);
	}
	wait_escape();
	exit(0);
}
