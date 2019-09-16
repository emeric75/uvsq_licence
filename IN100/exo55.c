#include <uvsqgraphics.h>

int main(){
	init_graphics(600,600);
	POINT p1,p2,p3,p4,or,hd,clic;
	int i,state_b,state_w,state_r;
	state_b=state_w=state_r=0;
	or.x = or.y =0;
	hd.x = WIDTH; hd.y = HEIGHT;
	p1.x = p2.x = WIDTH/3; p1.y = 0; p2.y = HEIGHT;
	p3.x = p4.x = 2*WIDTH/3; p3.y = 0; p4.y = HEIGHT;
	draw_line(p1,p2,white);
	draw_line(p3,p4,white);
	
	for(i=0; i<20; i++){
		clic = wait_clic();
		if(clic.x < 2*WIDTH/3){
			if(clic.x < WIDTH/3){
				if(state_b){
					draw_fill_rectangle(or,p2,black);
					state_b=0;
				}else{
					draw_fill_rectangle(or,p2,blue);
					state_b=1;
				}
			}else{
				if(state_w){
					draw_fill_rectangle(p1,p4,black);
					state_w=0;
				}else{
					draw_fill_rectangle(p1,p4,white);
					state_w=1;
				}
			}
		}else{
			if(state_r){
				draw_fill_rectangle(p3,hd,black);
				state_r=0;
			}else{
				draw_fill_rectangle(p3,hd,red);
				state_r=1;
			}
		}
		draw_line(p1,p2,white);
		draw_line(p3,p4,white);
	}
	wait_escape();
}
