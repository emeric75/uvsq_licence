#include <uvsqgraphics.h>
#define TAILLE 600
int main () {
	init_graphics(TAILLE, TAILLE);
	
	POINT pts[20], centre;
	centre.x = centre.y = TAILLE/2;
	int ind_maxdist = 0;
	for(int i = 0; i<20; i++){
		pts[i].x = alea_int(TAILLE);
		pts[i].y = alea_int(TAILLE);
		draw_circle(pts[i], 20, orange);
		if(distance(centre, pts[i])>distance(centre, pts[ind_maxdist])){
			ind_maxdist = i;
		}
	}
	
	POINT clic;
	for(int i = 0; i<20; i++){
		clic = wait_clic();
		if(distance(centre,clic)< distance(centre, pts[ind_maxdist])){
			draw_circle(pts[ind_maxdist],20,black); 
			draw_circle(clic, 20, orange);
			pts[ind_maxdist] = clic;
			for(int j = 0; j<20; j++){
				if(distance(centre, pts[j])>distance(centre, pts[ind_maxdist])){
					ind_maxdist = j;
				}
			}
		}
	}
	wait_escape();
}
