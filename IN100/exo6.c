#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	
	int a,b;
	
	a=10;
	b=a;
	a=a+2;
	
	write_int(a);
	writeln();
	write_int(b);
	
	wait_escape();
	exit(0);
}
