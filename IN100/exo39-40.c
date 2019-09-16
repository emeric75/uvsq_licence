#include <uvsqgraphics.h>

int main () {
	init_graphics(520, 400);
	
	int T[20];
	int i;
	int min = 100, max = 0, ind_min = 0, ind_max = 0; 
	POINT bg,hd;
	
	for(i=0; i<20; i=i+1){
		T[i] = alea_int(100);
		bg.x = 100+20*i;bg.y = 50;
		hd.x = 100+20*i+19; hd.y = 50 + 3 * T[i];
		if(T[i] < min){
			ind_min = i;
			min = T[i];
		}
		if(T[i] > max){
			ind_max = i;
			max = T[i];
		}
		draw_rectangle(bg,hd,blue);
	}
	
	bg.x = 100+20*ind_min; bg.y = 50;
	hd.x = 100+20*ind_min+19; hd.y = 50 + 3 * min;
	draw_rectangle(bg,hd,red);
	
	bg.x = 100+20*ind_max; bg.y = 50;
	hd.x = 100+20*ind_max+19; hd.y = 50 + 3 * max;
	draw_rectangle(bg,hd,green);
	
	wait_escape();
	exit(0);
}
	
