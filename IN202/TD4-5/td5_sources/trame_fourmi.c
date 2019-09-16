#include "utils.c"

/*retourne la nouvelle position a partir d'une position pos et la direction d de deplacement
  la grille est considérée comme un tore*/
POINT deplacement(POINT pos, Direction d, int taille){
  if(d == HAUT)    pos.y = modulo(pos.y+1, taille);
  if(d == BAS)     pos.y = modulo(pos.y-1, taille);
  if(d == GAUCHE)  pos.x = modulo(pos.x-1, taille);
  if(d == DROITE)  pos.x = modulo(pos.x+1, taille);
  return pos;
}

Fourmi fourmi(Grille g, Fourmi f){
  /*à faire: Calcule la nouvelle direction de la fourmi en fonction de l'état de la case sur laquelle elle se trouve */ 
	if(g.t[f.pos.x][f.pos.y] % 2){
		f.d = modulo(f.d+1,4);
	}else{
		f.d = modulo(f.d-1,4);
	}

  /*à faire: modifie l'état de la case*/
	g.t[f.pos.x][f.pos.y] = modulo(g.t[f.pos.x][f.pos.y]+1,9);
  /*à faire: déplace la fourmi*/
	f.pos = deplacement(f.pos,f.d,g.taille);
  
  return f;
}


Fourmi fourmi_rev(Grille g, Fourmi f){
  Direction d;
  /*à faire: Calcule la direction vers la derniere case visitée */ 
  d = modulo(f.d+2,4);
  /*à faire: déplace la fourmi */
  f.pos = deplacement(f.pos,d,g.taille);
  
  /*à faire: calcule l'ancienne direction de la fourmi*/
  if(g.t[f.pos.x][f.pos.y] % 2){
		f.d = modulo(f.d-1,4);
	}else{
		f.d = modulo(f.d+1,4);
	}
  /*à faire: modifie l'état de la dernière case visitée*/
  g.t[f.pos.x][f.pos.y] = modulo(g.t[f.pos.x][f.pos.y]-1,9);

  return f;
}



/****************** Fonction main *************************/

int main(){
  int fleche, evnt;
  POINT p;
  char touche;
  Grille g={0,0,NULL};
  Fourmi f = {{0,0},DROITE};
  POINT container = {100, HAUTEUR-50};
  affiche_auto_off();
  
  
  g.t = NULL;
  g.taille = 0;
  g.def = 0;
  init_graphics(LARGEUR, HAUTEUR);
  SDL_EnableKeyRepeat(500,0.2);//premiere valeur: duree avant repetition; deuxieme valeur: duree entre deux repetitions (diminuer pour accelerer)
  affiche_auto_off();

  /* Initialisation des boutons */
  int nombre_bouton = 5;
  Bouton *bouton_tab = init_boutons(nombre_bouton);
  bouton_tab[0].label = "Charge Img";
  bouton_tab[1].label = "Sauv Img";
  bouton_tab[2].label = "Init grille";
  bouton_tab[3].label = "Grille alea";
  bouton_tab[4].label = "Fourmi";
  int count = 0;
  while(1){
    update_image(bouton_tab, nombre_bouton, g, f);
    
    evnt = wait_key_arrow_clic (&touche, &fleche, &p);
    if(evnt == EST_CLIC){
      if(clic_bouton(p,bouton_tab[0]))
	g = lire_image(g);
      else if(clic_bouton(p,bouton_tab[1]))
	ecrire_image(g); 
      else if(clic_bouton(p,bouton_tab[2])){
	if(g.t != NULL)
	  free(g.t);
	g = init_grille();
      }
      else if(clic_bouton(p,bouton_tab[3])){
	if(g.t != NULL)
	  free(g.t);
	g = grille_alea();
      }
      else if(clic_bouton(p,bouton_tab[4])){
		  count = 0;
	printf("Choisir la case initiale de la fourmi en cliquant sur la grille\n");
	do{
	  p = wait_clic();
	  f.pos.x = p.x/g.def;
	  f.pos.y = p.y/g.def;
	}
	while(f.pos.x >= g.taille || f.pos.y >= g.taille);
	printf("Choisir la direction de la fourmi en appuyant sur une fleche\n");
	do
	  evnt = wait_key_arrow_clic (&touche, &fleche, &p);
	while(evnt != EST_FLECHE);
	if(fleche == FLECHE_DROITE) f.d = DROITE;
	if(fleche == FLECHE_GAUCHE) f.d = GAUCHE;
	if(fleche == FLECHE_BAS) f.d = BAS;
	if(fleche == FLECHE_HAUTE) f.d = HAUT;	
      }
      else
	g = change_grille(g, p);
    }
    
    
    else if(evnt == EST_FLECHE){


      if(fleche == FLECHE_DROITE)
	{f = fourmi(g, f);
	count++;}
      if(fleche == FLECHE_GAUCHE)
	{f = fourmi_rev(g, f);
    count--;}
    
    aff_int(count, 20, container, white);
    printf("%d\n",count);
    affiche_all();
    }
  }
  
  
  exit(0);
}
