#include <uvsqgraphics.h>

int main () {
	init_graphics(1000,700);

	int a;
	a=7;
	write_int(a);
	//sans valeur définie, write_int affiche 0
	
	wait_escape();
	exit(0);
}
