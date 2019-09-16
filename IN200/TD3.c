#include "uvsqgraphics.h"


void affiche_allumette(POINT p){
	POINT p2;
	p2.x = p.x+5; p2.y = p.y + 300;
	draw_fill_rectangle(p,p2,white);
}
/*
void efface_allumette(POINT p){
	POINT p2;
	p2.x = p.x+5; p2.y = p.y + 300
	draw_fill_rectangle(p,p2,black);
}*/
void affiche_choix(){
	POINT bg, hd;
	bg.x = 50; bg.y = 50;
	hd.x = 150; hd.y = 150;
	for(int i = 0; i<3; i++){
		draw_fill_rectangle(bg,hd,white);
		bg.x += 200;
		hd.x += 200;
	}
	POINT centre;
	centre.x = 100; centre.y = 100;
	draw_fill_circle(centre,10,black);
	centre.x = 275; centre.y = 125;
	draw_fill_circle(centre,10,black);
	centre.x = 325; centre.y = 75;
	draw_fill_circle(centre,10,black);
	
	centre.x = 475; centre.y = 75;
	draw_fill_circle(centre,10,black);
	centre.x = 505; centre.y = 100;
	draw_fill_circle(centre,10,black);
	centre.x = 540; centre.y = 125;
	draw_fill_circle(centre,10,black);
	
}
void affiche_allumettes(int N){
	POINT p;
	p.x = 20; p.y = 200;
	for(int i = 0; i<N; i++){
		affiche_allumette(p);
		p.x += 20;
	}
}
int get_valeur(){
	int out = 0;
	POINT p;
	while(out == 0){
		p = wait_clic();
		if(50<=p.y && p.y <= 150){
			if(50<=p.x&&p.x<=150){
				out = 1;
			}
			if(250<=p.x&&p.x<=350){
				out = 2;
			}
			if(450<=p.x&&p.x<=550){
				out = 3;
			}
		}
	}
	return out;
}
int main(){
	init_graphics(600,600);
	int remaining = 23, player = 2;
	POINT aff_rem, aff_player;
	aff_rem.x = 500; aff_rem.y = 300;
	aff_player.x = 400; aff_player.y = 550;
	while(remaining > 0){
		if(player == 1) player = 2; else player = 1;
		
		affiche_choix();
		
		char to_aff[4];
		sprintf(to_aff,"%d",remaining);
		aff_pol(to_aff,40,aff_rem,white);
		char to_aff_player[12];
		sprintf(to_aff_player,"Joueur %d",player);
		aff_pol(to_aff_player,40,aff_player,white);
		
		
		affiche_allumettes(remaining);
		remaining -= get_valeur();
		fill_screen(black);
		
	}
	aff_player.x = 100;
	char to_aff_player[20];
	sprintf(to_aff_player,"Joueur %d gagne",player);
	aff_pol(to_aff_player,60,aff_player,white);
	wait_escape();
	exit(0);
}
