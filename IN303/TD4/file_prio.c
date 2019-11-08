#include "file.h"
#include <stdlib.h>
void enqueue_prio(PRIO_QUEUE **pq, int val, int prio){
	ELEM *tmp = malloc(sizeof(ELEM));
	if(tmp == NULL) exit(15);
	tmp->val = val;
	tmp->prio = prio;
	if(is_empty_queue(*pq)){
		tmp->suiv = (*pq)->deb;
		tmp->prev = NULL;
		(*pq)->fin = (*pq)->deb = tmp;
		return;
	}
	if(prio < (*pq)->deb->prio){
		tmp->suiv = (*pq)->deb;
		tmp->prev = NULL;
		(*pq)->deb->prev = tmp;
		(*pq)->deb = tmp;
		return;
	}
	PRIO_QUEUE *find = *pq;
	while((find->deb)->suiv && (find->deb)->prio < prio){
		find->deb = (find->deb)->suiv;
	}
	printf("ok val: %d prio: %d\n",find->deb->val,find->deb->prio);
	ELEM *next = find->deb->suiv;
	find->deb->suiv = tmp;
	tmp->suiv = next;
	if(next) next->prev = tmp;
	tmp->prev = find->deb;
}
