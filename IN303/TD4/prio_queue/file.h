#ifndef FILE_H
#define FILE_H
struct elem{
	int val;
	int prio;
	struct elem* suiv;
	struct elem* prev;
};
typedef struct elem ELEM;

struct my_queue{
	struct elem* deb;
	struct elem* fin;
};
typedef struct my_queue DEQUE;
typedef struct my_queue PRIO_QUEUE;
void creer_queue(DEQUE **);
int is_empty_queue(DEQUE *);
void enqueue(DEQUE**,int);
ELEM* dequeue(DEQUE**);
void aff_queue(DEQUE*);
void free_queue(ELEM*);
void free_deque(DEQUE*);
#endif
