#include <uvsqgraphics.h>

#define TAILLE 600
#define DELTA TAILLE/10
#define NOIR 0
#define BLANC 1

int plateau[12][12];
void swap_color(int i, int j){
	if(plateau[i][j] == BLANC){
		plateau[i][j] = NOIR;
	}else{
		plateau[i][j] = BLANC;
	}
}
void init_plateau(){
	for(int i=1; i<11; i++)
		for(int j=1; j<11; j++)
			plateau[i][j] = NOIR;
	int x,y;
	for(int r=0; r < alea_int(10)+1; r++){
		x = alea_int(11)+1;
		y = alea_int(11)+1;
		swap_color(x,y);
		swap_color(x+1,y);
		swap_color(x-1,y);
		swap_color(x,y+1);
		swap_color(x,y-1);
	}
}
void affiche_plateau(int c){
	POINT aff_pos;
	char aff[10];
	aff_pos.x = 625; aff_pos.y = 475;
	fill_screen(couleur_RGB(120,120,120));
	for(int i=1; i<11; i++){
		for(int j=1; j<11; j++){
			POINT c;
			c.x = DELTA*(i-1) + DELTA/2; c.y = DELTA*(j-1) + DELTA/2;
			if(plateau[i][j]==BLANC){
				draw_fill_circle(c, DELTA/2 -1, white);
			}else{
				draw_fill_circle(c, DELTA/2 -1, black);
			}
		}
	}
	sprintf(aff, "%d", c);
	aff_pol(aff, 35, aff_pos, black);
}
void modifie_plateau(){
	POINT clic = wait_clic();
	int i_m = clic.x/(DELTA) +1, j_m = clic.y/(DELTA) +1;
	swap_color(i_m,j_m);
	swap_color(i_m+1,j_m);
	swap_color(i_m-1,j_m);
	swap_color(i_m,j_m+1);
	swap_color(i_m,j_m-1);
}
int encore(){
	int compare = plateau[1][1];
	for(int i=1; i<11; i++){
		for(int j=1; j<11; j++){
			if(plateau[i][j] != compare)
				return 1;
		}
	}
	return 0;
}
int main(){
	init_graphics(TAILLE+100,TAILLE);
	
	init_plateau();
	int c = 0;
	affiche_plateau(c);
	while(c<100 && encore()){
		affiche_plateau(c);
		modifie_plateau();
		c++;
	}
	affiche_plateau(c);
	wait_escape();
	exit(0);
}
