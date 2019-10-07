#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// #####
// 1. Génération, suppression et affichage de tableaux
// #####
TABINT gen_alea_tabint (int N, int K) {
	TABINT T;
	srand(getpid());
	T.N =N;
	T.T = malloc(N*sizeof(int));
	if(T.T == NULL){printf("error allocating memory"); exit(1);}
	for(int *p = T.T; p<T.T+T.N; p++) *p = rand()%(K+1);
	return T;
}

TABINT sup_tabint (TABINT T) {
	free(T.T);
	return T;
}

void aff_tabint (TABINT T) {
	for(int *p = T.T; p<T.T+T.N; p++){
		printf("%d ",*p);
	}
	printf("\n");
}

// #####
// 2. Manipulation des valeurs du tableau
// #####

// Echange la case i et la case i+1 si la case i est > à la case i+1
struct test ech_tabint (TABINT T, int i, struct test t) {
	int temp;
	if(*(T.T+i) > *(T.T+i+1)){
		temp = *(T.T+i);
		*(T.T+i) = *(T.T+i+1);
		*(T.T+i+1) = temp;
		t.nb_ech++;
	}
	t.nb_comp++;
	return t;
}


struct test scan_ech_tabint (TABINT T, int fin)  {
	struct test t = {0,0};
	for(int i = 0; i<fin; i++){
		t = ech_tabint(T,i,t);
	}
	return t;
}
