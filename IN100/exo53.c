#include <uvsqgraphics.h>

int main(){
	init_graphics(600,600);
	POINT p1,p2,clic;
	p1.x = p2.x = WIDTH/2; p1.y = 0; p2.y = HEIGHT;
	draw_line(p1,p2,white);
	int count_red=0;
	for(int i = 0; i<20; i++){
		clic = wait_clic();
		if (clic.x < WIDTH/2){
			draw_circle(clic,20,red);
			count_red+=1;
		}else{
			if(count_red){
				draw_circle(clic,20,blue);
			}
		}
	}
	wait_escape();
	exit(0);
}
