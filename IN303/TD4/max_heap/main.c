#include "tas.h"
#include <stdio.h>
#include <stdlib.h>
struct tab{
	int N;
	int *tab;
};
typedef struct tab TAB;
TAB read_tab(char *fname){
	FILE *f = fopen(fname,"r");
	int ok = 1;
	int val = 0;
	int nb_val = 0;
	do{
		ok=fscanf(f,"%d",&val);
		if(ok != EOF) nb_val++;
	}while(ok != EOF);
	int *tab = malloc(nb_val*sizeof(int));
	if(!tab){printf("error allocating memory\n"); exit(1);}
	rewind(f);
	for(int i = 0; i<nb_val; i++){
		ok = fscanf(f,"%d",&(tab[i]));
	}
	fclose(f);
	TAB t;
	t.N = nb_val;
	t.tab = tab;
	return t;
}
void aff_tab(TAB t){
	for(int i = 0; i<t.N; i++){
		printf("%d ", t.tab[i]);
	}
	printf("\n");
}
int main(int argc, char **argv){
	if(argc < 2){printf("not enough arguments\n"); exit(1);}
	TAB t;
	t = read_tab(argv[1]);
	aff_tab(t);
	TAS_TAB tt = creer_tas_tab();
	for(int i = 0; i<t.N; i++){
		tt=inserer_elem(tt,t.tab[i],t.tab[i]);
	}
	tt = tasser_tab(tt);
	aff_tas_tab(tt);
	for(int i = t.N-1; i>=0; i--){
		ELEM to_ins = get_most_prio(&tt);
		t.tab[i] = to_ins.val;
	}
	aff_tab(t);
	free(t.tab);
	free(tt.tab);
}
