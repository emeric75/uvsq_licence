#include "liste.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
	LISTE *l = NULL;
	l = inserer_deb(l, 12);
	affiche_iter(l);
	inserer_deb2(&l,42);
	inserer_deb2(&l,17);

	printf("%d : ", length_iter(l));
	affiche_rec(l);
	printf("is_present iter/rec : %d %d\n", is_present_iter(l,42), is_present_rec(l,42));

	l=supprimer_deb(l);
	supprimer_deb2(&l);

	printf("%d : ", length_rec(l));
	affiche_rec(l);
	printf("is_present iter/rec : %d %d\n", is_present_iter(l,42), is_present_rec(l,42));

	l=inserer_fin_iter(l,13);
	l=inserer_fin_rec(l,21);
	affiche_rec(l);

	l=supprimer_fin_iter(l);
	affiche_rec(l);

	l=supprimer_fin_rec(l);
	affiche_rec(l);
	l=supprimer_fin_rec(l);
	affiche_rec(l);

	libere_memoire(l);
	exit(0);
}
