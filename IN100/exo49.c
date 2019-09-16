#include <uvsqgraphics.h>

int haut_ou_bas;
int gauche_droite;
int OU_CA;

void qui_dit_ou_c_est(POINT p){
	if(p.x < WIDTH/2){
		gauche_droite = 0;
	}
	if(p.x >= WIDTH/2){
		gauche_droite = 1;
	}
	if(p.y < HEIGHT/2){
		haut_ou_bas = 0;
	}
	if(p.y >= HEIGHT/2){
		haut_ou_bas = 1;
	}
}
void calcul_OU_CA(){
	OU_CA = 2*haut_ou_bas + gauche_droite;
}
void dessine_cercle(POINT centre){
	qui_dit_ou_c_est(centre);
	calcul_OU_CA();
	COULEUR coul;
	if (OU_CA == 0){
		coul =bleu;
	}
	if (OU_CA == 1){
		coul =rouge;
	}
	if (OU_CA == 2){
		coul =vert;
	}
	if (OU_CA == 3){
		coul =jaune;
	}
 	draw_circle(centre,40,coul);

}

int main(){
	init_graphics(600,600);
	
	POINT p1 = wait_clic();
	dessine_cercle(p1);
	
	wait_escape();
	exit(0);
}
