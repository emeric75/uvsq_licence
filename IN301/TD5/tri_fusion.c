#include "stat.h"
#include "tabint.h"
#include <stdio.h>
#include <stdlib.h>


void tri_fusion_tabint(TABINT T, int g, int d){
	if(g<d){
		int m = (g+d)/2;
		tri_fusion_tabint(T,g,m);
		tri_fusion_tabint(T,m+1,d);
		fusionner(T,g,m,d);
		//aff_tabint(T);
	}
}

struct stat stat_moy(int N, int A){
	struct stat out = {0,0};
	TABINT T;
	for(int i = 0; i<A; i++){
		T = gen_alea_tabint(N,10000);
		tri_fusion_tabint(T,0,N-1);
		out.nb_moy_comp += NB_COMP_FUS;
		NB_COMP_FUS = 0;
		sup_tabint(T);
	}
	out.nb_moy_comp = out.nb_moy_comp/A;
	return out;
}

int main(){
	struct stat s;

	FILE *f = fopen("test_tri_fusion.data","w");
	if(f == NULL){printf("error opening test_tri_fusion.data\n"); exit(1);}
	/*TABINT T = gen_alea_tabint(10000,10000);
	tri_fusion_tabint(T,0,9999);
	printf("Nb comp fus : %lld\n", NB_COMP_FUS global var);*/
	for(int N = 10; N<1000; N=N*12/10){
		s = stat_moy(N,10000);
		printf("taille ");
		fprintf(f,"%d %f\n",N,s.nb_moy_comp);
		printf("%d %f\n",N,s.nb_moy_comp);
	}
	fclose(f);
}
