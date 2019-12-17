#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
int main(){
	ABR *a = arbre_vide();
	//printf("%d\n",est_vide(a));
	lib_abr(a);
	ABR *b = arbre_vide();
	for(int i = 1; i < 17; i++){
		b=inserer_abr(b,i);
	}
	aff_abr(b);
	b=equilibre(b);
	aff_abr(b);
	printf("est_equilibre(b) ? %d\n",est_equilibre(b));
	printf("%d\n",hauteur_abr(b));
	lib_abr(b);
}
