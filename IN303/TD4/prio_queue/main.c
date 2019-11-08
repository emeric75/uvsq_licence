#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include "file_prio.h"
int main(){
	DEQUE *q=NULL; 
	ELEM *e;
	PRIO_QUEUE *pq=NULL;
	creer_queue(&q);
	for(int i = 0; i < 25; i++){
		enqueue(&q,i);
	}
	aff_queue(q);
	aff_queue(q);
	for(int i = 0; i < 25; i++){
		e = dequeue(&q);
		printf("dequeued %d\n", e->val);
		free(e);
	}
	creer_queue(&pq);
	enqueue_prio(&pq,15,1);
	enqueue_prio(&pq,27,2);
	aff_queue(pq);
	enqueue_prio(&pq,42,2);
	aff_queue(pq);
	enqueue_prio(&pq,4,7);
	aff_queue(pq);
	while(!is_empty_queue(pq)){
		e = dequeue(&pq);
		if(e){
			printf("dequeued %d / prio %d\n", e->val, e->prio);
			free(e);
		}
	}
	free_deque(q);
	free_deque(pq);
	exit(0);
}
