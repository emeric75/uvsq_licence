#include <uvsqgraphics.h>

int main(){
	int taille = 600;
	init_graphics(taille,taille);
	
	POINT points[10];
	POINT p;
	
	for(int i = 0; i < 10; i = i+1){
		p = wait_clic();
		draw_circle(p,20,red);
		points[i] = p;
	}
	int remaining = 10;
	while(remaining != 0){
		p = wait_clic();
		for(int index = 0; index < 10; index = index + 1){
			if(pow(p.x-points[index].x,2) + pow(p.y-points[index].y,2) < pow(20,2)){
				draw_circle(points[index],20,black);
				points[index].x = -100;
				points[index].y = -100; 
				remaining -= 1;
			}
		}
	}
	
	wait_escape();
	exit(0);
}
