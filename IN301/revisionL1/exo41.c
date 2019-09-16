#include "stdio.h"
#include "stdlib.h"

int factorielle(int n){
	int f;
	if(n<=1) return 1;
	else return n*factorielle(n-1);
}

int main(){
	printf("%d\n",factorielle(2));
}
