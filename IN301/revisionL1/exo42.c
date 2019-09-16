#include "stdio.h"
#include "stdlib.h"
#include <math.h>
float f(int n){
	if (n==1) return 1;
	else return sqrt(f(n-1)+sqrt(n));
}
int main(){
	int N;
	printf("N=? ");
	scanf("%d", &N);
	for(int i = 1; i<=N; i++){
		printf("%f\n", f(i));
	}
}
