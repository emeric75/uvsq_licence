#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>

struct test tri_bulle_tabint(TABINT T){
	struct test partiel, t = {0,0};
	for(int i = T.N-1; i>0; i--){
		partiel = scan_ech_tabint(T,i);
		t.nb_comp += partiel.nb_comp;
		t.nb_ech += partiel.nb_ech;
		//aff_tabint(T);
	}
	return t;
}


struct stat stat_moy(int N, int A){
	struct stat s;
	struct test t;
	struct test total = {0,0};
	TABINT T;
	for(int i = 0; i<A; i++){
		T = gen_alea_tabint(N, 10000);
		t = tri_bulle_tabint(T);
		total.nb_comp += t.nb_comp;
		total.nb_ech  += t.nb_ech;
		sup_tabint(T);
	}
	s.nb_moy_comp = ((float)total.nb_comp)/((float)A);
	s.nb_moy_ech = ((float)total.nb_ech)/((float)A);
	return s;
}

int main() {
	FILE *f = fopen("test_tri_bulle.data","w");
	if(f == NULL){printf("error opening test_tri_bulle.data"); exit(1);}
	struct stat s;
	for(int N = 10; N <= 1000; N = (12*N)/10){
		printf("taille ");
		s = stat_moy(N,10000);
		printf("%d %f %f\n", N, s.nb_moy_comp, s.nb_moy_ech);
		fprintf(f,"%d %f %f\n",N,s.nb_moy_comp,s.nb_moy_ech);
	}
	fclose(f);
	exit(0);
}
