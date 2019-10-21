#ifndef LISTEH
#define LISTEH
typedef struct liste
{
	int val;
	struct liste* suiv;
} LISTE;

void libere_memoire(LISTE*);

LISTE *inserer_deb(LISTE*,int);
void inserer_deb2(LISTE**,int);

LISTE *supprimer_deb(LISTE*);
void supprimer_deb2(LISTE**);

void affiche_iter(LISTE*);
void affiche_rec(LISTE*);

int length_iter(LISTE*);
int length_rec(LISTE*);

int is_present_iter(LISTE*,int);
int is_present_rec(LISTE*,int);

LISTE *inserer_fin_iter(LISTE*,int);
LISTE *inserer_fin_rec(LISTE*,int);

LISTE *supprimer_fin_iter(LISTE*);
LISTE *supprimer_fin_rec(LISTE*);
#endif
