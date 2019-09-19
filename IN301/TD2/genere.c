#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void ecrire(){
	FILE *f = fopen(NOMFIC, "w");
	srand(getpid());
	if(f != NULL){
		for(int i = 0; i<N; i++){
			fprintf(f, "%6d\n", rand()%MAX);
		}
	}else{
		fprintf(stderr, "erreur ouverture fichier");
		exit(1);
	}
	fclose(f);
}

int main(){
	ecrire();
}
