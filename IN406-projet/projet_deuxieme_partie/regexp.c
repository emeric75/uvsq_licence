#include "regexp.h"
#include <string.h>
STATELISTE table[7][7] = {//cette table représente la table des transitions de l'énoncé
		{{-1},{-1},{-1},{2,{A,B}},{-1},{2,{A,B}},{-1}}, // transition quand le STATE S est lu
		{{-1},{-1},{-1},{2,{C,D}},{-1},{2,{C,D}},{-1}},//STATE A
		{{3,{PLUS,A,B}},{-1},{-1},{-1},{0},{-1},{1,{CAR}}},//STATE B
		{{-1},{-1},{-1},{2,{E,F}},{-1},{2,{E,F}},{-1}},//STATE C
		{{0},{3,{POINT,C,D}},{-1},{-1},{0},{-1},{0}},//STATE D
		{{0},{0},{0},{3,{PARO,S,PARF}},{-1},{1,{CAR}},{-1}},//STATE E
		{{0},{0},{2,{ETOILE,F}},{-1},{0},{-1},{0}}//STATE F
	};
//Une STATELISTE de taille 0 correspond à une règle dont la production est epsilon.
//Une STATELISTE de taille -1 correspond à une erreur (expression rejetée)
ADERIV nouvel_arbre(STATE s, char c){
	ADERIV a = malloc(sizeof(struct aderiv));
	if(!a) {printf("Plus de mémoire, malloc a échoué.\n"); exit(5);}
	a->s = s;
	a->caractere = c;
	a->fils[0] = NULL;
	a->fils[1] = NULL;
	a->fils[2] = NULL;
	return a;
}

void liberer_arbre(ADERIV a){
	if(a){
		for(int i = 0; i < 3; i++) liberer_arbre(a->fils[i]);
		free(a);
	}
}


int indice_char(char c){//retourne l'indice correspondant au caractère dans le tableau des états
	switch(c){
		case '+': return 0;
		case '.': return 1;
		case '*': return 2;
		case '(': return 3;
		case ')': return 4;
		case '#': return 6;
		default:
			if( c >= 'a' && c <= 'z') return 5;
			printf("Caractère inconnu dans l'expression régulière.\n");
			exit(3);
	}
}
int char_indice(STATE s){
	switch(s){
		case CAR: return 0;
		case PARO: return '(';
		case PARF: return ')';
		case PLUS: return '+';
		case POINT: return '.';
		case ETOILE: return '*'; 
		default: return -1;
	}
}
int is_terminal(STATE s){
	return s>6;
}
ADERIV creer_branches(ADERIV a, PILE *p, char **expr){
	STATE to_read = depiler(p);
	if(is_terminal(to_read)){
		int to_match = char_indice(to_read);
		printf("terminal state : %d\n",to_read);
		printf("to_match : %c\n",to_match);
		if(to_match == 0){
			if('a' <= **expr && **expr <= 'z'){
				(*expr)++;
			}else if(**expr == '#'){;
			}
			else{
				printf("1error parsing regex");
				exit(3);
			}	
		}else if(**expr == (char)to_match){
			(*expr)++;
		}else{
			//erreur
			printf("2error parsing regex");
			exit(3);
		}
	}else{
		printf("nonterminal state : %d\n",to_read);
		printf("on read : %c\n", **expr);
		STATELISTE to_add = table[to_read][indice_char(**expr)];
		if(to_add.taille == -1){
			//erreur
			printf("3error parsing regex");
			exit(3);	
		}else{
			for(int i = 0; i<to_add.taille; i++){
				*p = empiler(*p,to_add.liste[to_add.taille-1-i]);
				printf("to push : %d\n", to_add.liste[to_add.taille-1-i]);
				if(to_add.liste[i] == CAR)
					a->fils[i] = nouvel_arbre(to_add.liste[i],**expr);
				else
					a->fils[i] = nouvel_arbre(to_add.liste[i],0);
			}
			for(int i = 0; i<to_add.taille; i++)
				a->fils[i] = creer_branches(a->fils[i],p,expr);
		}
	}
	return a;
}
ADERIV construire_arbre_derivation(char *expr){
	int taille = strlen(expr);
	PILE p = nouvelle_pile(taille*2);
	ADERIV a = nouvel_arbre(S,0);
	p = empiler(p,S);
	a = creer_branches(a,&p,&expr);
	return a;
}

void affiche_aderiv(ADERIV a, int space){//rendre joli
	//affiche les fils de gauche à droite
	if(a){
		affiche_aderiv(a->fils[2], space + 1);
		affiche_aderiv(a->fils[1], space + 1);
		for(int i = 0; i < space; i++) printf("   ");
		affiche_state(a->s);
		if(a->s == CAR) printf(" : %c",a->caractere);
		printf("\n");
	    affiche_aderiv(a->fils[0], space + 1);
	}
}
