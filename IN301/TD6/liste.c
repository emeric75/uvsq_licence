#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void libere_memoire(LISTE *l){
	if(l){
		libere_memoire(l->suiv);
		free(l);
	}
}

LISTE *inserer_deb (LISTE *l, int val){
	LISTE *nouv = malloc(sizeof(LISTE));
	if(!nouv){printf("erreur allocation mémoire"); exit(1);}
	nouv->suiv = l;
	nouv->val = val;
	return nouv;
}
void inserer_deb2 (LISTE **l, int val){
	LISTE *nouv = malloc(sizeof(LISTE));
	if(!nouv){printf("erreur allocation mémoire"); exit(1);}
	nouv->suiv = *l;
	nouv->val = val;
	*l = nouv;
}
LISTE *supprimer_deb(LISTE *l){
	if(!l) return NULL;
	LISTE *to_del = l;
	l = l->suiv;
	free(to_del);
	return l;
}
void supprimer_deb2(LISTE **l){
	if(!(*l)) return;
	LISTE *to_del = *l;
	*l = (*l)->suiv;
	free(to_del);
}
void affiche_iter(LISTE *l){
	while(l){
		printf("%d ",l->val);
		l = l->suiv;
	}
	printf("\n");
}
void affiche_rec(LISTE *l){
	if(!l){printf("\n"); return;}
	printf("%d ",l->val);
	affiche_rec(l->suiv);
}
int length_iter(LISTE *l){
	int length=0;
	while(l){
		length++;
		l=l->suiv;
	}
	return length;
}
int length_rec(LISTE *l){
	if(!l) return 0;
	return 1 + length_rec(l->suiv);
}
int is_present_iter(LISTE *l, int val){
	int ok = 0;
	while(l){
		if(l->val == val){ok = 1; break;}
		l=l->suiv;
	}
	return ok;
}
int is_present_rec(LISTE *l, int val){
	if(!l) return 0;
	if(l->val == val) return 1;
	return is_present_rec(l->suiv, val);
}
LISTE *inserer_fin_iter(LISTE *l, int val){
	LISTE *end_ptr = l;
	while(end_ptr->suiv != NULL){
		end_ptr = end_ptr->suiv;
	}
	LISTE *nouv = malloc(sizeof(LISTE));
	if(!nouv){printf("erreur allocation mémoire"); exit(1);}
	nouv->val = val;
	nouv->suiv = NULL;
	end_ptr->suiv = nouv;
	return l;
}
LISTE *inserer_fin_rec(LISTE *l, int val){
	if(!l){
		l=malloc(sizeof(LISTE));
		if(!l){printf("erreur allocation mémoire"); exit(1);}
		l->val = val;
		l->suiv = NULL;
		return l;
	}
	l->suiv = inserer_fin_rec(l->suiv,val);
	return l;
}
LISTE *supprimer_fin_iter(LISTE *l){
	LISTE *end_ptr = l;
	if(!l || !(l->suiv)) return NULL;
	while((end_ptr->suiv)->suiv){
		end_ptr = end_ptr->suiv;
	}
	LISTE *to_del = end_ptr->suiv;
	end_ptr->suiv = NULL;
	free(to_del);
	return l;
}
LISTE *supprimer_fin_rec(LISTE *l){
	if(!l || !(l->suiv)) return NULL;
	if((l->suiv)->suiv == NULL){free(l->suiv); l->suiv = NULL; return l;}
	l->suiv = supprimer_fin_rec(l->suiv);
	return l;
}

LISTE* supprimer_mil_iter(LISTE *l, int val){
	LISTE *ptr = l
	while(ptr->suiv != NULL && (ptr->suiv)->val != val){
		ptr = ptr->suiv;
	}
	if((ptr->suiv)->val == val){
		
	}
	return l;
}
