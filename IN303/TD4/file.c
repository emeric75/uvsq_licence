#include <stdio.h>
#include <stdlib.h>
#include "file.h"
int is_empty_queue(DEQUE *q){
	if(q == NULL || q->fin == NULL || q->deb == NULL)
		return 1;
	return 0;
}
void creer_queue(DEQUE **q){
	*q = malloc(sizeof(DEQUE));
	if(*q == NULL) exit(16);
	(*q)->deb = NULL;
	(*q)->fin = NULL;
}
void enqueue(DEQUE **q, int val){
	ELEM *tmp = malloc(sizeof(ELEM));
	if(tmp == NULL) exit(15);
	if(is_empty_queue(*q)) (*q)->fin = tmp;
	tmp->val = val;
	tmp->suiv = (*q)->deb;
	tmp->prev = NULL;
	if(!is_empty_queue(*q))         (*q)->deb->prev = tmp;
	(*q)->deb = tmp;
}
ELEM* dequeue(DEQUE **q){
	if(is_empty_queue(*q)) return NULL;
	if((*q)->fin->prev == NULL){
		ELEM *to_del = (*q)->deb;
		(*q)->deb = NULL;
		(*q)->fin = NULL;	
		return to_del; 
	}
	ELEM *to_del = (*q)->fin;
	(*q)->fin->prev->suiv = NULL;
	(*q)->fin = (*q)->fin->prev;
	return to_del;
}
void aff_queue(DEQUE q){
	while(q.deb){
		printf("%d ", q.deb->val);
		q.deb = q.deb->suiv;
	}
	printf("\n");
}
void free_queue(ELEM *e){
	if(e != NULL) free_queue(e->suiv);
	free(e);
}
void free_deque(DEQUE *q){
	free_queue(q->deb);
	free(q);
}
