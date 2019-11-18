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
int tas_tab_est_vide(TAS_TAB t){
	if(t.N == 1) return 1;
	return 0;
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
//facile à écrire : pas optimisé O(nlogn)
/*ELEM get_most_prio(TAS_TAB *t){
	if(t->N < 2){printf("get_most_prio : empty heap\n"); exit(1);}
	ELEM max = t->tab[1];
	t->tab[1] = t->tab[t->N-1];
	t->N--;
	*t=tasser_tab(*t);
	return max;
}*/
//O(logn)
ELEM get_most_prio(TAS_TAB *t){
	if(tas_tab_est_vide(*t)){printf("get_most_prio : empty heap\n"); exit(1);}
	ELEM max = t->tab[1];
	t->tab[1] = t->tab[t->N-1];
	t->N--;
	int i = 1;
	ELEM temp;
	while((2*i+1 < t->N && t->tab[i].prio < t->tab[2*i+1].prio) ||
		(2*i < t->N && t->tab[i].prio < t->tab[2*i].prio) ){
		if(2*i+1< t->N && t->tab[2*i].prio < t->tab[2*i+1].prio){
			temp = t->tab[i];
			t->tab[i] = t->tab[2*i+1];
			t->tab[2*i+1] = temp;
			i = 2*i+1;
		}else{
			temp = t->tab[i];
			t->tab[i] = t->tab[2*i];
			t->tab[2*i] = temp;
			i *= 2;
		}
	}
	return max;
}
