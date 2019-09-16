
#include "uvsqgraphics.h"
#define L 40
#define C 60

#define TERRE 0
#define ARBRE 1
#define EAU 2
#define FEU 3
#define C_TIEDE 4
#define C_ETEINT 5

#define DUREE_FEU 5
#define DUREE_CENDRE 5 

typedef struct parcelle {int etat;int temps;}PARCELLE;
int voisins[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
PARCELLE T1[L][C];
PARCELLE T2[L][C];
int count = 1;
int couleur_terrain_aleatoire()
{
	return alea_int(3);
}
void terrain_aleatoire(){
	for(int i=0; i<L;i++){
		for(int j=0; j<C;j++){
			T1[i][j].etat = couleur_terrain_aleatoire();
			T1[i][j].temps = 0;
		}
	}
}
void affiche_parcelle(int i, int j){
	COULEUR coul;
	switch(T1[i][j].etat){
		case TERRE:
		coul = marron;
		break;
		case ARBRE:
		coul = vert;
		break;
		case EAU:
		coul = bleu;
		break;
		case FEU:
		coul = rouge;
		break;
		case C_TIEDE:
		coul = gris;
		break;
		case C_ETEINT:
		coul = noir;
		break;
		default: coul = violet; break;
	}
	POINT bg = {10*i, 10*j};
	POINT hd = {10*(i+1), 10*(j+1)};
	draw_fill_rectangle(bg,hd,coul);
}
void affiche_terrain(){
	for(int i=0; i<L;i++){
		for(int j=0; j<C;j++){
			affiche_parcelle(i,j);
		}
	}
	affiche_all();
}
void modif_parcelle(int i, int j){
	int ok;
	if(T1[i][j].etat == ARBRE){
		ok = 1;
		for(int k=0;k<8;k++){
			if(i+voisins[k][0] >= 0 && i+voisins[k][0] < L && j + voisins[k][1] >= 0 && j + voisins[k][1] < C && T1[i+voisins[k][0]][j+voisins[k][1]].etat == FEU){
				T2[i][j].etat = FEU;
				T2[i][j].temps = 0;
				ok = 0;
				count++;
			}
		}
		if(ok) T2[i][j] = T1[i][j];
	}
	else if(T1[i][j].etat == FEU){
		if(T1[i][j].temps == DUREE_FEU){
			T2[i][j].temps = 0;
			T2[i][j].etat = C_TIEDE;
		}else{
		T2[i][j].temps++;
		T2[i][j].etat = FEU;
		}
		count++;
	}
	else if(T1[i][j].etat == C_TIEDE){
		if(T1[i][j].temps == DUREE_CENDRE){
			T2[i][j].temps = 0;
			T2[i][j].etat = C_ETEINT;
		}else{
		T2[i][j].temps++;
		T2[i][j].etat = C_TIEDE;
		}
		count++;
	}else{
		T2[i][j] = T1[i][j];
	}
}
void modif_terrain(){
	for(int i=0; i<L;i++){
		for(int j=0; j<C;j++){
			modif_parcelle(i,j);
		}
	}
}
int continuer(){
	return (count!=0); 
}
void launch_fire(){
	POINT p = wait_clic();
	T1[p.x/10][p.y/10].etat = FEU; 
	T1[p.x/10][p.y/10].temps = 0;
}
int main(){
	init_graphics(400,600);
	affiche_auto_off();
	terrain_aleatoire();
	affiche_terrain();
	launch_fire();
	affiche_terrain();
	while(continuer()){
		count = 0;
		modif_terrain();
		attendre(300);
		for(int i=0; i<L;i++){
			for(int j=0; j<C;j++){
			T1[i][j] = T2[i][j];
			}
		}	
		affiche_terrain();
	}
	wait_escape();
	return EXIT_SUCCESS;
}
