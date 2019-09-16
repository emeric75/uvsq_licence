#include <uvsqgraphics.h>

int main () {
	int taille = 512;
	init_graphics(taille,taille);
	
	POINT hg,bd;
	hg.x = 0; hg.y=2;
	bd.x = taille; hg.y=0;
	for(int i = 0; i < 256; i=i+1){
		draw_fill_rectangle(hg,bd,couleur_RGB(i,i,i));
		hg.y = bd.y += 2;
	}
		
	wait_escape();
	exit(0);
}
