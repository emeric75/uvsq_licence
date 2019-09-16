//FILE IO
#include <stdio.h>
#include "struct.c"
NIVEAU read_level(char* name){
	FILE* f = fopen(name,"r");
	NIVEAU out;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			fscanf(f,"%c",&(out.grille[i][j])); 
		}
		fscanf(f,"\n");
	}
	fclose(f);
	return out;
}

/*void write_level(NIVEAU n, char* name){
	
}*/
