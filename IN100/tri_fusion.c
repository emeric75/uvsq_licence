#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 16
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
int indice_du_plus_grand(int min, int max){
	int maxind=min;
	for(int i =min; i<max;i++){
		if(T[i]>T[maxind])maxind=i;
	}
	return maxind;
}
void tri_selection(int min, int max){
	for(int i = 0; i<max-min; i++){
		echange(indice_du_plus_grand(min, max-i), max-i-1);
		//disp();
	}
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
	//disp(min,max);
	//séparation en deux sous-tableaux et tri
	int mil = (min+max)/2;
	tri_fusion(min,mil);
	tri_fusion(mil,max);
	
	//FUUUUUUUUUUSION
	int i,c1=0,c2=0;
	int temptab[N];
	for(i = min; i<max; i++){
	if(T[min+c1]<T[mil+c2] && min+c1<mil){
		temptab[i] = T[min+c1];
		c1++;
	}else{
		temptab[i] = T[mil+c2];
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
	
	
	/*init();
	//disp();
	write_text("selection...");writeln();
	t3=clock();
	tri_selection(0,N);
	t4=clock();
	printf("Temps ecoule selection : %lf\n", (double)(t4-t3)/(double)CLOCKS_PER_SEC);
	//disp();*/
	wait_escape();
}
