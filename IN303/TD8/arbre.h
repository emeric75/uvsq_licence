struct abr{
	int racine;
	struct abr* fg;
	struct abr* fd;
};
typedef struct abr ABR;
ABR* arbre_vide();
int est_vide(ABR *);
ABR* feuille(int);
void lib_abr(ABR *);
ABR* inserer_abr(ABR*, int);
void aff_abr(ABR *);
int hauteur_abr(ABR *);
int est_equilibre(ABR *);
ABR *supprimer_abr(ABR *a, int val);


struct elemfabr{
	ABR* elem;
	struct elemfabr *prec;
	struct elemfabr *suiv;
};
struct fabr{
	struct elemfabr *deb;
	struct elemfabr *fin;
};
typedef struct fabr FABR;
FABR file_vide();
int est_vide_fabr(FABR);
FABR enfile(FABR,ABR*);
ABR *defile(FABR*);
