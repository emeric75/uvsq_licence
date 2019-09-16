#include <uvsqgraphics.h>

int main () {
	int taille = 200;
	init_graphics(taille,taille);
	
	POINT P = get_mouse();
	POINT r1,r2,r3;
	
	COULEUR colors[16]={argent,blanc,bleu,bleumarine,citronvert,cyan,magenta,gris,jaune,marron,noir,rouge,sarcelle,vertclair,vertolive,violet};
	
	r1.x=0; r1.y=0;
	r2.x=100; r2.y=200;
	r3.x=200; r3.y=0;
	while(1){
		P = get_mouse();
		attendre(30);
		if(P.x<100){
			fill_screen(black);
			draw_fill_rectangle(r1,r2,colors[alea_int(16)]);
		}else{
			fill_screen(black);
			draw_fill_rectangle(r2,r3,colors[alea_int(16)]);
		}
	}
	wait_escape();
	exit(0);
}
