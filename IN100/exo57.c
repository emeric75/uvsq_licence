#include <uvsqgraphics.h>

int taille = 600; 

void fill_white(int i, int j){
	int d=taille/8;
	POINT bg, hd;
	bg.x = d*i; bg.y = d*j;
	hd.x = bg.x+d; hd.y = bg.y+d;
	if(i%2==j%2){
		draw_fill_rectangle(bg,hd,white);
	}	
}

POINT update(POINT c, POINT a_c){
	int d=taille/8;
	POINT pion, a_pion;
	a_pion.x = d*a_c.x + d/2, a_pion.y = d*a_c.y + d/2;
	pion.x = d*c.x + d/2, pion.y = d*c.y + d/2;
	draw_fill_circle(a_pion, d/2-1,black);
	fill_white(a_c.x,a_c.y);
	draw_fill_circle(pion, d/2-1, red);
	return c;
}

int main(){
	init_graphics(taille,taille);
	int d=taille/8;
	
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			fill_white(i,j);
		}
	}
	POINT coords, a_coords;
	coords.x = 0; coords.y = 0;
	a_coords.x = 0; a_coords.y = 0; 
	POINT clic, pion;
	pion.x = d*coords.x + d/2; pion.y = d*coords.y + d/2;
	draw_fill_circle(pion, d/2-1, red);
	
	clic = wait_clic();
	coords.x = (clic.x)/d; coords.y = (clic.y)/d ;
	
	//tour
	/*while(coord_x == a_cx || coord_y == a_cy){
		update(coord_x,coord_y,a_cx,a_cy);
		clic = wait_clic();
		coord_x = (clic.x)/d; coord_y = (clic.y)/d;
	}*/
	
	//reine
	while(coords.x == a_coords.x || coords.y == a_coords.y || coords.x- a_coords.x == coords.y - a_coords.y || coords.x - a_coords.x == -(coords.y- a_coords.y)){
		a_coords = update(coords,a_coords);
		clic = wait_clic();
		coords.x = (clic.x)/d; coords.y = (clic.y)/d;
	}
	
	//cavalier
	/*while((abs(coord_x - a_cx) == 2 && abs(coord_y - a_cy) == 1) || (abs(coord_x - a_cx) == 1 && abs(coord_y - a_cy) == 2)){
		update(coord_x,coord_y,a_cx,a_cy);
		clic = wait_clic();
		coord_x = (clic.x)/d; coord_y = (clic.y)/d;
	}*/
	
	wait_escape();
}
