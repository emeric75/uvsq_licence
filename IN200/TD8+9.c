#include <uvsqgraphics.h>
#define LARGEUR 8
#define HAUTEUR 12
#define TAILLE_CASE 40

// Initialisations + fonctions de base
//
POINT aff_score = {40,560};
POINT bg = {40,40};
COULEUR B[LARGEUR][HAUTEUR];
int voisins[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int score = 0;
int temp_score = 0;
int boules_remaining = LARGEUR*HAUTEUR;

COULEUR couleur_aleatoire(){
	switch(alea_int(4)){
		case 0:
			return bleu;
		case 1: 
			return vert;
		case 2:
			return jaune;
		case 3:
			return rouge;
		default:
			return noir;
	}
}

void init_boules(){
	for(int i = 0; i < LARGEUR; i++){
		for(int j = 0; j < HAUTEUR; j++){
			B[i][j] = couleur_aleatoire();
		}
	}
}

// Affichages
//

void affiche_quadrillage(){
	POINT p1,p2; p1.y = bg.y; p2.y = bg.y + HAUTEUR*TAILLE_CASE;
	for(p1.x = bg.x; p1.x <= bg.x+LARGEUR*TAILLE_CASE; p1.x += TAILLE_CASE){
		p2.x=p1.x;
		draw_line(p1,p2,white);
	}
	p1.x = bg.x; p2.x = bg.x+LARGEUR*TAILLE_CASE;
	for(p1.y = bg.y; p1.y <= bg.y+HAUTEUR*TAILLE_CASE; p1.y += TAILLE_CASE){
		p2.y=p1.y;
		draw_line(p1,p2,white);
	}
}
void affiche_score(){
	char store_score[20];
	sprintf(store_score, "%d", score);
	aff_pol(store_score, 20, aff_score, white);
}
void affiche_boules(){
	POINT c;
	for(int i = 0; i < LARGEUR; i++){
		for(int j = 0; j < HAUTEUR; j++){
			c.x = bg.x + TAILLE_CASE*i + TAILLE_CASE/2;
			c.y = bg.y + TAILLE_CASE*j + TAILLE_CASE/2;
			draw_fill_circle(c,TAILLE_CASE/2 -1,B[i][j]);
		}
	}
}
void affiche(){
	fill_screen(black);
	affiche_quadrillage();
	affiche_boules();
	affiche_score();
}

// Gestion du jeu
//

void mettre_a_noir(int i, int j){
	COULEUR coul = B[i][j];
	B[i][j] = noir;
	temp_score += 1;
	for(int ind = 0; ind<4; ind++){
		if(i+voisins[ind][0]>-1 && i+voisins[ind][0]<LARGEUR && j+voisins[ind][1]>-1 && j+voisins[ind][1]<HAUTEUR && /*i+voisins[ind][0] != prev_i && j+voisins[ind][1] != prev_j &&*/ B[i+voisins[ind][0]][j+voisins[ind][1]] == coul){
			mettre_a_noir(i+voisins[ind][0], j+voisins[ind][1]);
		}
	}
	if(temp_score == 1){B[i][j] = coul;}
}
int gestion_clic(POINT clic){
	int i,j;
	if(clic.x >= bg.x && clic.x <= bg.x + LARGEUR*TAILLE_CASE && clic.y >= bg.y && clic.y <= bg.y + HAUTEUR*TAILLE_CASE){
		i = (clic.x - bg.x)/TAILLE_CASE;
		j = (clic.y - bg.y)/TAILLE_CASE;
		mettre_a_noir(i,j);
 		return 1; 
	}else{
		return 0;
	}
}
void descendre_colonne(int i){
	for(int j = HAUTEUR - 2; j>-1; j--){
		if(B[i][j] == noir){
			for(int k = j; k<HAUTEUR-1; k++){
				B[i][k] = B[i][k+1];
				B[i][k+1] = noir; 
			}
		}
	}
}
void ramener_ligne(int j){
	for(int i = LARGEUR - 2; i>-1; i--){
		if(B[i][j] == noir){
			for(int k = i; k<LARGEUR-1; k++){
				B[k][j] = B[k+1][j];
				B[k+1][j] = noir; 
			}
		}
	}
}
void update_board(){
	for(int i = 0; i< LARGEUR; i++){
		descendre_colonne(i);
	}
	for(int j = 0; j < HAUTEUR; j++){
		ramener_ligne(j);
	}
}

int main(){
	init_graphics(400,580);
	init_boules();
	while(boules_remaining > 0){
		affiche();
		POINT clic = {0,0};
		temp_score = 0;
		while(gestion_clic(clic) == 0) clic = wait_clic();
		score += (temp_score)*(temp_score-1);
		boules_remaining -= temp_score;
		update_board();
	}	
	affiche();
	wait_escape();
	exit(0);
}
