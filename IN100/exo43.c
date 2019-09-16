#include <uvsqgraphics.h>

void dessine_mickey(POINT centre, int rayon, COULEUR c){
	POINT c2,c3;
	
	c2.x = centre.x-3*rayon/(2*sqrt(2));c2.y = centre.y+3*rayon/(2*sqrt(2));
	c3.x = centre.x+3*rayon/(2*sqrt(2));c3.y = centre.y+3*rayon/(2*sqrt(2));
	
	draw_circle(centre,rayon,c);
	draw_circle(c2,rayon/2,c);
	draw_circle(c3,rayon/2,c);
}

int main () {
	init_graphics(600,600);
		POINT center;
		center.x = alea_int(600);
		center.y = alea_int(600);
		int r = 100;
		COULEUR c = rand();
		dessine_mickey(center,r,c);
	
	wait_escape();
	exit(0);
}
