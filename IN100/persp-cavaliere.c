#include <uvsqgraphics.h>

#define ANGLE 45
#define PI 3.1416
typedef struct point3d {int x,y,z;} POINT3D;

POINT to2d(POINT3D p3d){
	POINT twoD;
	twoD.x = p3d.x + p3d.z*cos(ANGLE*PI/180);
	twoD.y = p3d.y + p3d.z*sin(ANGLE*PI/180);
	return twoD;
}

int main(){
	init_graphics(600,600);
	
	POINT3D P1,P2,P3,P4,P5,P6,P7,P8;
	P1.x = 150;P1.y = 150;P1.z =0;
	P2.x = 150;P2.y = 350;P2.z =0;
	P3.x = 350;P3.y = 350;P3.z =0;
	P4.x = 350;P4.y = 150;P4.z =0;
	P5.x = 150;P5.y = 150;P5.z =200;
	P6.x = 150;P6.y = 350;P6.z =200;
	P7.x = 350;P7.y = 350;P7.z =200;
	P8.x = 350;P8.y = 150;P8.z =200;
	
	POINT p1,p2,p3,p4,p5,p6,p7,p8;
	p1 = to2d(P1);
	p2 = to2d(P2);
	p3 = to2d(P3);
	p4 = to2d(P4);
	p5 = to2d(P5);
	p6 = to2d(P6);
	p7 = to2d(P7);
	p8 = to2d(P8);
	
	draw_line(p1,p2,blue);
	draw_line(p2,p3,blue);
	draw_line(p3,p4,blue);
	draw_line(p4,p1,blue);
	draw_line(p5,p6,red);
	draw_line(p6,p7,red);
	draw_line(p7,p8,red);
	draw_line(p8,p5,red);
	draw_line(p1,p5,white);
	draw_line(p2,p6,white);
	draw_line(p3,p7,white);
	draw_line(p4,p8,white);
	
	
	wait_escape();
	exit(0);
}
