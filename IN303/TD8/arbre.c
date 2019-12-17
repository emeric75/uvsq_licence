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
		//prefixe
		printf("%d\n",a->racine);
		aff_abr(a->fg);
		//infixe
		aff_abr(a->fd);
		//postfixe
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
				free(temp);
				return a;
			}else if(!a->fd){
				temp = a;
				a = a->fg;
				free(temp);
				return a;
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
ABR *rot_droite(ABR *a){
	if(!a || !a->fg) return a;
	int x = a->fg->racine;
	int y = a->racine;
	ABR *a1 = a->fg->fg;
	ABR *a2 = a->fg->fd;
	ABR *a3 = a->fd;
	ABR *res = feuille(x);
	res->fd = feuille(y);
	res->fg = a1; res->fd->fg = a2; res->fd->fd = a3;
	return res;	
}
ABR *rot_gauche(ABR *a){
	if(!a || !a->fd) return a;
	int x = a->racine;
	int y = a->fd->racine;
	ABR *a1 = a->fg;
	ABR *a2 = a->fd->fg;
	ABR *a3 = a->fd->fd;
	ABR *res = feuille(y);
	res->fg = feuille(x);
	res->fd = a3; res->fg->fg = a1; res->fg->fd = a2;
	return res;	
}
ABR *equilibre(ABR *a){
	if(!est_equilibre(a)){
		int hg = hauteur_abr(a->fg);
		int hd = hauteur_abr(a->fd);
		a->fg = equilibre(a->fg);
		a->fd = equilibre(a->fd);
		if(hg > hd+1){ //rot d
			if(hauteur_abr(a->fg->fd) > hauteur_abr(a->fg->fg))
				a->fg = rot_droite(a->fg);
			a=rot_droite(a);
		}else if(hd > hg+1){ //rot g
			if(hauteur_abr(a->fd->fg) > hauteur_abr(a->fd->fd))
				a->fd = rot_droite(a->fd);
			a=rot_gauche(a);
		}
		a=equilibre(a);
	}else return a;
}
