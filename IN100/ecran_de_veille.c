#include <uvsqgraphics.h>

int main () {
	int taille = 800;
	init_graphics(taille,taille);
	
	
	int delta,deltaT,etat;
	delta = 5; deltaT=5;
	POINT t1,t2;
	COULEUR colors[16]={argent,blanc,bleu,bleumarine,citronvert,cyan,magenta,gris,jaune,marron,noir,rouge,sarcelle,vertclair,vertolive,violet};
	COULEUR c;
	
	t1.x=0;t1.y=0;
	t2.x=taille;t2.y=taille;
	
	while(1){
		c=colors[alea_int(16)];
		etat = alea_int(4);
		delta = alea_int(5)+1;
		deltaT = 2*delta; 
		if(etat == 0){
			c=colors[alea_int(16)];
			while(t1.x<taille){
				draw_line(t1,t2,c);
				t1.x = t1.x+delta;
				t2.x = t2.x-delta;
				attendre(deltaT);
			}
		}
		if(etat == 1){
			c=colors[alea_int(16)];
			while(t1.y<taille){
				draw_line(t1,t2,c);
				t1.y = t1.y+delta;
				t2.y = t2.y-delta;
				attendre(deltaT);
			}	
		}
		if(etat == 2){
			c=colors[alea_int(16)];
			while(t1.x>0){
				draw_line(t1,t2,c);
				t1.x = t1.x-delta;
				t2.x = t2.x+delta;
				attendre(deltaT);
			}
		}
		if(etat == 3){
			c=colors[alea_int(16)];
			while(t1.y>0){
				draw_line(t1,t2,c);
				t1.y = t1.y-delta;
				t2.y = t2.y+delta;
				attendre(deltaT);
			}
		}
	}
	wait_escape();
	exit(0);
}
