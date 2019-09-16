#include <stdio.h>
#include <stdlib.h>

typedef struct niveau {char grille[15][15];}NIVEAU;

NIVEAU read_level(char *name){
	FILE* f = fopen(name,"r");
	if(f == NULL) exit(EXIT_FAILURE);
	NIVEAU out;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			fscanf(f,"%c",&(out.grille[i][j])); 
		}
		fscanf(f,"\n");
	}
	fclose(f);
	printf("chargement lvl ok\n");
	return out;
}
void aff_level(NIVEAU level){
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			printf("%c",level.grille[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char *argv[]){
	NIVEAU level;
	level = read_level("1.lvl");
	
	aff_level(level);
	
	exit(EXIT_SUCCESS);
}
