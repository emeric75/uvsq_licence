#include <stdio.h>
#include <stdlib.h>
int mystrlen(char* s){
	int len = 0;
	while(s[len] != '\0') len++;
	return len;
}
int main(int argc, char **argv){
	if(argc == 1) {printf("You must provide at least one file\n"); exit(1);}
	int count,nl,max_argvlen=0;
	char c;
	for(int i = 1; i<argc; i++){
		if(mystrlen(argv[i]) > max_argvlen)
			max_argvlen = mystrlen(argv[i]);
	}
	for(int i = 1; i<argc; i++){
		FILE *f = fopen(argv[i], "r");
		if(f != NULL){
			count = 0;
			nl = 0;
			while((c=fgetc(f)) != EOF){
				if(c == '\n') nl++;
				count++;
			}
			printf("%*s  : %5d %6d\n", max_argvlen, argv[i], nl, count);
			fclose(f);
		}else{
			printf("Error reading %s\n", argv[i]);
			exit(1);
		}
	}
}
