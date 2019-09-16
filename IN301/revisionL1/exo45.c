#include "stdio.h"
#include "stdlib.h"
#include <uvsqgraphics.h>
#define N 1000

void print_tab(int T[],int n ){
	for(int i =0; i<n; i++){
		printf("%d ", T[i]);
	}
	printf("\n");
}

int main(){
	int T[N];
	for(int i = 0; i<N; i++){
		T[i] = alea_int(100);
	}
	int found[N], nb_found = 0,is_found; 
	for(int i = 0; i<N; i++){
		is_found = 0;
		for(int j = 0; j<nb_found; j++){
			if(found[j] == T[i]) is_found = 1;
		}
		if(!is_found){found[nb_found] = T[i]; nb_found++;}
	}
	printf("Valeurs differentes : %d\n", nb_found);
	int modulo[10];
	for(int i = 0; i<N; i++){
		modulo[T[i]%10]++;
	}
	print_tab(modulo,10);
}
