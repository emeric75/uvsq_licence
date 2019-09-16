#include "uvsqgraphics.h"
#include <math.h>
// Définition des différentes formes

#define WIDTH 600
#define HEIGHT 600

#define VIDE 0 
#define CERCLE 100 
#define CARRE 101 
#define CROIX 102
#define CERCLE_SPE 105
#define HAUT 0
#define DROITE 1
#define BAS 2
#define GAUCHE 3

#define SIZE_X 40
#define SIZE_Y 40

#define NBR_X WIDTH/SIZE_X
#define NBR_Y HEIGHT/SIZE_Y
// Définition des types
struct elem { 
	int i,j; // position sur le quadrillage de l’élément 
	int forme; // vaut VIDE, CERCLE, CARRE ou CROIX 
	COULEUR coul; // vaut bleu, rouge, jaune ou vert 
};
struct serpent { 
	int longueur; // nombre d’éléments dans le corps du serpent 
	struct elem A[200]; // les éléments constitutifs du serpent 
	int dirx,diry;
};

// Fonctions à écrire
int min(int a, int b){
	return (a>=b) ? b:a;
}
void init_jeu(struct elem J[SIZE_X][SIZE_Y]) {
	int a;
	for(int i = 0; i<SIZE_X; i++){
		for(int j = 0; j<SIZE_Y; j++){
			a = alea_int(200);
			if(a<195){
				J[i][j].forme = VIDE;
			}else if(a<197){
				J[i][j].forme = CERCLE;
			}else if(a<199){
				J[i][j].forme = CARRE;
			}else{
				J[i][j].forme = CROIX;
			}
		}
	}
}
struct serpent init_serpent() { 
	struct serpent S;
	S.longueur = 1;
	S.A[0].i = alea_int(SIZE_X/2)+SIZE_X/4;
	S.A[0].j = alea_int(SIZE_Y/2)+SIZE_Y/4;
	S.dirx = 0;
	S.diry = pow(-1,alea_int(2));
	S.A[0].forme = CERCLE_SPE;
	return S; 
}
void dessine_quadrillage(){
	POINT p1, p2;
	p1.y = 0; p2.y = HEIGHT;
	for(p1.x = 0; p1.x <= WIDTH; p1.x+=NBR_X){
		p2.x=p1.x;
		draw_line(p1,p2,white);
	}
	p1.x = 0; p2.x = WIDTH;
	for(p1.y = 0; p1.y <= HEIGHT; p1.y+=NBR_Y){
		p2.y=p1.y;
		draw_line(p1,p2,white);
	}
}
void affiche_jeu(struct elem J[SIZE_X][SIZE_Y], int score) {
	POINT bg, centre, hd,hg,bd,coord;
	for(int i = 0; i<SIZE_X; i++){
		for(int j = 0; j<SIZE_Y; j++){
			bg.x = NBR_X*i+1; bg.y = NBR_Y*j+1;
			centre.x = NBR_X*i+NBR_X/2; centre.y = NBR_Y*j+NBR_Y/2;
			hd.x = NBR_X*(i+1)-1; hd.y = NBR_Y*(j+1)-1;
			hg.x = NBR_X*i+1; hg.y = NBR_Y*(j+1)-1;
			bd.x = NBR_X*(i+1)-1; bd.y = NBR_Y*j+1;
			switch(J[i][j].forme){
				/*case VIDE: 
					draw_fill_rectangle(bg,hd,black);
					break;*/
				case CERCLE: 
					draw_fill_circle(centre, min(NBR_X/2,NBR_Y/2), red);
					break;
				case CARRE: 
					draw_fill_rectangle(bg,hd,blue);
					break;
				case CROIX: 
					draw_line(bg,hd,orange);
					draw_line(hg,bd,orange);
					break;
				default: break;
			}
		}
	}
	coord.x = WIDTH/2; coord.y = HEIGHT/2;
	char to_aff[6];
	sprintf(to_aff, "%d", score);
	aff_pol_centre(to_aff,WIDTH/2,coord,white);
}

void affiche_serpent(struct serpent S) {
	POINT bg,centre,hd,hg,bd;
	int t=0;
	int i,j;
	for(t = 0; t < S.longueur; t++){
		i = S.A[t].i;
		j = S.A[t].j;
		bg.x = NBR_X*i+1; bg.y = NBR_Y*j+1;
		centre.x = NBR_X*i+NBR_X/2; centre.y = NBR_Y*j+NBR_Y/2;
		hd.x = NBR_X*(i+1)-1; hd.y = NBR_Y*(j+1)-1;
		hg.x = NBR_X*i+1; hg.y = NBR_Y*(j+1)-1;
		bd.x = NBR_X*(i+1)-1; bd.y = NBR_Y*j+1;
		switch(S.A[t].forme){
				/*case VIDE: 
					draw_fill_rectangle(bg,hd,black);
					break;*/
				case CERCLE: 
					draw_fill_circle(centre, min(NBR_X/2,NBR_Y/2), red);
					break;
				case CARRE: 
					draw_fill_rectangle(bg,hd,blue);
					break;
				case CROIX: 
					draw_line(bg,hd,orange);
					draw_line(hg,bd,orange);
					break;
				case CERCLE_SPE:
					draw_fill_circle(centre, min(NBR_X/2,NBR_Y/2), white);
					break;
				default: break;
			}
	}
}
struct serpent change_dir(struct serpent S, POINT p){
	if(p.x > 0){
		//S.dir = DROITE;
		S.dirx = 1;
		S.diry = 0;
	}
	if(p.x < 0){
		//S.dir = GAUCHE;
		S.dirx = -1;
		S.diry = 0;
	}
	if(p.y > 0){
		//S.dir = HAUT;
		S.dirx = 0;
		S.diry = 1;
	}
	if(p.y < 0){
		//S.dir = BAS;
		S.dirx = 0;
		S.diry = -1;
	}
	return S;
}
struct serpent deplace_serpent(struct serpent S){
	for(int t = 0; t< S.longueur-1; t++){
		S.A[t].i = S.A[t+1].i;
		S.A[t].j = S.A[t+1].j;
	}
	//if(S.longueur > 1) S.A[0] = S.A[1]; 
	if(S.diry == 1)  {S.A[S.longueur-1].j++;}
	if(S.dirx == 1)  {S.A[S.longueur-1].i++;}
	if(S.diry == -1) {S.A[S.longueur-1].j--;}
	if(S.dirx == -1) {S.A[S.longueur-1].i--;}
	
	return S;
}
int detect_mange(struct serpent *S, struct elem J[SIZE_X][SIZE_Y]){
	if(S->longueur < 200 && J[S->A[S->longueur-1].i + S->dirx][S->A[S->longueur-1].j + S->diry].forme != VIDE){
		S->A[S->longueur].i = S->A[S->longueur-1].i /*+ S.dirx*/;
		S->A[S->longueur].j = S->A[S->longueur-1].j /*+ S.diry*/;
		S->A[S->longueur].forme = J[S->A[S->longueur-1].i+ S->dirx][S->A[S->longueur-1].j+ S->diry].forme;
		J[S->A[S->longueur-1].i+ S->dirx][S->A[S->longueur-1].j+ S->diry].forme = VIDE;
		S->longueur += 1;
		return 1;
	}
	return 0;
}
int game_ok(struct serpent S, struct elem J[SIZE_X][SIZE_Y]){
	if(S.A[S.longueur-1].i > SIZE_X-1 || S.A[S.longueur-1].i < 0 || S.A[S.longueur-1].j > SIZE_Y-1 || S.A[S.longueur-1].j < 0){
		return 0;
	}
	return 1;
}
int main() {
	struct elem J[SIZE_X][SIZE_Y]; 
	struct serpent S;
	init_graphics(WIDTH,HEIGHT);
	affiche_auto_off(); 
	dessine_quadrillage();
	POINT p;
	init_jeu(J); 
	S = init_serpent(); 
	int score = 0;
	while(game_ok(S,J)){
		dessine_quadrillage();
		affiche_serpent(S);
		affiche_jeu(J,score); 
		affiche_all();
		fill_screen(black);
		p = get_arrow();
		if(p.x != 0 || p.y != 0){
			S = change_dir(S,p);
		}
		if(detect_mange(&S,J)) score += 1;
		S = deplace_serpent(S);
		attendre(60);
	}
	
	wait_escape(); 
	exit(0);
}
