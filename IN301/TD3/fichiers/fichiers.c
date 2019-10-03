#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int nb_entiers(char *filename){
	FILE *f = fopen(filename, "r");
	if(f == NULL) {printf("Error opening %s\n", filename); exit(1);}
	char s[12];
	int n=0;
	while(fscanf(f,"%s",s) != EOF){
		int i = 0, ok = 1;
		while(s[i] != '\0'){
			if(!isdigit(s[i])){ok = 0; break;}
			i++;
		}
		if(ok) n++;
	}
	return n;
}

int main(int argc, char **argv){
	if(argc < 2){printf("You must provide a file\n"); exit(1);}
	if(argc > 2){printf("You provided too many files\n"); exit(1);}
	printf("nb_entiers %s : %d\n", argv[1], nb_entiers(argv[1]));
	exit(0);
}
