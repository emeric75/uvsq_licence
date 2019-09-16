#include <uvsqgraphics.h>

void dessine_triangle(POINT p1, POINT p2, POINT p3){
	draw_line(p1,p2,bleu);
	draw_line(p2,p3,white);
	draw_line(p3,p1,red);
}

int main () {
	init_graphics(600,600);
	
	POINT Pa,Pb,Pc;
	Pa=wait_clic();
	Pb=wait_clic();
	Pc=wait_clic();
	
	dessine_triangle(Pa,Pb,Pc);
	
	
	wait_escape();
	exit(0);
}
