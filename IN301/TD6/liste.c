#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void libere_memoire(LISTE *l){
	if(l){
		libere_memoire(l->suiv);
		free(l);
	}
}


LISTE *creer_liste(){
	return NULL;
}

LISTE *rand_liste(int N, int K){
	LISTE *l = creer_liste();
	for(int i = 0; i<N; i++){
		l=inserer_deb(l, rand()%K );
	}
	return l;
}
/*
*
*
FONCTIONS DE BASE
Insertion, suppression, affichage, longueur, recherche
*
*
*/



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
	if(!l) return NULL;
	if(l->val == val) return l->suiv;
	LISTE *ptr = l;
	while(ptr->suiv != NULL && (ptr->suiv)->val != val){
		ptr = ptr->suiv;
	}
	if(ptr->suiv != NULL && (ptr->suiv)->val == val){
		LISTE *tmp = ptr->suiv;
		ptr->suiv = (ptr->suiv)->suiv;
		free(tmp);
	}
	return l;
}
LISTE *supprimer_mil_rec(LISTE *l, int val){
	if(!l) return NULL;
	if(l->val == val) return l->suiv;
	if((l->suiv)->val == val){
		LISTE *tmp = l->suiv;
		l->suiv = (l->suiv)->suiv;
		free(tmp);
		return l;
	}
	l->suiv = supprimer_mil_rec(l->suiv,val);
	return l;
}

LISTE *inserer_trie_iter(LISTE *l, int val){
	LISTE *e = malloc(sizeof(LISTE));
	e->val = val;
	if(!l){
		e->suiv = NULL;
		return e;
	}
	if(val < l->val){
		e->suiv = l;
		return e;
	}
	LISTE *ins_ptr = l;
	while(ins_ptr->suiv != NULL && (ins_ptr->suiv)->val < val){
		ins_ptr = ins_ptr->suiv;
	}
	e->suiv = ins_ptr->suiv;
	ins_ptr->suiv = e;
	return l;
}

LISTE *inserer_trie_rec(LISTE *l, int val){
	if(!l){
		LISTE *e = malloc(sizeof(LISTE));
		e->val = val;
		e->suiv = NULL;
		return e;
	}
	if(val < l->val){
		LISTE *e = malloc(sizeof(LISTE));
		e->val = val;
		e->suiv = l;
		return e;
	}
	if(!(l->suiv)){
		LISTE *e = malloc(sizeof(LISTE));
		e->val = val;
		e->suiv = NULL;
		l->suiv = e;
		return l;
	}
	if((l->suiv)->val >= val){
		LISTE *e = malloc(sizeof(LISTE));
		e->val = val;
		e->suiv = l->suiv;
		l->suiv = e;
		return l;
	}
	l->suiv = inserer_trie_rec(l->suiv,val);
	return l;
}

/*
*
*
MANIPULATION AVANCEE
*
*
*/

LISTE *retourner(LISTE *l){
	LISTE *l2 = NULL;
	while(l){
		l2 = inserer_deb(l2,l->val);
		l = l->suiv;
	}
	return l2;
}
LISTE *concat(LISTE *l1, LISTE *l2){
	l1 = retourner(l1);
	while(l1){
		l2 = inserer_deb(l2,l1->val);
		l1 = l1->suiv;
	}
	return l2;
}
LISTE *fusion(LISTE *l1, LISTE *l2){
	LISTE *l3 = NULL;
	while(l1 != NULL || l2 != NULL){
		if(l1 == NULL){
			l3=inserer_deb(l3,l2->val);
			l2 = l2->suiv;
		}else if(l2 == NULL){
			l3=inserer_deb(l3,l1->val);
			l1=l1->suiv;
		}else{
			if(l1->val < l2->val){
				l3=inserer_deb(l3,l1->val);
				l1=l1->suiv;
			}else{
				l3=inserer_deb(l3,l2->val);
				l2=l2->suiv;
			}
		}
	}
	l3=retourner(l3);
	return l3;
}
LISTE *uniq(LISTE *l){
	if(!l) return NULL;
	LISTE *e = l;
	int to_change = e->val;
	while(e->suiv){
		if(e->suiv->val == to_change){
			LISTE *tmp = e->suiv;
			e->suiv = e->suiv->suiv;
			free(tmp);
		}else{
			to_change = e->suiv->val;
			e = e->suiv;
		}
	}
	return l;
}
LISTE *echange(LISTE *l){
	int tmp;
	if(l->suiv){
		tmp = l->suiv->val;
		l->suiv->val = l->val;
		l->val = tmp;
	}
	return l;
}
LISTE *tri_bulle(LISTE *l){
	LISTE *cpt = l;
	while(cpt->suiv){
		LISTE *e = cpt;
		while(e->suiv){
			if(e->suiv->val > e->val)
				echange(e);
			e = e->suiv;
		}
		cpt = cpt->suiv;
	}
	l = retourner(l);
	return l;
}
