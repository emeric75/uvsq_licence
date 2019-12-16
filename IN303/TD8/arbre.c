#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
ABR *arbre_vide(){
	return NULL;
}
int est_vide(ABR *a){
	return (a==NULL);
}
ABR *feuille(int val){
	ABR *a = malloc(sizeof(ABR));
	a->racine = val;
	a->fd = NULL;
	a->fg = NULL;
	return a;
}
void lib_abr(ABR *a){
	if(a){
		if(a->fg) lib_abr(a->fg);
		if(a->fd) lib_abr(a->fd);
		free(a);
	}
	a=NULL;
}
ABR* inserer_abr(ABR *a, int val){
	if(a){
		if(val <= a->racine){
			a->fg=inserer_abr(a->fg,val);
		}else if(val > a->racine){
			a->fd=inserer_abr(a->fd,val);
		}
		return a;
	}else{
		return feuille(val);
	}
}
void aff_abr(ABR *a){
	if(a){
		aff_abr(a->fg);
		printf("%d\n",a->racine);
		aff_abr(a->fd);
	}
}
int max(int a, int b){
	return (a<b) ? b : a;
}
int hauteur_abr(ABR *a){
	if(a == NULL) return 0;
	return 1 + max(hauteur_abr(a->fg),hauteur_abr(a->fd));
}
int est_equilibre(ABR *a){
	if(a == NULL) return 1;
	return (abs(hauteur_abr(a->fg)-hauteur_abr(a->fd))<2)
	       && est_equilibre(a->fg) && est_equilibre(a->fd);	
}
int max_abr(ABR *a){
	if(!a) {printf("merde\n"); exit(1);}
	while(a->fd != NULL){
		a = a->fd;
	}
	return a->racine;
}
ABR *supprimer_abr(ABR *a, int val){
	if(a){
		ABR *temp;
		if(val == a->racine){
			if(!a->fg){
				temp = a;
				a = a->fd;
				return temp;
			}else if(!a->fd){
				temp = a;
				a = a->fg;
				return temp;
			}else{
				int m = max_abr(a->fg);
				a=supprimer_abr(a,max_abr(a->fg));
				a->racine=m; 
			}
		}else if(val < a->racine){
			a->fg = supprimer_abr(a->fg, val);
		}else{
			a->fd = supprimer_abr(a->fd, val);
		}
	}else{
		return a;
	}
}
FABR file_vide(){
	FABR f;
	f.deb = NULL;
	f.fin = NULL;
	return f;
}
int est_vide_fabr(FABR f){
	return (!(f.deb) && !(f.fin));
}
FABR enfile(FABR f, ABR* a){
	struct elemfabr *e = malloc(sizeof(struct elemfabr));
	e->elem = a;
	if(est_vide_fabr(f)){
		e->prec = e->suiv = NULL;
		f.deb = f.fin = e;
		return f;
	}
	e->prec = f.fin; e->suiv = NULL;
	if(f.fin) f.fin->suiv = e;
	f.fin = e;
	return f;
}
ABR *defile(FABR* f){
	if(est_vide_fabr(*f) || !f) {printf("merde\n"); exit(1);}
	ABR *res = f->deb->elem;
	struct elemfabr *to_del = f->deb;
	f->deb = f->deb->suiv;
	if(f->deb) f->deb->prec = NULL;
	else f->fin = NULL;
	free(to_del);
	return res;
}
void parcours_largeur(ABR *a){
	FABR f = file_vide();
	f = enfile(f,a);
	while(!est_vide_fabr(f)){
		ABR *traiter = defile(&f);
		printf("%d\n",traiter->racine);
		if(!est_vide(traiter->fg)){
			f = enfile(f,traiter->fg);
		}
		if(!est_vide(traiter->fd)){
			f = enfile(f,traiter->fd);
		}
	}
}
