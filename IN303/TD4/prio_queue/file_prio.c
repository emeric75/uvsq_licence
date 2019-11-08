#include "file.h"
#include <stdlib.h>
void enqueue_prio(PRIO_QUEUE **pq, int val, int prio){
	ELEM *tmp = malloc(sizeof(ELEM));
	if(tmp == NULL) exit(15);
	tmp->val = val;
	tmp->prio = prio;
	tmp->suiv = (*pq)->deb;
	tmp->prev = NULL;
	if(is_empty_queue(*pq)){
		(*pq)->fin = (*pq)->deb = tmp;
		return;
	}
	if(prio < (*pq)->deb->prio){
		(*pq)->deb->prev = tmp;
		(*pq)->deb = tmp;
		return;
	}
	ELEM *find = (*pq)->deb;
	while(find->suiv && find->suiv->prio < prio){
		find = find->suiv;
	}
	printf("ok val: %d prio: %d\n",find->val,find->prio);
	ELEM *next = find->suiv;
	find->suiv = tmp;
	tmp->suiv = next;
	if(next) next->prev = tmp;
	if(!next) (*pq)->fin = tmp;
	tmp->prev = find;
}
