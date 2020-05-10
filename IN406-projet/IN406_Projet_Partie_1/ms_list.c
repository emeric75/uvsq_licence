#include <stdio.h>
#include <stdlib.h>
#include "ms_list.h"
MS_LIST* ms_list_init(){
	return NULL;
}
void ms_list_lib(MS_LIST *ms_list){
	if(ms_list){
		ms_list_lib(ms_list->suiv);
		if(ms_list->ms.multi_state){
			free(ms_list->ms.multi_state);
			//ms_list->ms.multi_state = NULL;
		}
		free(ms_list);
	}
}
MS_LIST* ms_list_append(MS_LIST* ms_list, int *multi_state, int nb_states){
	MS_LIST *nv = malloc(sizeof(MS_LIST));
	if(!nv){ printf("erreur allocation\n"); exit(1); }
	nv->ms.id_state_det = (ms_list == NULL) ? 0 : ms_list->ms.id_state_det+1;
	nv->ms.multi_state = multi_state;
	nv->ms.nb_states = nb_states;
	nv->suiv = ms_list;
	return nv;
}
MULTI_STATE ms_list_pop(MS_LIST** ms_list){
	if(ms_list){
		MS_LIST *to_del = *ms_list;
		MULTI_STATE to_return = (*ms_list)->ms;
		*ms_list = (*ms_list)->suiv;
		free(to_del);
		return to_return;
	}else{
		printf("multi_state_pop : tried popping empty list\n");
		exit(1);
	}
		
}
int ms_list_find(MS_LIST *ms_list, int *multi_state, int nb_states){
	if(ms_list == NULL) return -1;
	MULTI_STATE ms = ms_list->ms;
	if(nb_states == ms.nb_states){
		if(check_equal(multi_state, ms.multi_state,nb_states))
			return ms.id_state_det;
	}
	return ms_list_find(ms_list->suiv,multi_state,nb_states);
}
int check_equal(int *l1, int *l2, int length){
	for(int i = 0; i<length; i++)
		if(l1[i] != l2[i]) return 0;
	return 1;
}
int not_zero(int *tab, int l){
	int *test = calloc(l,sizeof(int));
	int res = check_equal(tab,test,l);
	free(test);
	return (res) ? 0 : 1;
}
