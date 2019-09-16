#include <uvsqgraphics.h>

int main(){
	init_graphics(600,600);
	POINT p1,p2,clic;
	p1.x = p2.x = WIDTH/2; p1.y = 0; p2.y = HEIGHT;
	draw_line(p1,p2,white);
	int prev_clic=0;
	for(int i = 0; i<20; i++){
		clic = wait_clic();
		if (clic.x < WIDTH/2){
			draw_circle(clic,20,red);
			prev_clic = 0;
		}else{
			if(prev_clic){
				draw_circle(clic,20,blue);
			}
			prev_clic = 1;
		}
	}
	wait_escape();
	exit(0);
}
