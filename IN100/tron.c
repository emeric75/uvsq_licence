#include <uvsqgraphics.h>

int min(int a, int b){
	if(a < b){
		return a;
	}else{
		return b;
	}	
}

int max(int a, int b){
	if(a < b){
		return b;
	}else{
		return a;
	}
}

void draw_grid(){
	/*POINT p1,p2;
	p1.y=0;p2.y=HEIGHT;
	for(int i = 0; i < WIDTH; i = i+25){
		p1.x = p2.x = i;
		draw_line(p1,p2,couleur_RGB(0,0,80));
	}
	p1.x = 0;p2.x = WIDTH;
	for(int i = 0; i < WIDTH; i = i+25){
		p1.y = p2.y = i;
		draw_line(p1,p2,couleur_RGB(0,0,50));
	}*/
	
	POINT bg,hd;
	bg.x = 0; bg.y=0;
	hd.x = 2; hd.y=2;
	
	for(int i = 0; i < ceil(WIDTH/2); i=i+1){
		for(int j = 0; j< ceil(HEIGHT/2); j=j+1){
		draw_fill_rectangle(bg,hd,couleur_RGB(i,j,pow(i+j,2)));
		bg.y = hd.y += 2;
		}
	bg.x = hd.x += 2;
	bg.y = hd.y =0;
	}
}

int main(){
	init_graphics(900,600);
	POINT pos,nDir,texte,actu_score1,actu_score2;
	int dir,GO,buffer_size,deltaP,score,nbFramesScore;
	buffer_size = 1000;
	GO = 0;
	pos.x = 450; pos.y = 100;
	dir = 1;
	deltaP = 1;
	score = 0;
	texte.x = 10; texte.y = 590;
	actu_score1.x = 0; actu_score1.y = 600;
	actu_score2.x = 60; actu_score2.y = 540;
	nbFramesScore = 0;
	POINT C[buffer_size];
	for(int i=0;i<buffer_size;i++){
		C[i].x = pos.x; C[i].y = pos.y;
	}
	
	/*draw_grid();*/
	while(GO == 0){
		draw_fill_circle(pos,2,orange);
		nDir = get_arrow();
		if(nDir.x != 0 || nDir.y != 0){
			if(nDir.x > 0){
				dir=2;
			}else{
				if(nDir.x < 0){
					dir=4;
				}
			}
			if(nDir.y > 0){
				dir=1;
			}else{
				if(nDir.y < 0){
					dir=3;
				}
			}
			for(int i=1;i<buffer_size;i++){
				C[i-1]=C[i];
			}
			C[buffer_size-1].x = pos.x; C[buffer_size-1].y = pos.y;
			
		}
		score += 1;
		aff_int(score, 15, texte, blanc);
		if(score % 1000 == 0 && deltaP < 4){
			deltaP += 1;
		}
		if(dir == 1){
			pos.y += deltaP;
		}
		if(dir == 2){
			pos.x += deltaP;
		}
		if(dir == 3){
			pos.y -= deltaP;
		}
		if(dir == 4){
			pos.x -= deltaP;
		}
		for(int i=0;i<buffer_size-1;i++){
			if(min(C[i].x,C[i+1].x)<= pos.x && pos.x <= max(C[i].x,C[i+1].x) &&  min(C[i].y,C[i+1].y)<= pos.y &&  pos.y <= max(C[i].y,C[i+1].y)){
				GO = 1;
			} 
		}
		if(pos.x<0 || pos.x>WIDTH || pos.y <0 || pos.y > HEIGHT){
			GO = 1;
		}
		nbFramesScore += 1;
		if(nbFramesScore == 5){
			draw_fill_rectangle(actu_score1,actu_score2,black);
			nbFramesScore = 0; 
		}
		attendre(5);
	}
	draw_fill_rectangle(actu_score1,actu_score2,black);
	aff_int(score, 15, texte, blanc);
	wait_escape();
	exit(0);
}
