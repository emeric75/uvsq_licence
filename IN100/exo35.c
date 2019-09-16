#include <uvsqgraphics.h>
#include <math.h>

int main () {
	int taille = 512;
	init_graphics(taille,taille);
	
	POINT bg,hd;
	bg.x = 0; bg.y=0;
	hd.x = 2; hd.y=2;
	
	for(int i = 0; i < 256; i=i+1){
		for(int j = 0; j< 256; j=j+1){
		draw_fill_rectangle(bg,hd,couleur_RGB(i,j,pow(i+j,2)));
		bg.y = hd.y += 2;
		}
	bg.x = hd.x += 2;
	bg.y = hd.y =0;
	}
		
	wait_escape();
	exit(0);
}
