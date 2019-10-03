#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tab{
	int N;
	int *T
} TAB;


int * alloue(char *filename, int N){
	int *T = malloc(N * sizeof(int));
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
		if(ok){*(T+n) = atoi(s); n++;}
	}
	return T;
}

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

int indmaxtab(int *T, int k, int N){
	if(k<0 || k>N-1) {printf("maxtab : error in argument k\n"); exit(1);}
	int max = *T, indmax = 0;
	for(int *p = T+1; p<T+k; p++){
		if(*p>max){max = *p; indmax = p-T;}
	}
	return indmax;
}

void step_sort(int *T, int k, int N){
	if(k<0 || k>N-1) {printf("step_sort : error in the choice of k\n");exit(1);}
	int m = indmaxtab(T,k,N), temp;
	temp = *(T+m);
	*(T+m) = *(T+k);
	*(T+k) = temp;
}

void sort(int *T, int N){
	for(int i = N-1; i>-1; i--){
		step_sort(T,i,N);
	}
}

void printtab(int *T, int N){
	for(int *p = T; p < T+N; p++){
		printf("%d ", *p);
	}
	printf("\n");
}

int main(int argc, char **argv){
	if(argc < 2){printf("You must provide a file\n"); exit(1);}
	if(argc > 2){printf("You provided too many files\n"); exit(1);}
	int N = nb_entiers(argv[1]);
	printf("nb_entiers %s : %d\n", argv[1], N);
	int *T = alloue(argv[1], N);
	printtab(T,N);
	sort(T,N);
	printtab(T,N);
	exit(0);
}
