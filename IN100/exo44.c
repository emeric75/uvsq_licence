#include <uvsqgraphics.h>

void dessine_cercle(int rayon){
	POINT center, clic;
	COULEUR coul = red;
	center = wait_clic();
	draw_fill_circle(center, rayon, coul);
	clic = wait_clic();
	while(pow(clic.x-center.x,2)+pow(clic.y-center.y,2) < pow(rayon,2)){
		if(coul == red){
			coul = blue;
		}else{
			coul = red;
		}
		draw_fill_circle(center,rayon,coul);
		clic = wait_clic();
	}
	
}

int main () {
	init_graphics(600,600);
	
	int r = 50;
	
	dessine_cercle(r);
	
	wait_escape();
	exit(0);
}
