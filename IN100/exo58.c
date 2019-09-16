#include <uvsqgraphics.h>

int main(){
	init_graphics(512,512);
	POINT bg,hd;
	bg.x = bg.y = 0;
	hd.x = bg.x + 2; hd.y = HEIGHT;
	
	for(int i = 0; i<256; i++){
		bg.x = 2*i; hd.x = bg.x + 2;
		draw_fill_rectangle(bg,hd,couleur_RGB(i,0,0));
	}
	
	wait_escape();
}
