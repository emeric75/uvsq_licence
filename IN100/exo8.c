#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	
	int a,b,c,d;
	
	a=157;
	b=42;
	c=a/b;
	d=a%b;
	//a = b*c+d
	wait_escape();
	exit(0);
}
