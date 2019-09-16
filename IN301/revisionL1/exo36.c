#include "stdio.h"
#include "stdlib.h"

#define EPS 0.00001

int main(){
	int n = 0;
	float S_np1 = 1.0f, S_n = 0.0f;
	while(S_np1-S_n >= EPS){
		n++;
		S_n = S_np1;
		S_np1 += 1.0f/((n+1)*(n+1));
	}
	printf("Approx limite : S_%d = %f\n", n, S_n);
}
