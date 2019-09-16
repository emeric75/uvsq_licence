#include <uvsqgraphics.h>
#define TAILLE 600
int main () {
	init_graphics(TAILLE, TAILLE);
	
	POINT pts[20];
	int rayons[20];
	for(int i = 0; i<20; i++){
		pts[i].x = alea_int(TAILLE);
		pts[i].y = alea_int(TAILLE);
		rayons[i] = 50;
		draw_circle(pts[i], 50, orange);
	}
	POINT clic;
	for(int i=0; i<20; i++){
		clic = wait_clic();
		fill_screen(black);
		for(int ind=0; ind<20; ind++){
			if(rayons[ind]>0){
				if(distance(pts[ind],clic)<rayons[ind]){
					rayons[ind] += 5;
				}else{
					rayons[ind] -= 5;
				}
				draw_circle(pts[ind], rayons[ind], orange);
			}
		}
	}
	wait_escape();
}
