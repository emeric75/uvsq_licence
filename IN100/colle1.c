#include <uvsqgraphics.h>

int main () {
	init_graphics(600,600);
	POINT carre1,carre2,clic;
	carre1.x = WIDTH/2 - 25; carre1.y = HEIGHT/2 - 25;
	carre2.x = WIDTH/2 + 25; carre2.y = HEIGHT/2 + 25;
	
	draw_rectangle(carre1,carre2,blue);
	clic = wait_clic();
	while((clic.x < carre1.x || clic.x > carre2.x) || (clic.y < carre1.y || clic.y > carre2.y)){
		if(clic.x < (carre1.x+carre2.x)/2){
			carre1.x -= 10;
			carre2.x -= 10;
		}else{
			carre1.x += 10;
			carre2.x += 10;
		}
		fill_screen(black);
		draw_rectangle(carre1,carre2,blue);
		clic = wait_clic();
	}
	
	wait_escape();
	exit(0);
}
