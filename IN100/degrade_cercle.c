#include <uvsqgraphics.h>

int main () {
	int taille = 512;
	init_graphics(taille,taille);
	
	POINT center;
	int f;
	center.x = 0; center.y=0;
	for(int i = 0; i <= ceil(512 * sqrt(2)); i=i+1){
		f = floor(i/(2*sqrt(2)));
		draw_circle(center,i,couleur_RGB(f,0,f));
	}
		
	wait_escape();
	exit(0);
}
