#include "tas.h"
#include <stdio.h>
#include <stdlib.h>

#define M 1000
TAS_TAB creer_tas_tab(){
	TAS_TAB t;
	t.N = 1;
	t.MAX = M;
	t.tab = malloc(M * sizeof(ELEM));
	if(t.tab == NULL){printf("error allocating memory"); exit(1);}
	return t;
}
void aff_tas_tab(TAS_TAB t){
	printf("tas: ");
	for(int i = 1; i<t.N; i++){
		printf("%dp%d ",t.tab[i].val,t.tab[i].prio);
	}
	printf("\n");
}
TAS_TAB inserer_elem(TAS_TAB t, int val, int prio){
	if(t.N+1 < M){
		ELEM e;
		e.val = val;
		e.prio = prio;
		t.tab[t.N] = e;
		t=tasser_elem(t,t.N);
		t.N++;
	}else{
		printf("heap full : element not inserted\n");
	}
	return t;
}
TAS_TAB tasser_elem(TAS_TAB t,int ind){
	int to_place = ind; ELEM tmp;
	while(to_place > 1 && t.tab[to_place/2].prio < t.tab[to_place].prio){
		tmp = t.tab[to_place/2];
		t.tab[to_place/2] = t.tab[to_place];
		t.tab[to_place] = tmp;
		to_place /= 2;
	}
	return t;
}
TAS_TAB tasser_tab(TAS_TAB t){
	for(int i = 2; i < t.N; i++){
		t=tasser_elem(t,i);
	}
	return t;
}
ELEM get_most_prio(TAS_TAB *t){
	if(t->N < 2){printf("get_most_prio : empty heap\n"); exit(1);} 
	ELEM max = t->tab[1];
	t->tab[1] = t->tab[t->N-1];
	t->N--;
	*t=tasser_tab(*t);
	return max;
}
