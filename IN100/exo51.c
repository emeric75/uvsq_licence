#include <uvsqgraphics.h>
POINT c,c_precedent;

void efface_affiche(){
	draw_fill_circle(c_precedent,30,noir);
	draw_fill_circle(c,30,blue);
}

void plus_ou_moins(POINT p){
	c_precedent = c;
	if (p.y>c.y){
		c.y += 2;
	}else{
		c.y -= 2;
	}

}

int main(){
	int i;
	init_graphics(400,400);
	
	c_precedent.x=0;
	c_precedent.y=0;
	
	c.x=200;
	c.y=200;
	
	while(1){
		efface_affiche();
		plus_ou_moins(c);
	}


}
