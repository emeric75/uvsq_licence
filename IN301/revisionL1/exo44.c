#include "stdio.h"
#include "stdlib.h"

#define N 10

void print_tab(int T[]){
	for(int i = 0; i<N; i++){
		printf("%d ", T[i]);
	}
	printf("\n");
}

void all_1(int T[]){
	for(int i = 0; i<N; i++){
		T[i] = 1;
	}
}

int min_tab(int T[]){
	int min = T[1];
	for(int i = 0; i<N; i++){
		if(T[i]<min) min = T[i];
	}
	return min;
}

void one_right(int T[]){
	for(int i = 0; i<N-1; i++){
		T[i+1]=T[i];
	}
	T[0] = 0;
}

void insert_trie(int T[], int add){
	one_right(T);
	T[0] = add;
	int i = 0, temp;
	while(T[i] > T[i+1]){
		temp = T[i+1];
		T[i+1] = T[i];
		T[i] = temp;
	}
}
void no_double(int T[]){
	/*int found[100] = [0];
	int nb_found = 0, is_found;*/
	for(int i = 0; i<N;i++){
		/*is_found = 0 
		for(int j=0; j< nb_found; j++){
			if(T[i] == found[j]){T[i] = -T[i]; is_found=1;}
		}
		if(!is_found){found[nb_found] = T[i]; nb_found++;}*/
		for(int j = i+1; j<N; j++){
			if(T[j] == T[i] && T[i]>0) T[j]=-T[j];
		}
	}
}
int main(){
	int T[N];
	all_1(T);
	print_tab(T);
	printf("%d\n", min_tab(T));
	one_right(T);
	print_tab(T);
	no_double(T);
	print_tab(T);
}
