#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	
	int a,b;
	
	a = (10/3)*3;
	b = (10*3)/3;
	
	write_int(a);
	writeln();
	write_int(b);
	
	wait_escape();
	exit(0);
}
