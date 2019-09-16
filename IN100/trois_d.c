#include <uvsqgraphics.h>
float taille = 600;
typedef struct point3d {int x,y,z;} POINT3D;

POINT to_2D(POINT fuite, POINT3D p3D){
	float k = p3D.z/taille;
	int deltaX = fuite.x-p3D.x, deltaY = fuite.y-p3D.y;
	POINT out;
	out.x = p3D.x + k*deltaX; out.y = p3D.y + k*deltaY;
	return out;
}

int main(){
	
	init_graphics(taille,taille);
	
	POINT fuite,pos,arrow,p1,p2,p3,p4,p5,p6,p7,p8;
	POINT3D p9,p10,p11,p12,p13,p14,p15,p16;
	int length,inc;
	fuite.x = WIDTH/2; fuite.y = HEIGHT/2;
	pos.x = 20; pos.y = 20;
	length = 200;
	inc = 5;
	
	while(1){
		arrow = get_arrow();
		if(arrow.x > 0){
			pos.x += inc;
		}
		if(arrow.x < 0){
			pos.x -= inc;
		}
		if(arrow.y > 0){
			pos.y += inc;
		}
		if(arrow.y < 0){
			pos.y -= inc;
		}
		p9.x=pos.x; p9.y=pos.y; p9.z=0;
		p10.x=pos.x+length; p10.y=pos.y; p10.z=0;
		p11.x=pos.x+length; p11.y=pos.y+length; p11.z=0;
		p12.x=pos.x; p12.y=pos.y+length; p12.z=0;
		p13.x=pos.x; p13.y=pos.y; p13.z=length;
		p14.x=pos.x+length; p14.y=pos.y; p14.z=length;
		p15.x=pos.x+length; p15.y=pos.y+length; p15.z=length;
		p16.x=pos.x; p16.y=pos.y+length; p16.z=length;
		
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
		draw_line(p1,p5,blue);
		draw_line(p2,p3,blue);
		draw_line(p2,p6,blue);
		draw_line(p3,p4,blue);
		draw_line(p3,p7,blue);
		draw_line(p4,p8,blue);
		draw_line(p5,p6,blue);
		draw_line(p5,p8,blue);
		draw_line(p6,p7,blue);
		draw_line(p7,p8,blue);
		attendre(10);
		fill_screen(black);
	}
	
	wait_escape();
	exit(0);
	 
}
