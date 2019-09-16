#include <uvsqgraphics.h>


int main(){
	int taille=600;
	int d = taille/8;
	init_graphics(taille,taille);
	POINT bg,hd;
	bg.x = bg.y = 0;
	hd.x = bg.x + d; hd.y = bg.y + d; 
	
	for(int i = 0; i<64; i++){
		bg.x = d*(i%8); bg.y = d*(i/8);
		hd.x = bg.x + d; hd.y = bg.y + d;
		if((i/8)%2 == i%2){
			draw_fill_rectangle(bg,hd,white);
		}
	}
	/*for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			bg.x = d*i; bg.y = d*j;
			hd.x = bg.x+d; hd.y = bg.y+d;
			if(i%2==j%2){
				draw_fill_rectangle(bg,hd,white);
			}
		}
	}*/
	wait_escape();
}
