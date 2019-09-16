#include <uvsqgraphics.h>
#include <math.h>

#define PI 3.14159265

int main () {
	int taille,deltaT,r,count,nbrLines;
	float angle,angle2,delta_a,delta_a2;
	COULEUR color = rand();
	taille = 600;
	angle = 0.0f;
	angle2 = 0.0f;
	delta_a = 1.5f;
	delta_a2 =0.4f;
	deltaT = 5;
	r = taille/2 * fabs(cos(PI/180*angle));
	count = 0;
	nbrLines = 4;
	
	init_graphics(taille,taille);
	
	POINT c; c.x = c.y = taille/2;
	
	
	POINT P1,P2,P3,P4;
	POINT P5,P6,P7,P8;
	P1.x = r* (1+cos(PI/180 * angle)+cos(PI/180 * angle2));P1.y = r * (1+sin(PI/180 * angle)+sin(PI/180 * angle2));
	P2.x = r* (1+cos(PI/180 * (angle+90))-cos(PI/180 * angle2));P2.y = r * (1+sin(PI/180 * (angle+90))-sin(PI/180 * angle2));
	P3.x = r* (1+cos(PI/180 * (angle+180))+cos(PI/180 * angle2));P3.y = r * (1+sin(PI/180 * (angle+180))+sin(PI/180 * angle2));
	P4.x = r* (1+cos(PI/180 * (angle+270))-cos(PI/180 * angle2));P4.y = r * (1+sin(PI/180 * (angle+270))-sin(PI/180 * angle2));
	P5.x = taille/2 + P1.x; P5.y= taille/2 + P1.y;
	P6.x = taille/2 + P2.x; P6.y= taille/2 + P2.y;
	P7.x = taille/2 + P3.x; P7.y= taille/2 + P3.y;
	P8.x = taille/2 + P4.x; P8.y= taille/2 + P4.y;
	while(1){
		if(angle > 360.0f){
			angle = 0.0f;
			color = rand();
		}
		draw_line(P1,P2,color);
		draw_line(P2,P3,color);
		draw_line(P3,P4,color);
		draw_line(P4,P1,color);
		//draw_line(P5,P1,color);
		//draw_line(P6,P2,color);
		//draw_line(P7,P3,color);
		//draw_line(P8,P4,color);
		draw_line(P5,P6,color);
		draw_line(P6,P7,color);
		draw_line(P7,P8,color);
		draw_line(P8,P5,color);
		
		angle += delta_a;
		angle2 += delta_a2;
		r = taille/2 * fabs(cos(PI/180*angle));
		
		
		//carré
		/*P1.x = r* (1+cos(PI/180 * angle)+cos(PI/180 * angle2));P1.y = r * (1+sin(PI/180 * angle)+sin(PI/180 * angle2));
		P2.x = r* (1+cos(PI/180 * (angle+90))+cos(PI/180 * angle2));P2.y = r * (1+sin(PI/180 * (angle+90))+sin(PI/180 * angle2));
		P3.x = r* (1+cos(PI/180 * (angle+180))+cos(PI/180 * angle2));P3.y = r * (1+sin(PI/180 * (angle+180))+sin(PI/180 * angle2));
		P4.x = r* (1+cos(PI/180 * (angle+270))+cos(PI/180 * angle2));P4.y = r * (1+sin(PI/180 * (angle+270))+sin(PI/180 * angle2));*/
		
		//flèche
		P1.x = r* (1+cos(PI/180 * angle)/(cos(PI/180 * angle2)+1.01f));P1.y = r * (1+sin(PI/180 * angle)/(cos(PI/180 * angle2)+1.01f));
		P2.x = r* (1+cos(PI/180 * (angle+90))-cos(PI/180 * angle2));P2.y = r * (1+sin(PI/180 * (angle+90))-sin(PI/180 * angle2));
		P3.x = r* (1+(cos(PI/180 * (angle+180)))/(cos(PI/180 * angle2)+1.01f));P3.y = r * (1+sin(PI/180 * (angle+180))/(cos(PI/180 * angle2)+1.01f));
		P4.x = r* (1+cos(PI/180 * (angle+270))-cos(PI/180 * angle2));P4.y = r * (1+sin(PI/180 * (angle+270))-sin(PI/180 * angle2));
		P5.x = taille - P1.x; P5.y= taille - P1.y;
		P6.x = taille - P2.x; P6.y= taille - P2.y;
		P7.x = taille - P3.x; P7.y= taille - P3.y;
		P8.x = taille - P4.x; P8.y= taille - P4.y;
		attendre(deltaT);
		count += 1;
		if(count == nbrLines){
			count = 0;
			fill_screen(black);
		}
	}
	wait_escape();
	exit(0);
}
