#include "stdio.h"
#include "stdlib.h"

int main(){
	int a,b,c=0;
	scanf("%d %d", &a, &b);
	printf("  %d x %d\n", a, b);
	while(a > 1){
		if(a%2 == 1){
			c = c+b;
			a--;
		}else{
			a = a/2;
			b = 2*b;
		}
		if(c){
			printf("= %d x %d + %d\n",a,b,c);
		}else{
			printf("= %d x %d\n",a,b);
		}
	}
	printf("= %d\n",b+c);
}
