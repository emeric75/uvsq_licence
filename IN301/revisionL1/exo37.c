#include "stdio.h"
#include "stdlib.h"

int main(){
	int test,div = 2;
	printf("Entrez un nombre entier : ");
	scanf("%d", &test);
	while(div<test){
		if(test%div){div++;}
		else {printf("NON PREMIER\n"); exit(0);}
	}
	printf("PREMIER\n");
	exit(0);
}
