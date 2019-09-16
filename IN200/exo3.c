#include "uvsqgraphics.h"
POINT init_balle(int x, int y){
	POINT p; p.x = x; p.y = y;
	return p;
}
void efface_affiche(POINT ancien, POINT nouveau, int r, COULEUR c){
	//draw_fill_circle(ancien, r, black);
	draw_fill_circle(nouveau, r, c);
}
POINT deplace_balle(POINT a, int dx, int dy){
	a.x += dx;
	a.y += dy;
	return a;
}
int dehors_x(POINT p, int r){
	if( 0 > p.x - r || p.x+r > 600){
		return 1;
	}
	return 0;
}
int dehors_y(POINT p, int r){
	if( 0 > p.y - r || p.y+r > 600){
		return 1;
	}
	return 0;
}
int main(){
	init_graphics(600,600);
	affiche_auto_off();
	
	COULEUR c = alea_int(256);
	POINT a,n;
	n = init_balle(50,50);
	int r = 50;
	int dx = 6; int dy = 3;
	
	while(1){
		a = n;
		n = deplace_balle(n,dx,dy);
		efface_affiche(a,n,r,c);
		if(dehors_x(n,r))  {dx = -dx; c = couleur_RGB(alea_int(255),alea_int(255),alea_int(255));}
		if(dehors_y(n,r))  {dy = -dy; c = couleur_RGB(alea_int(255),alea_int(255),alea_int(255));}
		affiche_all();
		attendre(5);
	}
	
	wait_escape();
	exit(0);
}
