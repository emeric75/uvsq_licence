#ifndef LISTEH
#define LISTEH
typedef struct liste
{
	int val;
	struct liste* suiv;
} LISTE;

void libere_memoire(LISTE*);

LISTE *creer_liste();
LISTE *rand_liste(int,int);

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

LISTE *supprimer_mil_iter(LISTE*,int);
LISTE *supprimer_mil_rec(LISTE*,int);

LISTE *inserer_trie_iter(LISTE*,int);
LISTE *inserer_trie_rec(LISTE*,int);

LISTE *retourner(LISTE*);

LISTE *concat(LISTE*,LISTE*);

LISTE *fusion(LISTE*,LISTE*);

LISTE *uniq(LISTE*);

LISTE *echange(LISTE*);

LISTE *tri_bulle(LISTE*);
#endif
