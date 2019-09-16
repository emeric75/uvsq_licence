#include <uvsqgraphics.h>
#include <math.h>

#define NB_BALLES 250
typedef struct balle{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
}BALLE;
typedef struct raquette{
	POINT bg;
	int width,height;
}RQT;
BALLE init_balle(){
	BALLE b;
	b.centre.x = alea_int(WIDTH-200)+100;
	b.centre.y = alea_int(HEIGHT-200)+100;
	b.coul = couleur_RGB(alea_int(256),alea_int(256),alea_int(256));
	b.dx = pow(-1,alea_int(2))*(alea_int(5)+1);
	b.dy = pow(-1,alea_int(2))*(alea_int(5)+1);
	b.rayon = alea_int(26)+5;
	return b;
}

BALLE deplace_balle(BALLE b){
	b.centre.x += b.dx;
	b.centre.y += b.dy;
	return b;
}
void efface_balle(BALLE b){
	draw_fill_circle(b.centre,b.rayon,black);
}
void affiche_balle(BALLE b){
	draw_fill_circle(b.centre,b.rayon,b.coul);
}
BALLE rebond_balle(BALLE b){
	if(b.centre.x-b.rayon<0 || b.centre.x+b.rayon > WIDTH || (b.centre.x < WIDTH/2 && b.centre.x + b.rayon > WIDTH/2) ||(b.centre.x > WIDTH/2 && b.centre.x + b.rayon < WIDTH/2) ){
		b.dx = -b.dx;
	}
	if(b.centre.y-b.rayon<0 || b.centre.y+b.rayon > HEIGHT){
		b.dy = -b.dy;
	}
	return b;
}
int main(){
	init_graphics(400,400);
	affiche_auto_off();
	BALLE bs[NB_BALLES];
	for(int i = 0; i<NB_BALLES; i++){
		bs[i] = init_balle();
	}
	while(1){
		for(int i = 0; i<NB_BALLES; i++){
			efface_balle(bs[i]);
			bs[i] = rebond_balle(bs[i]);
			bs[i] = deplace_balle(bs[i]);
			affiche_balle(bs[i]);
		}
		affiche_all();
		attendre(10);
	}
	wait_escape();
	exit(0);
}
