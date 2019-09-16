#include <uvsqgraphics.h>

void dessine_lignesH(int d, COULEUR c){
	POINT H1,H2;
	H1.y = 0;
	H2.y = HEIGHT;
	
	for(int x = 0; x <= WIDTH; x = x+d){
		H1.x = H2.x = x;
		draw_line(H1,H2,c);
	}
	
}
void dessine_lignesV(int d, COULEUR c){
	POINT H1,H2;
	H1.x = 0;
	H2.x = WIDTH;
	
	for(int y = 0; y <= WIDTH; y = y+d){
		H1.y = H2.y = y;
		draw_line(H1,H2,c);
	}
}
void dessine_quadrillage(int delta, COULEUR coul){
	dessine_lignesH(delta,coul);
	dessine_lignesV(delta,coul);
}

int main () {
	init_graphics(800,400);
	
	int delta = 100;
	COULEUR coul = blue;
	
	dessine_quadrillage(delta,coul);
	
	wait_escape();
	exit(0);
}
