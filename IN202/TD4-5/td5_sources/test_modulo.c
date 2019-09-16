#include <stdio.h>
#include <math.h>

int modulo(int a, int b){
	return (a<0) ? ((a-b*floor(a/b) + b==b) ? 0 : a-b*floor(a/b) + b) : a-b*floor(a/b);
}

int main(){
	int a,b;
	char c,d;
	scanf("%d%d",&a,&b);
	scanf("%c %c",&c,&d);
	
	printf("%d %d #%c#%c#",a,b,c,d);
	
}
