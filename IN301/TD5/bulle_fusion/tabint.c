#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned long long int NB_COMP_FUS = 0;

// #####
// 1. Génération, suppression et affichage de tableaux
// #####
TABINT gen_alea_tabint (int N, int K) {
	TABINT T;
	srand(getpid());
	T.N =N;
	T.T = malloc(N*sizeof(int));
	if(T.T == NULL){printf("error allocating memory\n"); exit(1);}
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

void fusionner(TABINT T, int g, int m, int d){
	TABINT T3 = gen_alea_tabint(d-g+1,0);
	int indg=g, indd=m+1;
	for(int i = 0; i<d-g+1; i++){
		if(indg == m+1){
			(T3.T)[i] = (T.T)[indd];
			indd++;
		}else if(indd == d+1){
			(T3.T)[i] = (T.T)[indg];
			indg++;
		}else{
			if((T.T)[indg]<(T.T)[indd]){
				(T3.T)[i] = (T.T)[indg];
				indg++;
			}else{
				(T3.T)[i] = (T.T)[indd];
				indd++;
			}
			NB_COMP_FUS++;
		}
	}
	for(int i = 0; i<d-g+1; i++){
		(T.T)[g+i] = (T3.T)[i];
	}
	sup_tabint(T3);
}
