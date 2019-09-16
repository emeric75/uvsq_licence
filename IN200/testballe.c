#include <uvsqgraphics.h>
#include <math.h>
void affiche(int a, int b){
	write_int(a); write_text(" ");
	write_int(b); write_text(" ");
	writeln();
}
void h(int a, int *b)
{
*b = *b + 1;
a = a + 1;
}
int main()
{
	init_graphics(400,400);
	int a,b;
	a = 5; b = 10;
	h(b,&a);
	affiche(a,b);
}
