#include "stdio.h"
#include "stdlib.h"

int main(){
	int n = 0, u_n;
	printf("u_0 = ?");
	scanf("%d", &u_n);
	while(u_n != 1){
		if(u_n%2) u_n = 3*u_n+1;
		else u_n = u_n/2;
		//printf("%d\n", u_n);

		n++;
	}
	printf("%d\n",n);
}
