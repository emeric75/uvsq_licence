#include "uvsqgraphics.h"

void draw_motif(POINT p, int l){
	POINT p1,p2,p3;
	p1.x = p.x + l ;p1.y = p.y;
	p2.x = p.x + l ;p2.y = p.y + l;
	p3.x = p.x ;p3.y = p.y + l;
	
	draw_line(p,p1,white);
	draw_line(p1,p2,white);
	draw_line(p2,p3,white);
	draw_line(p3,p,white);
	draw_line(p,p2,white);
	draw_line(p1,p3,white);
}

void draw_motif_2(POINT p, int lo, int l, int c){
	int temp = p.y;
	for(int i = 0; i<c; i++){
		for(int j = 0; j<l; j++){
			draw_motif(p,lo);
			p.y += lo;
		}
		p.x += lo;
		p.y = temp;
	}
}

int main(){
	init_graphics(600,600);
	POINT p = wait_clic();
	draw_motif_2(p,100,5,4);
	wait_escape();
	exit(0);
}
