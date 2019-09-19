#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int T[NMAX];
int n;
void lire(){
	FILE *f = fopen(NOMFIC, "r");
	if(f != NULL){
		int i = 0;
		while(i < NMAX && fscanf(f, "%6d\n", &(T[i])) != EOF)
			i++;
		n = i;
	}else{
		fprintf(stderr, "erreur ouverture fichier");
		exit(1);
	}
	fclose(f);
}

void tab_to_file(){
	FILE *f = fopen("nombres-verif.data", "w");
	if(f != NULL){
		int i = 0;
		while(i < n){
			fprintf(f, "%6d\n", T[i]);
			i++;
		}
	}else{
		fprintf(stderr, "erreur ouverture fichier");
		exit(1);
	}
	fclose(f);
}
int recherche(int x){
	int i = 0;
	while(i < NMAX && T[i] != EOF && T[i] != x)
		i++;
	if(T[i] == x){
		fprintf(stderr, "1  nb_comp=%d\n", i+1);
		return 1;
	}else{
		fprintf(stderr, "0  nb_comp=%d\n", i+1);
		return 0;
	}
}

int stat_recherche(int x){
	int i = 0;
	while(i < NMAX && T[i] != EOF && T[i] != x)
		i++;
	if(T[i] == x){
		return i+1;
	}else{
		return i+1;
	}
}
int main(){
	lire();
	tab_to_file();
	int nb_comp = 0, moy;
	srand(getpid());
	for(int i = 0; i<N; i++){
		nb_comp += stat_recherche(rand() % 5*MAX);
	}
	moy = nb_comp/N;
	printf("Moyenne comp = %d\n", moy);
}
