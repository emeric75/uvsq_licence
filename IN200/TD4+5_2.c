#include <uvsqgraphics.h>
#include <math.h>

typedef struct balle{
	POINT centre;
	int rayon;
	COULEUR coul;
	float dx, dy;
}BALLE;
typedef struct raquette{
	POINT bg;
	int width,height;
	int dx;
}RQT;
BALLE init_balle(){
	BALLE b;
	b.centre.x = alea_int(WIDTH-200)+100;
	b.centre.y = alea_int(HEIGHT-200)+100;
	b.coul = couleur_RGB(alea_int(256),alea_int(256),alea_int(256));
	b.dx = pow(-1,alea_int(2))*(2.0f);
	b.dy = (1.0f);
	b.rayon = alea_int(26)+5;
	return b;
}

BALLE deplace_balle(BALLE b){
	b.centre.x += b.dx;
	b.centre.y += b.dy;
	return b;
}
void efface_balle(BALLE b){
	draw_fill_circle(b.centre,b.rayon,black);
}
void affiche_balle(BALLE b){
	draw_fill_circle(b.centre,b.rayon,b.coul);
}
BALLE rebond_balle(BALLE b,float plafond){
	if(b.centre.x-b.rayon<-1 || b.centre.x+b.rayon > WIDTH+1){
		b.dx = -b.dx;
	}
	if(b.centre.y-b.rayon<-1 || b.centre.y+b.rayon > ((int) plafond)+1){
		b.dy = -b.dy;
	}
	return b;
}
void update_plafond(float plafond){
	POINT bg, hd;
	hd.x=WIDTH;hd.y = HEIGHT;
	bg.x=0; bg.y = ((int) plafond);
	
	draw_fill_rectangle(bg,hd,couleur_RGB(100,100,100));
}
void dessine_raq(RQT raq){
	POINT raq2;
	raq2.x = raq.bg.x + raq.width;
	raq2.y = raq.bg.y + raq.height;
	draw_fill_rectangle(raq.bg,raq2,blue);
}

void efface_raq(RQT raq){
	POINT raq2;
	raq2.x = raq.bg.x + raq.width;
	raq2.y = raq.bg.y + raq.height;
	draw_fill_rectangle(raq.bg,raq2,black);
}
RQT deplace_raq(RQT raq){
	POINT arrow = get_arrow();
	if(arrow.x < 0 && raq.bg.x > 0){
		raq.bg.x -= raq.dx;
	}
	if(arrow.x > 0 && raq.bg.x+raq.width < WIDTH){
		raq.bg.x += raq.dx;
	}
	return raq;
}
int choc(BALLE b , RQT raq){
	if(b.centre.y-b.rayon <= raq.bg.y + raq.height && raq.bg.x < b.centre.x && b.centre.x  < raq.bg.x + raq.width && b.dy < 0){
		return 1;
	}
	return 0;
}
void affiche_life(int life){
	POINT p; p.x = 40; p.y = 360;
	for(int i = 0; i<life; i++){
		draw_circle(p, 20, red);
		p.x += 40;
	}
}
void affiche_score(int score){
	
	char to_aff[10];
	POINT where_to_aff, effacer;
	where_to_aff.x = 340; where_to_aff.y = 360;
	effacer.x = 400; effacer.y = 300;
	draw_fill_rectangle(where_to_aff,effacer,black);
	sprintf(to_aff,"%d",score);
	aff_pol(to_aff, 30, where_to_aff, white);
}
int main(){
	init_graphics(400,400);
	affiche_auto_off();
	
	int life = 3, nb_balles = 1, score = 0, deltascore = 0;
	float plafond = HEIGHT;
	
	BALLE bs[10];
	for(int i=0; i<10;i++){
		bs[i] = init_balle(bs[i]);
	}
	
	RQT raq;
	raq.width = 125;
	raq.height = 1;
	raq.bg.x = WIDTH/2 - raq.width/2;
	raq.bg.y = 10;
	raq.dx = 8;
	
	POINT when_restart; when_restart.x = 150; when_restart.y = 180;
	char restart[15]; sprintf(restart,"Restarting...");
	
	while(life > 0){
		efface_raq(raq);
		for(int i = 0; i<nb_balles; i++){
			efface_balle(bs[i]);
			bs[i] = rebond_balle(bs[i],plafond);
			bs[i] = deplace_balle(bs[i]);
			affiche_balle(bs[i]);
			if(choc(bs[i],raq)){
				bs[i].dy = -bs[i].dy;
				score += 1;
				deltascore += 1;
				if(raq.width > 50) raq.width -= 0.2f;
				plafond -= 0.2f;
			}
			if(bs[i].centre.y - bs[i].rayon < 0){
				efface_balle(bs[i]);
				for(int j = i+1; j < nb_balles; j++){
					bs[j-1] = bs[j];
				}
				nb_balles -= 1;
			}
			
		}
		update_plafond(plafond);
		affiche_life(life);
		affiche_score(score);
		if(deltascore == 5){
			deltascore += 1;
			life += 1;
		}
		if(deltascore == 16){
			deltascore += 1;
			if(nb_balles < 8) nb_balles += 2;
			deltascore = 0;
		}
		if(nb_balles == 0){
			life -= 1;
			deltascore = 0;
			nb_balles = 1;
			for(int i=0; i<10;i++){
				bs[i] = init_balle(bs[i]);
			}
			if(life > 0) aff_pol(restart, 40, when_restart, green);
			attendre(1500);
			fill_screen(black);
			raq.width = 125;
			raq.bg.x = WIDTH/2 - raq.width/2;
		}
		raq = deplace_raq(raq);
		dessine_raq(raq);
		affiche_all();
		attendre(1);
	}
	affiche_score(score);
	wait_escape();
	exit(0);
}
