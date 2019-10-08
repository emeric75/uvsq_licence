#ifndef _TABINT_H
#define _TABINT_H
#include "stat.h"

unsigned long long int NB_COMP_FUS;

struct tabint {
    int N;  // Taille du tableau
    int *T; // Pointeur vers le tableau
};
typedef struct tabint TABINT;


TABINT gen_alea_tabint (int N, int K);
TABINT sup_tabint (TABINT T);

void aff_tabint (TABINT T);

struct test ech_tabint (TABINT T, int i, struct test t);
struct test scan_ech_tabint (TABINT T, int fin);
void fusionner (TABINT T, int deb, int mil, int fin);

int verif_si_tableau_croissant (TABINT T);

#endif
