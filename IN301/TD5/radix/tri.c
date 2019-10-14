#include "tableau.h"
#include <string.h>

//associe à chaque caractere un indice dans le tableau des frequences
//les caractes possible sont les caracteres alphabetiques en minuscules et le caractere de fin de chaine '\0'
int indice(char c){
  if(c==0) return 0;
  return c-'a'+1;
}



//tri le tableau  selon la composante i
void tri_base_indice(Tableau t, int i){
	int j,put;
	int freq[27],freq_cum[27],ind[27];
	Tableau res;
	res = copy_tab(t);
	for(j=0; j<27; j++){
		freq[j] = 0;
	}
	for(j=0; j<27;j++){
		ind[j] = 0;
	}
	for(j=0 ;j<t.n;j++){
		freq[indice(t.tab[j][i])]++;
	}

	freq_cum[0]=0;
	for(j=1 ;j<27;j++){
		freq_cum[j] = freq_cum[j-1] + freq[j-1];
		//printf("freq_cum %d = %d\n",j,freq_cum[j]);
	}
	for(j=0 ;j<t.n;j++){
		//mettre à l'indice = freq_cum[indice(t.tab[j][i])] + ind[indice(t.tab[j][i])]
		put = freq_cum[indice(t.tab[j][i])] + ind[indice(t.tab[j][i])];
		res.tab[put] = t.tab[j];
		ind[indice(t.tab[j][i])]++;
	}
	for(j=0;j<t.n;j++){
		t.tab[j] = res.tab[j];
	}
}



 
//tri par base 
void tri_base(Tableau t){
  int i;
  for(i=t.taille-1; i>=0; i--){
    //printf("taille = %d\n",i);
    tri_base_indice(t, i);
    //affiche_tab(t);
    //printf("\n");
  }
}
//TODO
void tri_base_msd(Tableau t,int i,int g, int d){
	if(i == t.taille-1) return;
	tri_base_indice(t,i);
	int indeb = g, inmax = g;
	for(int j=0; j<27; j++){
		while(indice(t.tab[inmax][i]) == j) inmax++;
		tri_base_msd(t,i+1,indeb,inmax-1);
		indeb=inmax;
	}
}
//tri le tableau entre indices g et d compris

int partition(Tableau t, int g, int d){
	int i = g+1, j=d;
	//printf("%d %d\n", i,j);
	char *temp;
	while(i <= j){
		while(i<=j && strcmp(t.tab[i],t.tab[g]) <= 0 ) i++;
		while(i<=j && strcmp(t.tab[j],t.tab[g]) > 0) j--;
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
