#include "liste.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	srand(getpid());
	LISTE *l = rand_liste(15,1000);
	affiche_rec(l);
	l=tri_bulle(l);
	affiche_rec(l);
	libere_memoire(l);
	exit(0);
}
