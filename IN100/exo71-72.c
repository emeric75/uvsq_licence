#include <uvsqgraphics.h>
int T[20];
void init(){
	for(int i =0; i < 20; i++){
		T[i] = alea_int(100);
	}
}
void affiche(){
	POINT bg,hd;
	bg.x = 100;bg.y = 50;
	hd.x = 100+19; hd.y = 50 + 3 * T[0];
	draw_rectangle(bg,hd,red);
	for(int i=1; i<20; i=i+1){
		bg.x = 100+20*i;bg.y = 50;
		hd.x = 100+20*i+19; hd.y = 50 + 3 * T[i];
		draw_rectangle(bg,hd,blue);
	}
}
void echange(int i, int j){
	int tmp;
	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}
void recherche_min(int debut){
	int ind_min = 0, min=100, i;
	for(i=debut; i<20; i=i+1){
		if(T[i] < min){
			ind_min = i;
			min = T[i];
		}
	}
	echange(debut,ind_min);
}
int main () {
	init_graphics(520, 400);
	
	int min = 100, max = 0, ind_min = 0, ind_max = 0; 
	init();
	for(int i = 0; i<20; i++){
		affiche();
		attendre(400);
		recherche_min(i);
		fill_screen(black);
	}
	affiche();
	
	
	wait_escape();
	exit(0);
}
