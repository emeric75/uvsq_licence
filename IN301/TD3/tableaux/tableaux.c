#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define LEN 10

int * alloue(){
	int *T;
	T = malloc(LEN * sizeof(int));
	for(int *p = T;  p<T+LEN; p++){
		*p = rand()%21;
	}
	return T;
}

void printtab(int* T){
	for(int *p = T; p<T+LEN; p++){
		printf("%d ", *p);
	}
	printf("\n");
}

int prodtab(int *T){
	int prod = 1;
	for(int *p = T; p<T+LEN; p++){
		prod *= *p;
	}
	return prod;
}

int mintab(int *T){
	int min = *T;
	for(int *p = T+1; p<T+LEN; p++){
		min = (*p < min) ? *p : min;
	}
	return min;
}

void shift_right(int *T, int index){
	for(int *p = T+LEN-1; p>T+index-1; p--){
		*p = *(p-1);
	}
}

int * alloue_inc(){
	int elem=0;
	int *T;
	T = malloc(LEN * sizeof(int));
	for(int *p = T; p<T+LEN; p++){
		*p = (elem = elem + rand()%10);
	}
	return T;
}

void insert_trie(int *T, int x){
	int i = 0;
	while(i < LEN && *(T+i) < x) i++;
	shift_right(T, i);
	*(T+i) = x;
}

void invert(int *T){
	int temp;
	for(int i = 0; i < LEN/2; i++){
		temp = *(T+i);
		*(T+i) = *(T+LEN-1-i);
		*(T+LEN-1-i) = temp;
	}
}

void del_shiftleft(int *T){
	int todel = rand()%10;
	for(int *p = T+todel; p<T+LEN-1; p++){
		*p = *(p+1);
	}
}

int main(){
	srand(getpid());
	int *T;
	int *Tinc;
	T = alloue();
	Tinc = alloue_inc();
	if(T != NULL && Tinc != NULL){
		printf("T : \n");
		printtab(T);
		printf("prod %d\n",prodtab(T));
		printf("min %d \n",mintab(T));
		printf("shift right T\n");
		shift_right(T,0);
		printtab(T);
		printf("del shift left T\n");
		del_shiftleft(T);
		printtab(T);
		printf("invert T\n");
		invert(T);
		printtab(T);

		printf("Tinc : \n");
		printtab(Tinc);
		printf("insert 12 Tinc\n");
		insert_trie(Tinc, 12);
		printtab(Tinc);
	}else{
		printf("problème d'allocation, au revoir");
		exit(1);
	}
	exit(0);
}
