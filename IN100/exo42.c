#include <uvsqgraphics.h>

void dessine_croix(POINT centre, int largeur, COULEUR c){
	POINT c1,c2,c3,c4;
	c1.x = centre.x-largeur/2; c1.y = centre.y-largeur/2;
	c2.x = centre.x+largeur/2; c2.y = centre.y+largeur/2;
	c3.x = centre.x-largeur/2; c3.y = centre.y+largeur/2;
	c4.x = centre.x+largeur/2; c4.y = centre.y-largeur/2;
	
	
	draw_line(c1,c2,c);
	draw_line(c3,c4,c);
}

int main () {
	init_graphics(600,600);
	
	POINT center = wait_clic();
	int largeur = 150;
	COULEUR c = rouge;
	dessine_croix(center,largeur,c); 
	
	
	wait_escape();
	exit(0);
}
