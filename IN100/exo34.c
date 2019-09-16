#include <uvsqgraphics.h>
#define WIDTH  800
#define HEIGHT 542
int main () {
	init_graphics(WIDTH,HEIGHT);
	
	POINT hg,bd;
	hg.x = 0; hg.y=1;
	bd.x = WIDTH; bd.y=1;
	for(int i = 0; i < HEIGHT; i=i+1){
		draw_fill_rectangle(hg,bd,couleur_RGB(2*i,i,i/2));
		hg.y = bd.y += 1;
	}
		
	wait_escape();
	exit(0);
}
