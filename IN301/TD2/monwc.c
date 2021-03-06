#include <stdio.h>
#include <stdlib.h>

int mystrlen(char* s){
	int len = 0;
	while(s[len] != '\0') len++;
	return len;
}

int main(int argc, char **argv){
	if(argc == 1) {printf("You must provide at least one file\n"); exit(1);}
	int count,nl,words,a_iswhite = 2,iswhite,max_argvlen=0;
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
			words = 0;
			while(fscanf(f, "%c", &c) != EOF){
				if(c == '\n' || c == '\t' || c == ' ' || c == '\r' || c == EOF){
					a_iswhite = iswhite;
					iswhite = 1;
				}else{
					a_iswhite = iswhite;
					iswhite = 0;
				}
				if(a_iswhite == 0 && iswhite == 1)
					words++;
				if(iswhite){
					count++;
					if(c == '\n') nl++;
				}else{
					count++;
				}
			}
			printf("%*s  : %5d %5d %6d\n", max_argvlen, argv[i], nl, words,count);
			fclose(f);
		}else{
			printf("Error reading %s\n", argv[i]);
			exit(1);
		}
	}
}
