#include <uvsqgraphics.h>
//initialisations
typedef struct balle{POINT centre; int dx,dy,rayon; COULEUR couleur;} BALLE;
int count = 0;

BALLE init_balle(){
	BALLE b;
	b.centre.x = 100;
	b.centre.y = 200;
	b.dx = 1;
	b.dy = 3;
	b.rayon = 20;
	b.couleur = blanc;
	return b;
}
//deplacement
BALLE deplace_balle(BALLE b){
	b.centre.x += b.dx;
	b.centre.y += b.dy; 
	return b;
}
BALLE detect_collision(BALLE b){
	if(b.centre.x + b.rayon > WIDTH-2){
		b.dx = -b.dx;
		b.couleur = vert;
		count++;
	}
	if(b.centre.x - b.rayon < 0){
		b.dx = -b.dx;
		b.couleur = jaune;
		count++;
	}
	if(b.centre.y + b.rayon >  HEIGHT-2){
		b.dy = -b.dy;
		b.couleur = rouge;
		count++;
	}
	if(b.centre.y - b.rayon < 0){
		b.dy = -b.dy;
		b.couleur = bleu;
		count++;
	}
	return b;
}
//affichage
void affiche_balle(BALLE b){
	draw_fill_circle(b.centre,b.rayon,b.couleur);
}
void init_ecran(){
	POINT H_hd, H_bg, B_hd, B_bg, G_hd, G_bg,D_hd,D_bg;
	H_hd.x = 0; H_hd.y = HEIGHT;
	H_bg.x = WIDTH; H_bg.y = HEIGHT-2;
	B_hd.x = 0; B_hd.y = 2;
	B_bg.x = WIDTH; B_bg.y = 0;
	G_hd.x = 0; G_hd.y = HEIGHT;
	G_bg.x = 2; G_bg.y = 0;
	D_hd.x = WIDTH-2; D_hd.y = HEIGHT;
	D_bg.x = WIDTH; D_bg.y = 0;
	draw_fill_rectangle(H_hd,H_bg,rouge);
	draw_fill_rectangle(B_hd,B_bg,bleu);
	draw_fill_rectangle(G_hd,G_bg,jaune);
	draw_fill_rectangle(D_hd,D_bg,vert);
}
int main(){
	init_graphics(600,600);
	affiche_auto_off();
	BALLE b = init_balle();
	while(count < 30){
		init_ecran();
		affiche_balle(b);
		affiche_all();
		b=deplace_balle(b);
		b=detect_collision(b);
		fill_screen(black);
	}
	wait_escape();
	exit(EXIT_SUCCESS);
}
