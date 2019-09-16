#include <uvsqgraphics.h>

void dessine_ellipse(POINT f1, POINT f2, int dist, COULEUR c){
	POINT o;
	for(int i = 0; i<600; i++){
		for(int j = 0; j<600; j++){
			o.x=i;o.y=j;
			//draw_pixel(o,bleu);
			if(fabs(distance(o,f1)+distance(o,f2) - dist) <= 1){
				draw_pixel(o,c);
			}
			
		}
	}
	
}

int main(){
	init_graphics(600,600);
	
	POINT foyer1,foyer2;
	foyer1.x = 200; foyer1.y = 300;
	foyer2.x = 400; foyer2.y = 300;
	
	draw_circle(foyer1,20,bleu);
	dessine_ellipse(foyer1,foyer2,20,orange);
	
	wait_escape();
	exit(0);
}
