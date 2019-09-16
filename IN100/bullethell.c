#include <uvsqgraphics.h>
#include <tgmath.h>
#define PI 3.1415159
int main () {
	int taille = 600;
	init_graphics(taille,taille);
	
	POINT pos1,pos2,fleche;
	pos1.x=250;pos1.y=30;
	pos2.x=350;pos2.y=80;
	
	POINT foe;
	foe.x=300;foe.y=550;
	int etat_foe;
	etat_foe = 1;
	
	POINT bullet;
	int angle,deltaX,deltaY;
	
	bullet.x=foe.x; bullet.y=foe.y;
	angle = -45;
	deltaX = 10*cos(angle*PI/180)*cos(angle*PI/180);
	deltaY = 10*sin(angle*PI/180)*sin(angle*PI/180);
	
	draw_rectangle(pos1,pos2,blue);
	draw_circle(foe,30,yellow);
	draw_fill_circle(bullet,5,yellow);
	while(1){
		fleche = get_arrow();
		if(fleche.x < 0){
			pos1.x -= 5; pos2.x -= 5;
		}else{
			if(fleche.x > 0){
				pos1.x += 5; pos2.x += 5;
			}
		}
		if(foe.x>WIDTH-30){
			etat_foe = 0;
		}
		if(foe.x<30){
			etat_foe = 1;
		}
		if(etat_foe == 1){
			foe.x += 5;
		}else{
			foe.x -= 5;
		}
		if(bullet.x<0 || bullet.x>WIDTH){
			deltaX = -deltaX;
		}
		if(bullet.y >= -20){
			bullet.y -= deltaY;
			bullet.x += deltaX;
			if(bullet.y == 80 && (pos1.x<bullet.x && bullet.x <= pos2.x)){
				deltaX = -deltaX;
				deltaY = -deltaY; 
			}
		}else{
			if(bullet.y > 600){
				deltaY = -deltaY;
			}else{
				bullet.x=foe.x;
				bullet.y=foe.y;
				if(alea_int(2)){
					angle = -(90-alea_int(60)-5);
				}else{
					angle = -(90+alea_int(60)+5);
				}
				deltaX = 10*cos(angle*PI/180)*cos(angle*PI/180);
				deltaY = 10*sin(angle*PI/180)*sin(angle*PI/180);
			}
		}
		draw_rectangle(pos1,pos2,blue);
		draw_circle(foe,30,yellow);
		draw_fill_circle(bullet,5,yellow);
		attendre(10);
		fill_screen(black);
	}
	wait_escape();
	exit(0);
}
	
	
