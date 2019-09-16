#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
typedef struct {int sommet; int t[NMAX];} Pile;

Pile creerPile(){
	Pile p;
	p.sommet = -1;
	return p;
}

int pileVide(Pile p){
	return (p.sommet == -1);
}
int pilePleine(Pile p){
	return (p.sommet == NMAX-1);
}
void empiler(Pile *p, int c){
	if(!pilePleine(*p)){
		(*p).sommet += 1;
		(*p).t[(*p).sommet] = c;
	}
}
int depiler(Pile *p){
	if(!pileVide(*p)) {(*p).sommet -= 1;return (*p).t[(*p).sommet+1];} 
	return 0;
}
int sommet(Pile *p){
	return (*p).t[(*p).sommet];
}
int main(){
	Pile p = creerPile();
	char read[10]={""};
	scanf("%s",read);
	while(read[0] != '#'){
		if(read[0] == '+'){
			empiler(&p,depiler(&p)+depiler(&p));
		}else if(read[0] == '*'){
			empiler(&p,depiler(&p)*depiler(&p));
		}else if(read[0] == '-'){
			empiler(&p,depiler(&p)-depiler(&p));
		}else{
			empiler(&p,atoi(read));
		}
		scanf("%s",read);
	}
	printf("%d",sommet(&p));
}
