#include <uvsqgraphics.h>
#include <math.h>
#include <time.h>
#define HORLOGE 0
#define CHRO 1

// Variables globales, définition des structures
//

POINT centre = {450, 400};
POINT b1 = {850, 50}, b2 = {900, 0};
POINT bst1 = {850, 100}, bst2 = {900, 50};
POINT btour1 = {850, 150}, btour2 = {900, 100};
int mode = HORLOGE;
int tab[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
typedef struct segment{
	POINT p1,p2;
	int on;
}SEG;
typedef struct chiffre{
	SEG segs[7];
}CH;
struct chrono { int h; int m; int s; int start; int tour;};
typedef struct chrono CHRONO;

//Initialisation des structures
//

void init_segments(CH* dh, CH* uh, CH* dm, CH* um, CH* ds, CH* us){
	int i,j;
	
	dh->segs[0].p1.x = 80;  dh->segs[0].p1.y = 210;
	dh->segs[0].p2.x = 160; dh->segs[0].p2.y = 210;
	dh->segs[1].p1.x  = 70; dh->segs[1].p1.y  = 200;
	dh->segs[1].p2.x  = 70; dh->segs[1].p2.y  = 120;
	dh->segs[2].p1.x= 170;  dh->segs[2].p1.y = 200;
	dh->segs[2].p2.x = 170; dh->segs[2].p2.y = 120;
	dh->segs[3].p1.x= 80;   dh->segs[3].p1.y = 110;
	dh->segs[3].p2.x = 160; dh->segs[3].p2.y = 110;
	dh->segs[4].p1.x = 70;  dh->segs[4].p1.y = 100;
	dh->segs[4].p2.x= 70;   dh->segs[4].p2.y = 20;
	dh->segs[5].p1.x = 170; dh->segs[5].p1.y = 100;
	dh->segs[5].p2.x = 170; dh->segs[5].p2.y = 20;
	dh->segs[6].p1.x = 80;  dh->segs[6].p1.y= 10;
	dh->segs[6].p2.x = 160; dh->segs[6].p2.y = 10;
	for(i = 0; i<7; i++){
		dh->segs[i].on = 0;
	}
	*us = *ds = *um = *dm = *uh = *dh; 
	for(i = 0; i<5; i++){
		for(j = 0; j<7; j++){
			switch(i){
				case 0: uh->segs[j].p1.x += 110; uh->segs[j].p2.x += 110;
				case 1: dm->segs[j].p1.x += 120; dm->segs[j].p2.x += 120;
				case 2: um->segs[j].p1.x += 120; um->segs[j].p2.x += 120;
				case 3: ds->segs[j].p1.x += 120; ds->segs[j].p2.x += 120;
				case 4: us->segs[j].p1.x += 120; us->segs[j].p2.x += 120;
			}
		}
	}
}
void init_chrono(CHRONO *chr){
	chr->h = 0;
	chr->m = 0;
	chr->s = 0;
	chr->start = 0;
	chr->tour = 0;
}

//Affichage Horloge Analogique
//

void afficher_cadran(){
	POINT chiffre_aff;
	char chiffr[3];
	draw_circle(centre,180,green);
	for(int i = 1; i<=12; i++){
		chiffre_aff.x = 165*cosf((90-30*i)*M_PI/180) + 450;
		chiffre_aff.y = 165*sinf((90-30*i)*M_PI/180) + 400;
		
		sprintf(chiffr, "%d", i);
		aff_pol_centre(chiffr,20,chiffre_aff,green);
	}
}

void afficher_secondes(int s){
	POINT sec;
	sec.x = 150*cosf((90-6*s)*M_PI/180) + 450;
	sec.y = 150*sinf((90-6*s)*M_PI/180) + 400;
	draw_line(centre,sec,red);
}
void afficher_minutes(int m, int s){
	POINT min;
	min.x = 120*cosf((90-6*m-s/10.0f)*M_PI/180) + 450;
	min.y = 120*sinf((90-6*m-s/10.0f)*M_PI/180) + 400;
	draw_line(centre,min,white);
}

void afficher_heures(int h,int m, int s){
	POINT heu;
	heu.x = 100*cosf((90-30*h-m/2.0f-s/120.0f)*M_PI/180) + 450;
	heu.y = 100*sinf((90-30*h-m/2.0f-s/120.0f)*M_PI/180) + 400;
	draw_line(centre,heu,blue);
}

//Affichage Horloge Digitale
//

void transforme(int a, CH *ch){
	for(int i = 0; i<7; i++){
		if(tab[a][i]){
			ch->segs[i].on = 1;
		}else{
			ch->segs[i].on = 0;
		}
	}
}
void aff(CH* dh, CH* uh, CH* dm, CH* um, CH* ds, CH* us){
	int i;
	for(i = 0; i<7; i++){
		if(dh->segs[i].on) draw_line(dh->segs[i].p1,dh->segs[i].p2,white);
		else draw_line(dh->segs[i].p1,dh->segs[i].p2,couleur_RGB(50,50,50));
	}
	for(i = 0; i<7; i++){
		if(uh->segs[i].on) draw_line(uh->segs[i].p1,uh->segs[i].p2,white);
		else draw_line(uh->segs[i].p1,uh->segs[i].p2,couleur_RGB(50,50,50));
	}
	for(i = 0; i<7; i++){
		if(dm->segs[i].on) draw_line(dm->segs[i].p1,dm->segs[i].p2,white);
		else draw_line(dm->segs[i].p1,dm->segs[i].p2,couleur_RGB(50,50,50));
	}
	for(i = 0; i<7; i++){
		if(um->segs[i].on) draw_line(um->segs[i].p1,um->segs[i].p2,white);
		else draw_line(um->segs[i].p1,um->segs[i].p2,couleur_RGB(50,50,50));
	}
	for(i = 0; i<7; i++){
		if(ds->segs[i].on) draw_line(ds->segs[i].p1,ds->segs[i].p2,white);
		else draw_line(ds->segs[i].p1,ds->segs[i].p2,couleur_RGB(50,50,50));
	}
	for(i = 0; i<7; i++){
		if(us->segs[i].on) draw_line(us->segs[i].p1,us->segs[i].p2,white);
		else draw_line(us->segs[i].p1,us->segs[i].p2,couleur_RGB(50,50,50));
	}
}

//Gestion du chronomètre
//

void aff_chrono(CHRONO *chr, CH* dh, CH* uh, CH* dm, CH* um, CH* ds, CH* us){
	int i;
	transforme(chr->h/10,dh);
	transforme(chr->h%10,uh);
	transforme(chr->m/10,dm);
	transforme(chr->m%10,um);
	transforme(chr->s/10,ds);
	transforme(chr->s%10,us);
	for(i = 0; i<7; i++){
		if(dh->segs[i].on) draw_line(dh->segs[i].p1,dh->segs[i].p2,orange);
		else draw_line(dh->segs[i].p1,dh->segs[i].p2,couleur_RGB(100,100,100));
	}
	for(i = 0; i<7; i++){
		if(uh->segs[i].on) draw_line(uh->segs[i].p1,uh->segs[i].p2,orange);
		else draw_line(uh->segs[i].p1,uh->segs[i].p2,couleur_RGB(100,100,100));
	}
	for(i = 0; i<7; i++){
		if(dm->segs[i].on) draw_line(dm->segs[i].p1,dm->segs[i].p2,orange);
		else draw_line(dm->segs[i].p1,dm->segs[i].p2,couleur_RGB(100,100,100));
	}
	for(i = 0; i<7; i++){
		if(um->segs[i].on) draw_line(um->segs[i].p1,um->segs[i].p2,orange);
		else draw_line(um->segs[i].p1,um->segs[i].p2,couleur_RGB(100,100,100));
	}
	for(i = 0; i<7; i++){
		if(ds->segs[i].on) draw_line(ds->segs[i].p1,ds->segs[i].p2,orange);
		else draw_line(ds->segs[i].p1,ds->segs[i].p2,couleur_RGB(100,100,100));
	}
	for(i = 0; i<7; i++){
		if(us->segs[i].on) draw_line(us->segs[i].p1,us->segs[i].p2,orange);
		else draw_line(us->segs[i].p1,us->segs[i].p2,couleur_RGB(100,100,100));
	}
}
void bouton_switch(){
	COULEUR truc;
	POINT p = get_clic();
	if(p.x > 850 && p.y < 50) mode = (mode == HORLOGE) ? CHRO : HORLOGE; 	
	if(mode == HORLOGE){ truc = green;}
	if(mode == CHRO)   { truc = orange;} 
	draw_fill_rectangle(b1,b2,truc);
}
void boutons_chrono(CHRONO *chr){
	if(mode == CHRO){
		draw_fill_rectangle(bst1,bst2,(chr->start) ? rouge : vert);
		draw_fill_rectangle(btour1,btour2,jaune);
	}else{
		draw_fill_rectangle(bst1,bst2,noir);
		draw_fill_rectangle(btour1,btour2,noir);
	}
}
void update_chrono(CHRONO *chr, CH* dh, CH* uh, CH* dm, CH* um, CH* ds, CH* us, clock_t* start_chr){
	POINT p = get_clic();
	if(p.x > 850 && p.y > 50 && p.y < 100){
		//start stop
		chr->start = (chr->start) ? 0 : 1;
	}
	if(p.x > 850 && p.y > 100 && p.y < 150){
		//tour
		chr->tour = (chr->tour) ? 0 : 1;
	}
	if(chr->start){
		if (!(chr->tour)) aff_chrono(chr,dh,uh,dm,um,ds,us);
		//printf("%f",((float)clock()-*start_chr)/CLOCKS_PER_SEC );
		if( ((double)clock()-*start_chr)/CLOCKS_PER_SEC > 1.0d ){
			*start_chr = clock();
			chr->s += 1;
			if(chr->s == 60){
				chr->s = 0;
				chr->m += 1;
				if(chr->m == 60){
					chr->m = 0;
					chr->h += 1;
				}
			}
		}	
	}
}

int main(){
	init_graphics(900,600);
	affiche_auto_off();
	clock_t start_chr = clock();
	CH dh, uh, dm, um, ds, us;
	CHRONO hor;
	CHRONO chr;
	init_chrono(&hor);
	init_chrono(&chr);
	init_segments(&dh,&uh,&dm,&um,&ds,&us);
	afficher_cadran();
	chrono_start();
	while(1){
		afficher_secondes(hor.s);
		afficher_minutes(hor.m,hor.s);
		afficher_heures(hor.h,hor.m,hor.s);
		if(mode == HORLOGE){
			transforme(hor.h/10,&dh);
			transforme(hor.h%10,&uh);
			transforme(hor.m/10,&dm);
			transforme(hor.m%10,&um);
			transforme(hor.s/10,&ds);
			transforme(hor.s%10,&us);
			aff(&dh,&uh,&dm,&um,&ds,&us);
		}
		bouton_switch();
		boutons_chrono(&chr);
		if(mode == CHRO){
			update_chrono(&chr, &dh, &uh, &dm, &um, &ds, &us, &start_chr);
		}
		if(chrono_lap() > 1.0f){
			draw_fill_circle(centre,155,black);
			hor.s += 1;
			if(hor.s == 60){
				hor.s = 0;
				hor.m += 1;
				if(hor.m == 60){
					hor.m = 0;
					hor.h += 1;
					if(hor.h == 12){
						hor.h = 0;
					}
				}
			}
			chrono_start();
		}
		affiche_all();
	}
	wait_escape();
	exit(0);
}
