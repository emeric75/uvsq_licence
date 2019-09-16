#include "uvsqgraphics.h"

COULEUR T1[256];
COULEUR T2[512][512];
void remplir_gris(){
	for(int i = 0; i<256; i++){
		T1[i] = couleur_RGB(i,i,i);
	}
}

void remplir_rouge(){
	for(int i = 0; i<256; i++){
		T1[i] = couleur_RGB(i,0,0);
	}
}
void remplir_rouge_bleu(){
	for(int i = 0; i<256; i++){
		for(int j = 0; j<256; j++){
			T2[i][j] = couleur_RGB(i,0,j);
		}
	}
}
COULEUR remplir_case_alea(){
	return couleur_RGB(alea_int(256), alea_int(256), alea_int(256));
}
void remplir_aleatoire(){
	for(int i = 0; i<256; i++){
		for(int j = 0; j<256; j++){
			T2[i][j] = remplir_case_alea();
		}
	}
}
void afficher_horizontal(){
	POINT bg,hd;
	bg.x = 0; bg.y = 0;
	hd.x = 2; hd.y = HEIGHT; 
	for(int i = 0; i<256; i++){
		draw_rectangle(bg,hd,T1[i]);
		bg.x += 2;
		hd.x += 2;
	}
}
void afficher_vertical(){
	POINT bg,hd;
	bg.x = 0; bg.y = 0;
	hd.x = WIDTH; hd.y = 2; 
	for(int i = 0; i<256; i++){
		draw_rectangle(bg,hd,T1[i]);
		bg.y += 2;
		hd.y += 2;
	}
}
void afficher_2D(){
	POINT bg,hd;
	bg.x = 0; bg.y = 0;
	hd.x = 2; hd.y = 2; 
	for(int i = 0; i<256; i++){
		for(int j = 0 ; j<256; j++){
			draw_rectangle(bg,hd,T2[i][j]);
			bg.x += 2;
			hd.x += 2;
		}
		bg.x = 0; hd.x = 2;
		bg.y += 2; hd.y += 2;
	}
}
int main(){
	init_graphics(512,512);
	remplir_aleatoire();
	afficher_2D();
	wait_escape();
	exit(0);
}
