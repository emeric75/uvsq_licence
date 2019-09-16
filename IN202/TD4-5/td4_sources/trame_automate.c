#include "utils.c"
#include "patch.c"



/*Calcule la grille obtenue après une étape de l'automate de Margolus donné par la règle margo et margoR (pour le retour en arrière).*/

void margolus(int margo[16], int margoR[16], int fleche, Grille g){
  int i,j,k;
  char val;
  int turn = (fleche==FLECHE_DROITE ? 0:1);//vaut 0 si flèche droite, 1 si fleche gauche
 
  
  for(k=0; k<2; k++){//on fait 2 étapes de l'automate à chaque fois
    for(i=0; i<g.taille/2; i++){
      for(j=0; j<g.taille/2; j++){
	
	/*à faire: on calcule la valeur associée à la configuration des 4 cases (entre 0 et 15)*/
	val = 8*g.t[(2*i+turn)%g.taille][(2*j+1+turn)%g.taille]+4*g.t[(2*i+1+turn)%g.taille][(2*j+1+turn)%g.taille]+2*g.t[(2*i+turn)%g.taille][(2*j+turn)%g.taille]+g.t[(2*i+1+turn)%g.taille][(2*j+turn)%g.taille]; 

	/*on calcule la nouvelle configuration des 4 cases*/
	if(fleche == FLECHE_DROITE)
	  val = margo[(int)val];
	else
	  val = margoR[(int)val];


	/*à faire: on modifie les 4 cases*/
	g.t[(2*i+turn)%g.taille][(2*j+1+turn)%g.taille] = (val>>3)%2;
	g.t[(2*i+1+turn)%g.taille][(2*j+1+turn)%g.taille] = (val>>2)%2;  
	g.t[(2*i+turn)%g.taille][(2*j+turn)%g.taille] = (val>>1)%2; 
	g.t[(2*i+1+turn)%g.taille][(2*j+turn)%g.taille] = val%2;
	
      }
    }
    turn = 1-turn;
  }
}




/*retourne l'indice où se trouve la valeur i dans le tableau margo*/
int cherche(int margo[16], int i){
  int k=0;
  /*for(int k = 0; k < 16; k++){
	  if(margo[k] == i) break;
  }*/
  while(k<16 && margo[k] != i) k++;
  return k;
}

/*calcule la permutation inverse du tableau margo dans margoR*/
void reverse_perm(int margo[16], int margoR[16]){
  int i;
  for(i=0; i<16; i++){
    /*à modifier*/
    margoR[i] = cherche(margo, i);
  }
}



/*calcule le nombre de cases vivantes autour de la cellule (i,j)*/
int nbVivant(Grille g, int i, int j){
  int cmp = 0;
  int k,l;
  for(k=i-1; k<i+2; k++){
    for(l=j-1; l<j+2; l++){
      cmp += g.t[modulo(k, g.taille)][modulo(l, g.taille)];
    }
  }
  return cmp - g.t[i][j];
}


/*calcule la grille obtenue après une étape du jeu de la vie*/
Grille life(Grille g){
  Grille res = init(g);//copie la taille de g en mettant toutes les cellules à 0
  int i,j,n;


  /*à remplir en utilisant la fonction nbVivant au dessus*/
  for(i=0; i<g.taille; i++){
    for(j=0; j<g.taille; j++){
		n = nbVivant(g,i,j);
		res.t[i][j] = ((n == 2 && g.t[i][j]) || n== 3);
    }
  }

  
  free(g.t);
  return res;
}


/*ajoute une ligne à l'automate 1d, avec la règle donnée par la valeur c entre 0 et 255*/
void un_d(Grille g, unsigned char c, int ligne){
  int i;
  unsigned char val;
  int l = g.taille-ligne;//ligne à remplir en fonction de l+1

  /*à remplir*/
  for(i=0; i<g.taille; i++){
    val = 4*g.t[modulo(i-1,g.taille)][l+1] + 2* g.t[i][l+1] + g.t[modulo(i+1,g.taille)][l+1];//doit contenir la valeur de la configuration de la cellule i
    g.t[i][l] = (c >> val)%2;
  }

}



/*remplit la grille aléatoirement*/
Grille grille_alea(){
  Grille g;
  int i,j;
  char* p;
  
  printf("Entrer la taille de la grille\n");
  scanf("%d", &(g.taille));
  getchar();//vide le \n
  g.t = calloc(1,g.taille*g.taille+g.taille*sizeof(char*));
  p = (char*) (g.t + g.taille);
  for(i=0; i<g.taille; i++)
    g.t[i] = p + i*g.taille;



  /*à remplir*/
  for(i=0; i<g.taille; i++){
    for(j=0; j<g.taille; j++){
    g.t[i][j] = (alea_int(101)<50);
    }
  }
  

  
  return g;
}




/*remplit la ligne du haut de la grille aléatoirement*/
Grille ligne_alea(){
  Grille g;
  int i;
  char* p;
  
  printf("Entrer la taille de la grille\n");
  scanf("%d", &(g.taille));
  getchar();//vide le \n
  g.t = calloc(1,g.taille*g.taille+g.taille*sizeof(char*));
  p = (char*) (g.t + g.taille);
  for(i=0; i<g.taille; i++)
    g.t[i] = p + i*g.taille;


  /*à écrire*/
  for(i=0; i<g.taille; i++){
    g.t[i][g.taille-1] = (alea_int(101)<70);
  }
  return g;
}






/****************** Fonction main *************************/

int main(){
  int fleche, evnt;
  POINT p;
  char touche;
  Grille g;
  int choix = LIFE;
  int choix_1d;
  int ligne = 1;//pour l'automate 1d
  int margo[16];//pour le code de la règle de Margolus
  int margoR[16];//pour le code de la règle de Margolus inversée
  
  g.t = NULL;
  g.taille = 0;
  init_graphics(LARGEUR, HAUTEUR);
  SDL_EnableKeyRepeat(500,50);//premiere valeur: duree avant repetition; deuxieme valeur: duree entre deux repetitions (diminuer pour accelerer)
  affiche_auto_off();

  /* Initialisation des boutons */
  int nombre_bouton = 11;
  Bouton *bouton_tab = init_boutons(nombre_bouton);
  bouton_tab[0].label = "Charge Img";
  bouton_tab[1].label = "Sauv Img";
  bouton_tab[2].label = "Init grille";
  bouton_tab[3].label = "Grille alea";
  bouton_tab[4].label = "Ligne alea";
  bouton_tab[5].label = "Life";
  bouton_tab[6].label = "1D";
  bouton_tab[7].label = "Margolus";
  bouton_tab[8].label = "Tron";
  bouton_tab[9].label = "Critter";
  bouton_tab[10].label = "Rotation";
  
  while(1){
    update_image(bouton_tab,nombre_bouton, g);
    
    evnt = wait_key_arrow_clic (&touche, &fleche, &p);
    if(evnt == EST_CLIC){
      if(clic_bouton(p,bouton_tab[0]))
	g = lire_image(g);
      if(clic_bouton(p,bouton_tab[1]))
	ecrire_image(g); 
      if(clic_bouton(p,bouton_tab[2])){
	if(g.t != NULL)
	  free(g.t);
	g = init_grille();
      }
     if(clic_bouton(p,bouton_tab[3])){
	if(g.t != NULL)
	  free(g.t);
	g = grille_alea();
      }
     if(clic_bouton(p,bouton_tab[4])){
	if(g.t != NULL)
	  free(g.t);
	g = ligne_alea();
      }
      if(clic_bouton(p,bouton_tab[5]))
	choix = LIFE;
      if(clic_bouton(p,bouton_tab[6])){
	choix = UN_D;
	ligne = 1;
	printf("Donner une valeur entre 0 et 255 pour choisir l'automate 1D\n");
	do{
	  scanf("%d", &choix_1d);
	  getchar();
	}
	while(choix_1d>255 || choix_1d<0);
      }
      if(clic_bouton(p,bouton_tab[7])){
	choix = MARGOLUS;
	init_Margo_rule(margo, margoR);
      }
      if(clic_bouton(p,bouton_tab[8])){
	choix = MARGOLUS;
	Margo_rule(TRON, margo, margoR);
      }
      if(clic_bouton(p,bouton_tab[9])){
	choix = MARGOLUS;
	Margo_rule(CRITTER, margo, margoR);
      }
      if(clic_bouton(p,bouton_tab[10])){
	choix = MARGOLUS;
	Margo_rule(ROTATION, margo, margoR);
      }
      
      g = change_grille(g, p);
    }
    else if(evnt == EST_FLECHE){
      if(fleche == FLECHE_DROITE || fleche == FLECHE_GAUCHE){
	if(choix == LIFE)
	  g = life(g);
	else if(choix == UN_D){
	  ligne = min(ligne+1, g.taille);
	  un_d(g, (unsigned char) choix_1d, ligne);
	}
	else
	  margolus(margo, margoR, fleche, g);
      }
    }
  }
  
  
  exit(0);
}
