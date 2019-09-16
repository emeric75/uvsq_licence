#include <uvsqgraphics.h>

int main(){
	init_graphics(512,512);
	POINT bg,hd;
	bg.x = bg.y = 0;
	hd.x = bg.x + 2; hd.y = bg.x + 2;
	
	for(int i = 0; i<256; i++){
		for(int j = 0; j<256; j++){
			bg.x = 2*i; bg.y = 2*j; hd.x = bg.x + 2; hd.y = bg.y + 2;
			draw_fill_rectangle(bg,hd,couleur_RGB(pow(sqrt(i*j),2),abs(i-pow(j,2))/4,pow(((i+j)/2),1/3)));
		}
	}
	
	wait_escape();
}
