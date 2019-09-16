#include <uvsqgraphics.h>

void dessine_choix(){
	POINT base,base2;
	COULEUR c[2][2] = {{bleu,jaune},{vert,rouge}};
	base.x = WIDTH-20; base.y = 0;
	base2.x = base.x+10; base2.y = base.y + 10;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			draw_fill_rectangle(base,base2,c[i][j]);
			base.x += 10;
			base2.x += 10;
		}
		base.x = WIDTH-20;
		base2.x = base.x+10;
		base.y += 10;
		base2.y += 10;
	}
}

COULEUR choix_couleur(POINT p){
	if(p.x >= 580 && p.y <= 20){
		if(p.x >= 590 && p.y <= 10){
			return jaune;
		}else{
			if(p.x >= 590){
				return rouge;
			}
			if(p.y <= 10){
				return bleu;
			}
			if(p.x < 590 && p.y > 10){
				return vert;
			}
		}
	}else{
		return noir;
	}

}

void dessine_cercle(){
	COULEUR courante = noir;
	POINT p;
	p = wait_clic();
	while(choix_couleur(p) != noir){
		courante = choix_couleur(p);
		p = wait_clic();
	}
	draw_circle(p,50,courante);
}

int main(){
	init_graphics(600,600);
	dessine_choix();
	for(int i = 0; i<20; i++){
		dessine_cercle();
	}
	wait_escape();
	exit(0);
}
