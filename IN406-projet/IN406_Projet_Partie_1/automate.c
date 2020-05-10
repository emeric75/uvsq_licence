#include "automate.h"
#include "ms_list.h"
AUTOMATE automate_creer (int Q){
	AUTOMATE A;
	A.sigma = 26;
	A.Q = Q;
	A.F = calloc(Q,sizeof(int)); //calloc place des zéros dans le tableau: aucun état final
	A.T = calloc(Q,sizeof(TRANSITION));//les 0 placés par calloc correspondent à NULL: toutes les listes sont vides, pas de transition
	return A;
} 

void automate_ajouter_transition (AUTOMATE A, int dep, char car, int arr){
	TRANSITION T = A.T[dep];
	while(T){ //teste si la transition existe et ne fait rien si c'est le cas
		if(T->car == car && T->arr == arr) return;
		T = T->suiv;
	}
	TRANSITION new = malloc(sizeof(struct transition));
	new->car = car;
	new->arr = arr;
	new->suiv = A.T[dep];
	A.T[dep] = new;
}

/*TRANSITION supprimer_transition(TRANSITION T, char car, int arr){
	if(!T) return NULL;
	if(T->car == car && T->arr == arr) {
		TRANSITION suivant = T->suiv;
		free(T);
		return suivant;
	}
	T->suiv = supprimer_transition(T->suiv,car,arr);
	return T;
}*/

/*void automate_supprimer_transition (AUTOMATE A, int dep, char car, int arr){
	supprimer_transition(A.T[dep],car,arr);
}*/

void automate_ajouter_final (AUTOMATE A, int q){
	A.F[q] = 1;
}

/*void automate_supprimer_final (AUTOMATE A, int q){
	A.F[q] = 0;
}*/


TRANSITION copie_liste(TRANSITION T, int decalage, int conserve_epsilon){
	if(!T) return NULL;
	if(!conserve_epsilon && T->car == -1) return copie_liste(T->suiv,decalage,conserve_epsilon);
	TRANSITION nouveau = malloc(sizeof(struct transition));
	nouveau->car = T->car;
	nouveau->arr = T->arr + decalage;	
	nouveau->suiv = copie_liste(T->suiv,decalage,conserve_epsilon);
	return nouveau;
}

AUTOMATE automate_copier(AUTOMATE A, int conserve_epsilon){
	AUTOMATE B = automate_creer(A.Q);
	B.Q = A.Q;
	B.sigma = A.sigma;
	//CHECK : double allocation
	//B.F = malloc(sizeof(int)*A.Q);
	memcpy(B.F,A.F,A.Q*sizeof(int));
	//B.T = malloc(sizeof(TRANSITION)*A.Q);
	for(int i = 0; i < A.Q; i++) B.T[i] = copie_liste(A.T[i],0,conserve_epsilon);
	return B;
}

void liberer_transition(TRANSITION T){
	if(T){
		liberer_transition(T->suiv);
		free(T);
	}
}

void automate_liberer_memoire(AUTOMATE A){
	free(A.F);
	for(int i = 0; i < A.Q; i++){
		liberer_transition(A.T[i]);
	}
	free(A.T);
}


void automate_ecrire (AUTOMATE A, char* nomfic){
	FILE *F = fopen(nomfic,"w");
	if(F == NULL){
    	printf("échec ouverture fichier %s\n", nomfic);
    	exit(0);
  	}
  	int nombre_finaux = 0;
  	for(int i = 0; i < A.Q; i++) nombre_finaux += A.F[i];
  	int nombre_transition = 0;
  	for(int i = 0; i < A.Q; i++){
  		TRANSITION l = A.T[i];
  		while(l){
  			nombre_transition++;
  			l = l-> suiv;
  		}
  	}
  	fprintf(F,"%d %d %d\n",A.Q,nombre_finaux,nombre_transition);
  	for(int i = 0; i < A.Q; i++){
  		if(A.F[i]) fprintf(F,"%2d ",i);
  	}
  	fprintf(F,"\n");
  	for(int i = 0; i < A.Q; i++){
  		TRANSITION l = A.T[i];
  		while(l){
  			fprintf(F,"%2d %c %2d\n",i,l->car,l->arr);
  			l = l-> suiv;
  		}
  	}
  	fclose(F);
}

AUTOMATE automate_lire (char* nomfic){
	FILE *F = fopen(nomfic,"r");
	if(F == NULL){
    	printf("échec ouverture fichier %s\n", nomfic);
    	exit(1);
  	}
  	int nombre_etat, nombre_finaux, nombre_transition;
  	if( fscanf(F,"%d%d%d\n",&nombre_etat,&nombre_finaux,&nombre_transition) != 3) {
  		printf("Entete de fichier mal formé\n");
  		exit(2);
  	}
  	AUTOMATE A = automate_creer(nombre_etat);
  	for(int i = 0; i < nombre_finaux; i++){
  		int etat_final;
  		if(fscanf(F,"%d",&etat_final) != 1){
  			printf("État finaux mal formés\n");
  			exit(2);
  		}
  		automate_ajouter_final(A,etat_final);	
  	} 
  	for(int i = 0; i < nombre_transition; i++){
  		int dep, arr;
  		char car;
  		if(fscanf(F,"%d %c %d\n",&dep,&car,&arr) != 3){
  			printf("Transitions mal formées\n");
  			exit(2);	
  		}
  		automate_ajouter_transition(A,dep,car,arr);
  	}
  	fclose(F);
  	return A;
}


void parcours(AUTOMATE A, int etat, int* accessible){//parcours en profondeur du graphe des epsilons transitions
	//calcul accessible l'ensemble des états accessibles à partir de etat
	TRANSITION T = A.T[etat];
	while(T){
		if(T->car == -1 && !accessible[T->arr]){
			accessible[T->arr] = 1;
			parcours(A, T->arr, accessible);
		}
		T = T->suiv;
	}
}

int ** matrice_accessibilite(AUTOMATE A){//calcul la matrice d'accessibilité entre les sommets en utilisant uniquement
//les epsilon transitions
	int ** matrice = malloc(sizeof(int*)*A.Q);
	for(int i = 0; i < A.Q; i++) {
		matrice[i] = calloc(A.Q,sizeof(int));
		parcours(A,i,matrice[i]);
	}
	return matrice;
}


AUTOMATE automate_supprimer_epsilon(AUTOMATE A){
	AUTOMATE B = automate_copier(A,0);//recopie A en enlevant les epsilon transitions
	int **matrice = matrice_accessibilite(A);
	for(int i = 0; i < A.Q; i++){//fermeture avant à partir de A
		for(int j = 0; j < A.Q; j++){
			if(matrice[i][j]){
				if(A.F[j]) automate_ajouter_final(B,i);//on accède de i à un état final par un epsilon chemin donc i final
				TRANSITION T = B.T[j];
				while(T){//on parcourt toutes les transitions (j,c,j') pour ajouter la transition (i,c,j')
					automate_ajouter_transition(B,i,T->car,T->arr);
					T = T->suiv;
				}
			}
		}
	}
	//CHECK : liberation 2D
	for(int i=0; i<A.Q; ++i)
		free(matrice[i]);
	free(matrice);
	return B;
}


/////////////////////////// Partie à faire par les étudiants /////////////////////////////////////////

//TODO: s'occuper de sigma / des fuites pour determiniser
AUTOMATE automate_epsilon(){
	AUTOMATE A = automate_creer(1);
	automate_ajouter_final(A,0);	
	return A;
}

AUTOMATE automate_une_lettre(char car){
	AUTOMATE A = automate_creer(2);
	automate_ajouter_transition(A,0,car,1);
	automate_ajouter_final(A,1);	
	return A;
}


AUTOMATE automate_concatenation(AUTOMATE A, AUTOMATE B){
	AUTOMATE C = automate_creer(A.Q+B.Q);
	/*
	 * numérotation dans C
	 * 0 à A.Q-1: états de A  /  A.Q à A.Q+B.Q-1 : états de B
	 */
	TRANSITION *ptrC = C.T;
	TRANSITION *ptrA = A.T;
	//on rajoute les transitions de A
	for(int i = 0; i<A.Q; ++i){
		*ptrC = copie_liste(*ptrA,0,1);
		++ptrC;
		++ptrA;
	}
	//concaténation : on relie les états finaux de A à l'état init de B
	for(int q = 0; q<A.Q; ++q)
		if(A.F[q])
			automate_ajouter_transition(C,q,-1,A.Q);
	//on rajoute les transitions de B
	TRANSITION *ptrB = B.T;
	for(int q = 0; q<B.Q; ++q){
		*ptrC = copie_liste(*ptrB,A.Q,1);
		++ptrC;
		++ptrB;
	}
	//les états finaux de B deviennent finaux dans C
	for(int q = 0; q<B.Q; ++q)
		if(B.F[q])
			automate_ajouter_final(C,A.Q+q);
	return C;
}

AUTOMATE automate_disjonction(AUTOMATE A, AUTOMATE B){
	AUTOMATE C = automate_creer(A.Q+B.Q+1);
	/*
	 * 0 : nouvel état initial
	 * 1 à A.Q : états de A   /   A.Q+1 à A.Q+B.Q : états de B
	 */
	//eps-trans depuis état initial
	automate_ajouter_transition(C,0,-1,1);
	automate_ajouter_transition(C,0,-1,A.Q+1);
	//recopie des transitions de A puis de B
	TRANSITION *ptrC = (C.T + 1); //on a déjà écrit les transitions de l'état 0
	TRANSITION *ptrA = A.T;
	TRANSITION *ptrB = B.T;
	for(int q = 0; q<A.Q; ++q){
		*ptrC = copie_liste(*ptrA,1,1);
		++ptrC;
		++ptrA;
	}
	for(int q = 0; q<B.Q; ++q){
		*ptrC = copie_liste(*ptrB, A.Q+1, 1);
		++ptrC;
		++ptrB;
	}
	//rajout états finaux
	for(int q = 1; q<A.Q+1; ++q)
		if( A.F[q-1] )
			automate_ajouter_final(C,q);
	for(int q = A.Q+1; q< A.Q+B.Q+1; ++q)
		if( B.F[q-(A.Q+1)] )
			automate_ajouter_final(C,q);
	return C;
}

AUTOMATE automate_etoile(AUTOMATE A){
	AUTOMATE B = automate_creer(A.Q);
	automate_ajouter_final(B,0);

	TRANSITION *ptrB = B.T;
	TRANSITION *ptrA = A.T;
	for(int q = 0; q<A.Q; ++q){
		*ptrB = copie_liste(*ptrA,0,1);
		++ptrB;
		++ptrA;
		if( A.F[q] ) 
			automate_ajouter_transition(B,q,-1,0);
	}
	return B;
}
AUTOMATE automate_ajouter_etat(AUTOMATE A){
	++A.Q;
	A.F = realloc(A.F,A.Q*sizeof(int));
	A.F[A.Q-1] = 0;
	A.T = realloc(A.T,A.Q*sizeof(TRANSITION));
	A.T[A.Q-1] = NULL;
	return A;
}
AUTOMATE automate_determiniser(AUTOMATE A){
	AUTOMATE B = automate_supprimer_epsilon(A);
	AUTOMATE det = automate_creer(1);
	MS_LIST* det_states = ms_list_init();
	MS_LIST* to_process = ms_list_init();
	int *init = calloc(B.Q,sizeof(int));
	init[0] = 1;
	to_process = ms_list_append(to_process,init,B.Q);
	det_states = ms_list_append(det_states,init,B.Q);
	//calcul des états et transitions à partir de l'état initial {0}
	while(to_process){
		MULTI_STATE cur = ms_list_pop(&to_process);
		for(char c = 'a'; c<='z'; ++c){
			int *succ = calloc(B.Q,sizeof(int));
			for(int i = 0; i<cur.nb_states; ++i){
				if(cur.multi_state[i]){
					TRANSITION ptr = B.T[i];
					while(ptr){
						if(ptr->car == c)
							succ[ptr->arr] = 1;
						ptr = ptr->suiv;
					}
				}
			}
			if(not_zero(succ,B.Q)){
				int trouve = ms_list_find(det_states,succ,B.Q);
				if(trouve != -1){
					automate_ajouter_transition(det,cur.id_state_det,c,trouve);
					free(succ);
				}else{
					det = automate_ajouter_etat(det);
					det_states = ms_list_append(det_states,succ,B.Q);
					MS_LIST *nv = malloc(sizeof(MS_LIST));
					nv->ms = det_states->ms;
					nv->suiv = to_process;
					to_process = nv;
					automate_ajouter_transition(det,cur.id_state_det,c,det_states->ms.id_state_det);
				}
			}else{
				free(succ);
			}
		}
	}
	//détermination états finaux dans det
	MS_LIST *ptr = det_states;
	while(ptr){
		MULTI_STATE to_check = ptr->ms;
		for(int i = 0; i<B.Q; ++i){
			if(to_check.multi_state[i] && B.F[i])
				automate_ajouter_final(det,to_check.id_state_det);
		}
		ptr = ptr->suiv;
	}
	ms_list_lib(det_states);
	ms_list_lib(to_process);
	automate_liberer_memoire(B);
	return det;
}
//Brzozowski pour minimiser
/*
AUTOMATE automate_transpose(AUTOMATE A){
	AUTOMATE At = automate_creer(A.Q+1);
	automate_ajouter_final(At,1);
	for(int q=1; q<A.Q+1; ++q){
		if(A.F[q-1])
			automate_ajouter_transition(At,0,-1,q);
		TRANSITION ptr = A.T[q-1];
		while(ptr){
			automate_ajouter_transition(At, ptr->arr+1, ptr->car, q);
			ptr = ptr->suiv;
		}
	}
	return At;
}
AUTOMATE automate_minimal(AUTOMATE A){
	AUTOMATE B = automate_transpose(A);
	AUTOMATE C = automate_determiniser(B);
	automate_ecrire(C,"temp_min.aut");
	AUTOMATE D = automate_transpose(C);
	automate_ecrire(D,"temp_min2.aut");
	AUTOMATE min = automate_determiniser(D);
	automate_liberer_memoire(B);
	automate_liberer_memoire(C);
	automate_liberer_memoire(D);
	return min;
}*/
int get_succ_det(AUTOMATE A, int state, char l){
	TRANSITION ptr = A.T[state];
	while(ptr){
		if(ptr->car == l)
			return ptr->arr;
		ptr = ptr->suiv;
	}
	return -1;
}
AUTOMATE automate_minimal(AUTOMATE A){
	AUTOMATE B = automate_determiniser(A);
	int **sep = malloc(B.Q*sizeof(int*));
	for(int i = 0; i<B.Q; ++i)
		sep[i] = calloc(B.Q,sizeof(int));
	//separation final/non final
	for(int i = 0; i<B.Q; ++i)
		for(int j = 0; j<B.Q; ++j)
			if(B.F[i] && !B.F[j])
				sep[i][j] = sep[j][i] = 1;

	int changes = 1;
	while(changes){
		changes = 0;
		for(int i = 0; i<B.Q; i++){
			for(int j = 0; j<B.Q; j++){
				if(!sep[i][j]){
					for(char c = 'a'; c<='z'; ++c){
						int succ1 = get_succ_det(B,i,c);
						int succ2 = get_succ_det(B,j,c);
						if(succ1 == -1 && succ2 == -1){
							continue;
						}else if((succ1 == -1 && succ2 != -1)||(succ1!=-1 && succ2 == -1)){
							sep[i][j] = sep[j][i] = 1;
							changes++;
							break;
						}else if(sep[succ1][succ2] || sep[succ2][succ1]){
							sep[i][j] = sep[j][i] = 1;
							changes++;
							break;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i<B.Q; i++){
		for(int j = 0; j<B.Q; j++){
			printf("%d ",sep[i][j]);
		}
		printf("\n");
	}
	MS_LIST* new_states = ms_list_init();
	int *classed = calloc(B.Q,sizeof(int));
	int nb_classes = 1;
	for(int i = 0; i<B.Q; i++){
		classed[i] = i;
		for(int j =0; j<i; j++){
			if(!sep[i][j]){
				classed[j] = classed[i];
		}
	}
	}
	printf("\n");
	for(int i = 0; i<B.Q; i++){
		printf("%d ",classed[i]);
	}
	printf("\n");
	return B;
	//automate_liberer_memoire(B);
}
