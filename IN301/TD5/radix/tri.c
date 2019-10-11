#include "tableau.h"
#include <string.h>

//associe à chaque caractere un indice dans le tableau des frequences
//les caractes possible sont les caracteres alphabetiques en minuscules et le caractere de fin de chaine '\0'
int indice(char c){
  return c-'a';
}



//tri le tableau  selon la composante i
void tri_base_indice(Tableau t, int i){
	int j;
	int freq[26];
	Tableau res;
	res.n = t.n;
	res.taille = t.taille;
	//res.tab = malloc(); allouer un tableau multidim vide
	for(j=0; j<26; j++){
		freq[j] = 0;
	}
	for(j=0 ;j<t.n;j++){
		freq[indice(t.tab[j][i])]++;
	}
}



 
//tri par base 
void tri_base(Tableau t){
  int i;
  for(i=t.taille-1; i>=0; i--)
    tri_base_indice(t, i);
}




//tri le tableau entre indices g et d compris

int partition(Tableau t, int g, int d){
	int i = g+1, j=d;
	//printf("%d %d\n", i,j);
	char *temp;
	if(i == j){
		if(strcmp(t.tab[i-1],t.tab[i]) > 0){
			temp = t.tab[i-1];
			t.tab[i-1] = t.tab[i];
			t.tab[i] = temp;
			return i;
		}
		return i-1;
	}
	while(i <= j && i < d && j>g){
		while(strcmp(t.tab[i],t.tab[g]) <= 0 && i <= j && i<d && j > g) i++;
		while(strcmp(t.tab[j],t.tab[g]) >= 0 && i <= j && i<d && j>g) j--;
		if(i<j){
			temp = t.tab[i];
			t.tab[i] = t.tab[j];
			t.tab[j] = temp;
		}else{
			temp = t.tab[g];
			t.tab[g] = t.tab[j];
			t.tab[j] = temp;
		}
	}
	/*printf("\n");
	affiche_tab(t);
	printf("\n");*/
	//printf("%d\n\n",j);
	return j;
}



void tri_rapide(Tableau t, int g, int d){
	if(g<d){
		int ind = partition(t,g,d);
		tri_rapide(t,g,(ind-1<g) ? g : ind-1);
		tri_rapide(t,  (ind+1>d) ? d : ind+1,d);
	}
}


//tri par comparaison en utilisant la fonction strcmp
void tri_cmp(Tableau t){
  tri_rapide(t, 0, t.n-1);
}
