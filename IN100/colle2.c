#include <uvsqgraphics.h>

int main(){
	init_graphics(600,400);
	
	//initialisation ligne verticale
	POINT haut,bas;
	haut.x = WIDTH/2; haut.y = HEIGHT;
	bas.x = WIDTH/2; bas.y = 0;
	
	draw_line(haut,bas,white);
	
	//initialisation des cercles
	POINT pts[10], clic;
	int r = 50;
	for(int i = 0; i<10; i++){
		pts[i] = wait_clic();
		draw_fill_circle(pts[i], r, blue);
	}
	
	for(int i = 0; i<10; i++){
		clic = wait_clic();
		//vérification de la position du clic + chgt rayon
		if(clic.x < WIDTH/2){
			r += 10;
		}else{
			r -= 10;
		}
		//on efface l'écran, puis on redessine les cercles avec le nouveau rayon
		fill_screen(black);
		for(int j = 0; j<10; j++){
			draw_fill_circle(pts[j], r, blue);
		}	
		draw_line(haut,bas,white);
	}
	
	
	wait_escape();
	exit(0);
}
