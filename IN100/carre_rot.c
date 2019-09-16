#include <uvsqgraphics.h>
#include <math.h>

#define PI 3.14159265

int main () {
	int taille,deltaT,r,count,nbrLines;
	float angle,angle2,delta_a,delta_a2;
	COULEUR color = rand();
	taille = 600;
	angle = 0.0f;
	delta_a = 0.2f;
	deltaT = 5;
	r = taille/2;
	count = 0;
	nbrLines = 10;
	
	init_graphics(taille,taille);
	
	POINT c; c.x = c.y = taille/2;
	
	
	POINT P1,P2,P3,P4,arrow;
	P1.x = r* (1+cos(PI/180 * angle));P1.y = r * (1+sin(PI/180 * angle));
	P2.x = r* (1+cos(PI/180 * (angle+90)));P2.y = r * (1+sin(PI/180 * (angle+90)));
	P3.x = r* (1+cos(PI/180 * (angle+180)));P3.y = r * (1+sin(PI/180 * (angle+180)));
	P4.x = r* (1+cos(PI/180 * (angle+270)));P4.y = r * (1+sin(PI/180 * (angle+270)));
	while(1){
		arrow = get_arrow();
		if(arrow.x > 0){
			angle += delta_a;
		}
		if(arrow.x < 0){
			angle -= delta_a;
		}
		P1.x = r* (1+cos(PI/180 * angle));P1.y = r * (1+sin(PI/180 * angle));
		P2.x = r* (1+cos(PI/180 * (angle+90)));P2.y = r * (1+sin(PI/180 * (angle+90)));
		P3.x = r* (1+cos(PI/180 * (angle+180)));P3.y = r * (1+sin(PI/180 * (angle+180)));
		P4.x = r* (1+cos(PI/180 * (angle+270)));P4.y = r * (1+sin(PI/180 * (angle+270)));
		draw_line(P1,P2,color);
		draw_line(P2,P3,color);
		draw_line(P3,P4,color);
		draw_line(P4,P1,color);
		attendre(5);
		fill_screen(black);
	}
	
	wait_escape();
	exit(0);
}
