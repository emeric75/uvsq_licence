#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 1000000//taille maximale d'un fichier stocké en mémoire
#define TAILLE_BUFFER 63 // 63 est la taille max d'une sous séquence car in utilise un octet pour coder cette valeur dont les deux premiers bits donnent le type de l'information
//on pourrait permettre une taille de 66 car les tailles 0,1,2 ne sont jamais utilisées 
#define TAILLE_DICT 65535 // on écrit deux octets pour le décalage donc au plus 2^16= 65536

typedef struct {
  int lettre; 
  int type; //0 si c'est un chiffre, 1 si c'est une lettre
}schar;

typedef struct{
  schar* tableau;
  int taille;
}texte;

typedef struct{
 int longueur;
 int decalage;
}code;

int min(int a, int b){return (a<b)?a:b; }

texte lit_texte(char* adresse){
  	FILE* f= fopen(adresse,"r");
  	if(f == NULL){
  		printf("Le fichier à ouvrir n'existe pas.\n");
  		exit(1);
  	}
  	int i=0;
  	int c;
  	texte t;
  	t.tableau = malloc(sizeof(schar)*TAILLE_MAX);
  	while((c = fgetc(f)) != EOF){
      	t.tableau[i].lettre = c;
      	t.tableau[i].type = 1;
    	i++;
  	}
  	t.taille= i;
  	fclose(f);
  	return t;
}


void affiche_texte(texte t){
  	for(int i=0; i < t.taille; i++){
    	if(t.tableau[i].type) {
    		printf("%c",t.tableau[i].lettre);
    	}
    	else{
      		printf("(%d,%d)",t.tableau[i].lettre,t.tableau[i+1].lettre);
      		i = i+1;
    	}
  	}
}

int prefixe_commun(texte t, int pos1, int pos2){// les positions vérifient pos1 > pos2
	int maxi = 0;
	while(pos1+maxi < t.taille && (t.tableau[pos1+maxi].lettre == t.tableau[pos2+maxi].lettre)){
		maxi += 1;
	}
	return maxi;
}
  
code max_sequence(texte t, int pos){
  code res;
  res.longueur = 2;
  res.decalage = t.tableau[pos].lettre;
  int longueur;
  int k = ((TAILLE_DICT > pos) ? 0 : pos-TAILLE_DICT);
  for(int i = pos-1; i >= k; i--){
	  longueur = prefixe_commun(t,pos,i);
	  if(longueur>res.longueur && longueur < TAILLE_BUFFER){res.longueur = longueur; res.decalage = pos-i;}
  }
  return res;
}


texte compresse(texte t){
	texte comp;
	code m;
	int i=0,j=0;//i indice dans le texte non compressé, j indice dans le texte compresse
	comp.tableau = malloc(sizeof(schar)*TAILLE_MAX);
	printf("la taille est de %d caractères (octets)\n", t.taille);
	//affiche_texte(t);
	while(i < t.taille){
		m = max_sequence(t,i);
	    if(m.longueur == 2){
			comp.tableau[j].type = 1;
			comp.tableau[j].lettre = m.decalage;
			i++;
			j++;
		}else{
			comp.tableau[j].type = 0;
			comp.tableau[j].lettre = m.longueur;
			comp.tableau[j+1].type = 0;
			comp.tableau[j+1].lettre = m.decalage;
			j+=2;
			i+=m.longueur;
		}
  }
  comp.taille = j;
  printf("la taille après compression est de %d valeurs (entiers ou lettres)\n",j);
  //affiche_texte(comp);
  return comp;
}


texte decompresse(texte t){
	texte decomp;
	int i=0,j=0;
	int k,longueur,decalage;
	decomp.tableau = malloc(sizeof(schar)*TAILLE_MAX);
	printf("la taille avant décompression est %d valeurs\n", t.taille);
	while(i < t.taille){
		if(t.tableau[i].type == 1){
			decomp.tableau[j] = t.tableau[i];
			i++;
			j++;
		}else{
			longueur = t.tableau[i].lettre; 
			decalage = t.tableau[i+1].lettre; 
			for(k=j; k<j+longueur; k++){
				decomp.tableau[k] = decomp.tableau[k-decalage];
			}
			i+=2;
			j+=longueur;
		}
  	}
  	decomp.taille = j;
  	printf("la taille est après décompression de %d caractères (octets)\n",j);
  	return decomp;
}


texte lit_texte_compresse(char* adresse){
	FILE* f= fopen(adresse,"r");
	int i=0;
	int c;
	texte t;
	t.tableau = malloc(sizeof(schar)*TAILLE_MAX);
	while((c = fgetc(f))!=EOF){
		if(c < 128){ //on lit une lettre
	  		t.tableau[i].lettre = c;
	  		t.tableau[i].type = 1;
	  		i++;
		}
		else{
	  		if(c < 192){//paire avec décalage sur un octet
				t.tableau[i].lettre = c-128;
				t.tableau[i].type = 0;
				t.tableau[i+1].lettre = fgetc(f);
				t.tableau[i+1].type = 0;
			}
			else{//paire avec décalage sur deux octets
				t.tableau[i].lettre = c-192;
				t.tableau[i].type = 0;
				t.tableau[i+1].lettre = fgetc(f)*256;
				t.tableau[i+1].lettre += fgetc(f);
				t.tableau[i+1].type = 0;
			}
			i = i+2;
		}
	}
	t.taille= i;
	printf("Le texte compressé utilise %d valeurs\n",i);
	fclose(f);
	return t;
}

void ecrit_texte_compresse(char* adresse,texte t){//on devrait écrire des unsigned char ?
	FILE* f= fopen(adresse,"w");
	int i, cmpt = 0;
	for(i=0;i<t.taille;i++){
		if(t.tableau[i].type){//on écrit une lettre
			fputc(t.tableau[i].lettre,f);
			cmpt++;
    	}
	    else{//on écrit une paire  on utilise le premier bit du premier élément pour signaler un codage sur deux octets
	      	if(t.tableau[i+1].lettre < 256){//decalage sur 1 octet
				fputc(t.tableau[i].lettre + 128,f);//on ajoute 128 pour mettre un 10 en première position de l'octet
				fputc(t.tableau[i+1].lettre,f);
				cmpt +=2;
	      	}
	      	else{//décalage codé sur deux octets
	      		//printf("%d, %d, %d\n", t.tableau[i].lettre + 192,t.tableau[i+1].lettre/256,t.tableau[i+1].lettre%256);
				fputc(t.tableau[i].lettre + 192,f);//on ajoute 192 pour mettre un 11 en première position de l'octet
				fputc(t.tableau[i+1].lettre/256,f);
				fputc(t.tableau[i+1].lettre%256,f);
				cmpt += 3;
	      	}
	      	i++;
	    }
  	}
  	printf("Le texte compressé prend %d octets\n",cmpt);
  	fclose(f);
}

  
int main(int argc, char **argv){
	if(argc != 2) {printf("Il doit y avoir un argument, l'adresse du texte à compresser."); return 1;}
	texte t = lit_texte(argv[1]);	
	//affiche_texte(t);
	texte comp = compresse(t);
	//affiche_texte(comp);
  	texte uncomp = decompresse(comp);
  	//affiche_texte(uncomp);
  	ecrit_texte_compresse("texte_compresse",comp);
  	return 1;
}
