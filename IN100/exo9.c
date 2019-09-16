#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);
	
	int a,b,c,d,e,f;
	
	a=47;
	b=152;
	c=3;
	
	d=a-b-c;
	e=(a-b)-c;
	f=a-(b-c);
	
	write_int(d);
	writeln();
	write_int(e);
	writeln();
	write_int(f);
	//d=e, et d!=f, la soustraction est associative uniquement de G à D
	
	wait_escape();
	exit(0);
}
