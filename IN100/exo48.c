#include <uvsqgraphics.h>

/*void dessine_quadrilatere(POINT p1, POINT p2,POINT p3,POINT p4){
	POINT temp;
	if(p1.x > p2.x){
		temp = p2;
		p2 = p1;
		p1=temp;
	}
	if(p2.y < p3.y){
		temp = p3;
		p3 = p2;
		p2=temp;
	}
	if(p3.x<p4.x){
		temp = p4;
		p4 = p3;
		p3=temp;
	}
	if(p4.y>p1.y){
		temp = p4;
		p4 = p1;
		p1=temp;
	}
	if(p1.x > p2.x){
		temp = p2;
		p2 = p1;
		p1=temp;
	}
	if(p2.y < p3.y){
		temp = p3;
		p3 = p2;
		p2=temp;
	}
	if(p3.x<p4.x){
		temp = p4;
		p4 = p3;
		p3=temp;
	}
	if(p4.y>p1.y){
		temp = p4;
		p4 = p1;
		p1=temp;
	}
	draw_line(p1,p2,red);
	draw_line(p2,p3,red);
	draw_line(p3,p4,red);
	draw_line(p4,p1,red);
	
}
*/
void dessine_quadrilatere(POINT p1, POINT p2,POINT p3,POINT p4){
	POINT triY[4] = {p1,p2,p3,p4};
	POINT triprint[4];
	POINT temp;
	int maxY=0,indY=0;
	for(int ind=0; ind<4;ind++){
		for(int i=ind; i<4; i++){
			if(triY[i].y > maxY){
				maxY = triY[i].y;
				indY = i;
			}
		}
		temp = triY[ind];
		triY[ind] = triY[indY];
		triY[indY] = temp;
		triprint[ind] = triY[ind];
		maxY=0;indY=0;
	}
	if(triY[0].x > triY[1].x){
		triprint[0] = triY[1]; 
		triprint[1] = triY[0]; 
	}
	if(triY[2].x < triY[3].x){
		triprint[2] = triY[3];
		triprint[3] = triY[2];
	}
	for(int i = 0;i<4; i++){
		draw_line(triprint[i%4], triprint[(i+1)%4], blue);
	}
}
int main(){
	init_graphics(600,600);
	
	POINT p1,p2,p3,p4;
	
	p1=wait_clic();
	p2=wait_clic();
	p3=wait_clic();
	p4=wait_clic();
	
	dessine_quadrilatere(p1,p2,p3,p4);
	wait_escape();
	exit(0);
}
