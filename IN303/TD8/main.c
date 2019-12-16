#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
int main(){
	ABR *a = arbre_vide();
	//printf("%d\n",est_vide(a));
	lib_abr(a);
	ABR *b = feuille(12);
	b = inserer_abr(b,4);
	b = inserer_abr(b,42);
	b = inserer_abr(b,17);
	b = inserer_abr(b,10);
	aff_abr(b);
	printf("%d\n",hauteur_abr(b));
	printf("est_equilibre(b) ? %d\n",est_equilibre(b));
	b = supprimer_abr(b,12);
	aff_abr(b);
	//parcours_largeur(b);
	lib_abr(b);
}
