#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MAX 100

int T[N];
void init(){
	for(int i=0; i<N; i++){
		T[i] = alea_int(MAX-10)+10;
	}
}

void disp(){
	for(int i=0; i<N; i++){
		write_int(T[i]);write_text(" ");
		if(i%20 == 19){
			writeln();
		}
	}
	writeln();
}
void disp_tri(int min, int max){
	for(int i=0; i<N; i++){
		write_int(T[i]);write_text(" ");
	}
	write_text(" |    | ");write_int(min);write_text(" ");write_int(max);
	writeln();
}
void disp_ech(int min, int max){
	for(int i=0; i<N; i++){
		write_int(T[i]);write_text(" ");
	}
	write_text(" |    | ");write_int(min);write_text(" ");write_int(max);write_text(" ech");
	writeln();
}
	
void echange(int i, int j){
	int tmp;
	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}

void tri_fusion(int min,int max){
	//condition d'arrêt
	if(max-min==0){
		return;
	}else if(max-min==1){
		if(T[max]<T[min])
			echange(min,max);
		return;
	}
	
	//séparation en deux sous-tableaux et tri
	int mil = (min+max)/2;
	tri_fusion(min,mil);
	tri_fusion(mil+1,max);
	
	//FUUUUUUUUUUSION
	int i,c1=0,c2=0;
	int temptab[N];
	for(i = min; i<max; i++){
		
		if(T[min+c1]<T[mil+1+c2] && min+c1<=mil){
			temptab[i] = T[min+c1];
			c1++;
		}else{
			temptab[i] = T[mil+1+c2];
			c2++;
		}
	
	}
	for(i = min; i<max; i++){
		T[i] = temptab[i];
	}
	disp_ech(min,max);
}


int main(){
	init_graphics(800,600);
	
	clock_t t1,t2,t3,t4;
	
	init();
	disp();
	write_text("fusion...");writeln();
	t1=clock();
	tri_fusion(0,N);
	t2=clock();
	printf("Temps ecoule fusion : %lf\n", (double)(t2-t1)/(double)CLOCKS_PER_SEC);
	disp();
	wait_escape();
}
