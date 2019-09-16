#include "stdio.h"
#include "stdlib.h"

int friends(int a, int b){
	int sumdiva = 0, sumdivb=0, div=1;
	while(div < a){
		if(!(a%div)) sumdiva += div;
		div++;
	}
	div = 1;
	while(div < b){
		if(!(b%div)) sumdivb += div;
		div++;
	}
	if(a == sumdivb && b == sumdiva) return 1;
	else return 0;
}


int main(){
	int nmax;
	printf("nmax = ");
	scanf("%d", &nmax);
	for(int i = 1; i<=nmax; i++){
		for(int j=i; j<=nmax; j++){
			if(friends(i,j)) printf("(%d,%d)\n",i,j);
		}
	}
}
