#include <uvsqgraphics.h>
#include <math.h>

#define PI 3.14159265
float taille = 600;
typedef struct point3d {int x,y,z;} POINT3D;

POINT to_2D(POINT fuite, POINT3D p3D){
	float k = p3D.z/taille;
	int deltaX = fuite.x-p3D.x, deltaY = fuite.y-p3D.y;
	POINT out;
	out.x = p3D.x + k*deltaX; out.y = p3D.y + k*deltaY;
	return out;
}

/*POINT3D rot_x(POINT3D point, float angle){
	point.y = cos(angle)*(point.y-fuite.y)+fuite.y - sin(angle)*point.z;
	point.z = sin(angle)*point.y + cos(angle)*(point.z-taille)+taille;
	return point;
}

POINT3D rot_y(POINT3D point, float angle){
	point.x = cos(angle)*(point.x-fuite.x)+fuite.x - sin(angle)*point.z;
	point.z = sin(angle)*point.x + cos(angle)*(point.z-taille)+taille;
	return point;
}*/

POINT3D rot_z(POINT3D point, float angle){
	POINT3D or;
	float tx,ty;
	or.x = WIDTH/2;
	or.y = WIDTH/2;
	or.z = point.z;
	tx = cos(angle)*(point.x-or.x)- sin(angle)*(point.y-or.y)+or.x;
	ty = sin(angle)*(point.x-or.x)+ cos(angle)*(point.y-or.y)+or.y;
	point.x=tx;
	point.y=ty;
	return point;
}

int main () {
	int taille,deltaT,r,count,nbrLines;
	float angle,angle2,delta_a,delta_a2,anglez;
	COULEUR color = rand();
	taille = 600;
	angle = 0.0f;
	anglez=0.0f;
	delta_a = 3.0f;
	deltaT = 5;
	r = 200;
	count = 0;
	nbrLines = 10;
	
	init_graphics(taille,taille);
	
	POINT c; c.x = c.y = taille/2;
	
	
	POINT3D Pt1,Pt2,Pt3,Pt4,Pt5,Pt6,Pt7,Pt8;
	POINT P1,P2,P3,P4,P5,P6,P7,P8,arrow;
	
	Pt1.x = c.x +r* (cos(PI/180 * angle));Pt1.y = c.y +r * (sin(PI/180 * angle));Pt1.z = 0;
	Pt2.x = c.x +r* (cos(PI/180 * (angle+90)));Pt2.y = c.y +r * (sin(PI/180 * (angle+90)));Pt2.z=0;
	Pt3.x = c.x +r* (cos(PI/180 * (angle+180)));Pt3.y = c.y +r * (sin(PI/180 * (angle+180)));Pt3.z=0;
	Pt4.x = c.x +r* (cos(PI/180 * (angle+270)));Pt4.y = c.y +r * (sin(PI/180 * (angle+270)));Pt4.z=0;
	Pt5.x = c.x +r* (cos(PI/180 * angle));Pt5.y = c.y +r * (sin(PI/180 * angle));Pt5.z = 200;
	Pt6.x = c.x +r* (cos(PI/180 * (angle+90)));Pt6.y = c.y +r * (sin(PI/180 * (angle+90)));Pt6.z=200;
	Pt7.x = c.x +r* (cos(PI/180 * (angle+180)));Pt7.y = c.y +r * (sin(PI/180 * (angle+180)));Pt7.z=200;
	Pt8.x = c.x +r* (cos(PI/180 * (angle+270)));Pt8.y = c.y +r * (sin(PI/180 * (angle+270)));Pt8.z=200;
	while(1){
		arrow = get_arrow();
		if(arrow.x < 0){
			angle += delta_a;
		}
		if(arrow.x > 0){
			angle -= delta_a;
		}
		if(arrow.y < 0){
			anglez += delta_a;
		}
		if(arrow.y > 0){
			anglez -= delta_a;
		}
		
		Pt1.x = c.x + r* (cos(PI/180 * angle));Pt1.y = c.y +r * (sin(PI/180 * angle) + cos(PI/180 * (anglez-45)));Pt1.z = r*cos(PI/180 * (anglez-45));
		Pt2.x = c.x +r* (cos(PI/180 * (angle+90)));Pt2.y = c.y +r * (sin(PI/180 * (angle+90)) + cos(PI/180 * (anglez-45)));Pt2.z= r*cos(PI/180 * (anglez-45));
		Pt3.x = c.x +r* (cos(PI/180 * (angle+180)));Pt3.y = c.y +r * (sin(PI/180 * (angle+180)) + cos(PI/180*(anglez+45)) );Pt3.z= r*cos(PI/180*(anglez+45)) ;
		Pt4.x = c.x +r* (cos(PI/180 * (angle+270)));Pt4.y = c.y +r * (sin(PI/180 * (angle+270)) + cos(PI/180*(anglez+45)) );Pt4.z= r*cos(PI/180*(anglez+45)) ;
		Pt5.x = c.x +r* (cos(PI/180 * angle));Pt5.y = c.y +r * (sin(PI/180 * angle) + cos(PI/180*(anglez-135)) );Pt5.z = r*cos(PI/180*(anglez-135)) ;
		Pt6.x = c.x +r* (cos(PI/180 * (angle+90)));Pt6.y = c.y +r * (sin(PI/180 * (angle+90)) + cos(PI/180*(anglez-135)) );Pt6.z= r*cos(PI/180*(anglez-135)) ;
		Pt7.x = c.x +r* (cos(PI/180 * (angle+180)));Pt7.y = c.y +r * (sin(PI/180 * (angle+180)) + cos(PI/180*(anglez+135)) );Pt7.z= r*cos(PI/180*(anglez+135)) ;
		Pt8.x = c.x +r* (cos(PI/180 * (angle+270)));Pt8.y = c.y +r * (sin(PI/180 * (angle+270)) + cos(PI/180*(anglez+135)) );Pt8.z= r*cos(PI/180*(anglez+135)) ;
		P1=to_2D(c,Pt1);
		P2=to_2D(c,Pt2);
		P3=to_2D(c,Pt3);
		P4=to_2D(c,Pt4);
		P5=to_2D(c,Pt5);
		P6=to_2D(c,Pt6);
		P7=to_2D(c,Pt7);
		P8=to_2D(c,Pt8);
		draw_line(P1,P2,blue);
		draw_line(P1,P4,blue);
		draw_line(P1,P5,blue);
		draw_line(P2,P3,blue);
		draw_line(P2,P6,blue);
		draw_line(P3,P4,blue);
		draw_line(P3,P7,blue);
		draw_line(P4,P8,blue);
		draw_line(P5,P6,blue);
		draw_line(P5,P8,blue);
		draw_line(P6,P7,blue);
		draw_line(P7,P8,blue);
		attendre(10);
		fill_screen(black);
	}
	
	wait_escape();
	exit(0);
}
/*int main(){
	init_graphics(taille,taille);
	
	POINT fuite,pos,arrow,key,p1,p2,p3,p4,p5,p6,p7,p8;
	POINT3D p9,p10,p11,p12,p13,p14,p15,p16;
	int length;
	fuite.x = WIDTH/2; fuite.y = HEIGHT/2;
	int angle = 0;
	pos.x = WIDTH/4;pos.y = WIDTH/4;
	length = taille/4;
	
	p9.x=pos.x+length*cos((angle)/180*PI); p9.y=pos.y+length*sin(angle/180*PI); p9.z=0;
	p10.x=pos.x+length*cos((angle+90)/180*PI); p10.y=pos.y+length*sin((angle+90)/180*PI); p10.z=0;
	p11.x=pos.x+length*cos((angle+180)/180*PI); p11.y=pos.y+length*sin((angle+180)/180*PI); p11.z=0;
	p12.x=pos.x+length*cos((angle+270)/180*PI); p12.y=pos.y+length*sin((angle+270)/180*PI); p12.z=0;
	p13.x=pos.x+length*cos(angle); p13.y=pos.y; p13.z=length;
	p14.x=pos.x+length*cos(angle+90); p14.y=pos.y; p14.z=length;
	p15.x=pos.x+length*cos(angle+180); p15.y=pos.y+length; p15.z=length;
	p16.x=pos.x+length*cos(angle-90); p16.y=pos.y+length; p16.z=length;
	while(1){
		arrow = get_arrow();
		if(arrow.x>0){
			p9 = rot_z(p9,-2*PI/180);
			p10 = rot_z(p10,-2*PI/180);
			p11 = rot_z(p11,-2*PI/180);
			p12 =rot_z(p12,-2*PI/180);
			angle++;
			p13 =rot_z(p13,-2*PI/180);
			p14 =rot_z(p14,-2*PI/180);
			p15 =rot_z(p15,-2*PI/180);
			p16 =rot_z(p16,-2*PI/180);
		}
		if(arrow.x<0){
			p9=rot_z(p9,2*PI/180);
			p10=rot_z(p10,2*PI/180);
			p11=rot_z(p11,2*PI/180);
			p12=rot_z(p12,2*PI/180);
			p13=rot_z(p13,2*PI/180);
			p14=rot_z(p14,2*PI/180);
			p15=rot_z(p15,2*PI/180);
			p16=rot_z(p16,2*PI/180);
			angle--;
		}
		p9.x=pos.x+length*cos((angle)/180*PI); p9.y=pos.y+length*sin(angle/180*PI); p9.z=0;
		p10.x=pos.x+length*cos((angle+90)/180*PI); p10.y=pos.y+length*sin((angle+90)/180*PI); p10.z=0;
		p11.x=pos.x+length*cos((angle+180)/180*PI); p11.y=pos.y+length*sin((angle+180)/180*PI); p11.z=0;
		p12.x=pos.x+length*cos((angle+270)/180*PI); p12.y=pos.y+length*sin((angle+270)/180*PI); p12.z=0;	
		p1 = to_2D(fuite,p9); 
		p2 = to_2D(fuite,p10);
		p3 = to_2D(fuite,p11);
		p4 = to_2D(fuite,p12);
		p5 = to_2D(fuite,p13);
		p6 = to_2D(fuite,p14);
		p7 = to_2D(fuite,p15);
		p8 = to_2D(fuite,p16);
			
		draw_line(p1,p2,blue);
		draw_line(p1,p4,blue);
		//draw_line(p1,p5,blue);
		draw_line(p2,p3,blue);
		//draw_line(p2,p6,blue);
		draw_line(p3,p4,blue);
		//draw_line(p3,p7,blue);
		//draw_line(p4,p8,blue);
		//draw_line(p5,p6,blue);
		//draw_line(p5,p8,blue);
		//draw_line(p6,p7,blue);
		//draw_line(p7,p8,blue);
		//fill_screen(black);
		attendre(20);
	}
	
	wait_escape();
	exit(0);
}*/
