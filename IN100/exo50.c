#include <uvsqgraphics.h>


int a_qui_de_jouer;
void quadrillage(){
	POINT l1,l2;
	l1.y = 0; l2.y = HEIGHT;
	for(int x = 100; x <= 300; x += 100){
		l1.x = l2.x = x;
		draw_line(l1,l2,white);
	}
	l1.x = 0; l2.x = WIDTH;
	for(int y = 100; y <= 300; y += 100){
		l1.y = l2.y = y;
		draw_line(l1,l2,white);
	}

}
void dessine_action(POINT p){
	POINT centre,X1,X2,X3,X4;
	centre.x = 100*(p.x/100) + 50;
	centre.y = 100*(p.y/100) + 50; 
	
	
	if(a_qui_de_jouer%2 == 0){
		X1.x = centre.x - 50;  X1.y = centre.y + 50;
		X2.x = centre.x + 50;  X2.y = centre.y - 50;
		X3.x = centre.x - 50;  X3.y = centre.y - 50;
		X4.x = centre.x + 50;  X4.y = centre.y + 50;
	
		draw_line(X1,X2,red);
		draw_line(X3,X4,red);
	}
	else{
		draw_circle(centre,49,blue);
	}
	
}

int main(){
	init_graphics(300,300);
	quadrillage();
	POINT p;
	int k=0;
	while(k<9){
		p = wait_clic();
		dessine_action(p);
		k++;
		a_qui_de_jouer++;
	}
	wait_escape();
	exit(0);
}
