#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>
#define NB_MINES 40
#define BGX 20
#define BGY 20
#define DELTA 20
#define MINE 1
#define OK 0
#define NDEC 0
#define DEC 1
#define NFLAG 2
#define FLAG 3
int T[20][20];
int state[20][20];
int flag[20][20];

void init_plateau(){
	for(int i = 0; i<20; i++){
		for(int j=0; j<20; j++){
			if(alea_float() < NB_MINES/400.0f){
				T[i][j] = MINE;
			}else{
				T[i][j] = OK;
			}
			state[i][j] = NDEC;
			flag[i][j] = NFLAG;
		}
	}
}
void draw_quadrillage(){
	POINT left,right;
	left.x=BGX; right.x = BGX+20*DELTA;
	for(int j = 0; j<20; j++){
		left.y = right.y = BGY + DELTA*j; 
		draw_line(left,right,blue);
	}
	POINT up,down;
	down.y=BGY; up.y = BGY+20*DELTA;
	for(int i=0; i<20; i++){
		up.x = down.x = BGX + DELTA*i; 
		draw_line(up,down,blue);
	}
}
int get_voisins(int i, int j){
	int diff[3] = {-1,0,1}, count_mines = 0;
	for(int idx=0; idx<3; idx++){
		for(int idy=0; idy<3; idy++){
			if(T[i+diff[idx]][j+diff[idy]] == MINE){
				count_mines += 1;
			}
		}
	}
	
}
void draw_voisins(int i, int j){
	int diff[3] = {-1,0,1}, count_mines = 0;
	for(int idx=0; idx<3; idx++){
		for(int idy=0; idy<3; idy++){
			if(T[i+diff[idx]][j+diff[idy]] == MINE){
				count_mines += 1;
			}
		}
	}
	POINT centre; 
	centre.x = BGX + DELTA*i+DELTA/2; centre.y = BGY + DELTA*j+DELTA/2; 
	char to_aff[2];
	sprintf(to_aff,"%d",count_mines);
	aff_pol_centre(to_aff, 15, centre, black);
}
void draw_flag(int i, int j){
	POINT bg, hd;
	bg.x = BGX + DELTA*i; bg.y = BGY + DELTA*j;
	hd.x = BGX + DELTA*i+DELTA; hd.y = BGY + DELTA*j+DELTA; 
	draw_line(bg,hd,red);
}
void affichage(){
	POINT bg,hd;
	for(int i = 0; i<20; i++){
		for(int j=0; j<20; j++){
			bg.x = BGX + DELTA*i; bg.y = BGY + DELTA*j;
			hd.x = bg.x + DELTA; hd.y = bg.y + DELTA;
			if(state[i][j] == NDEC){
				draw_fill_rectangle(bg,hd,couleur_RGB(200,200,200));
				if(flag[i][j] == FLAG) draw_flag(i,j);
			}else if(state[i][j] == DEC){
				if(T[i][j] == OK){
					draw_fill_rectangle(bg,hd,couleur_RGB(100,100,100));
					draw_voisins(i,j);
				}else{
					draw_fill_rectangle(bg,hd,couleur_RGB(200,0,0));
				}
			}
		}
	}
	draw_quadrillage();
}
POINT quelle_case(POINT clic){
	POINT out;
	out.x = (clic.x-BGX)/DELTA; out.y = (clic.y-BGY)/DELTA;
	return out;
}

void switch_flag(POINT coord){
	if(flag[coord.x][coord.y] == NFLAG){
		flag[coord.x][coord.y] = FLAG;
	}else{
		flag[coord.x][coord.y] = NFLAG;
	}
}

void discover(POINT coord){
	if(state[coord.x][coord.y] == NDEC){
		state[coord.x][coord.y] = DEC;
		/*if(get_voisins(coord.x,coord.y) == 0){
		int diff[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
		for(int id=0; id<4; id++){
			if(T[coord.x+diff[id][0]][coord.y+diff[id][1]]==OK){
				POINT n_disc;
				n_disc.x = coord.x+diff[id][0]; n_disc.y = coord.y+diff[id][1];
				discover(n_disc);
			}
		}
	}*/
	}
}
int check_vivant(POINT coord){
	if(T[coord.x][coord.y] == MINE){
		return 0;
	}else{
		return 1;
	}
}

int main(){
	init_graphics(440,440);
	init_plateau();
	int vivant = 1;
	POINT clic;
	while(vivant){
		affichage();
		char c;
		POINT caseclic;
		clic = wait_clic_GMD(&c);
		caseclic = quelle_case(clic);
		if(c == 'G'){
			vivant = check_vivant(caseclic);
			discover(caseclic);
		}else if(c == 'D'){
			switch_flag(caseclic);
		}
	}
	affichage();
	wait_escape();
}
