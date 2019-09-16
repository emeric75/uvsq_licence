#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uvsqgraphics.h>
#include "patch.c" //à retirer selon la version de la librairie uvsqgraphics

#define LARGEUR 1000
#define HAUTEUR 800
#define TAILLE 128 //taille de la grille carrée

COULEUR tab[9] = {noir,gris,blanc,rouge,vert,bleu,jaune,cyan,magenta};

typedef struct{
  int taille;
  int def;//taille d'une case
  char** t;//tableau à 2 dimensions avec des valeurs 0 et 1/2/3 (cellule morte ou vivante)
}Grille;

/* Définitions des boutons pour l'interface */
typedef struct {
  POINT bg;
  POINT hd;
  COULEUR cou;
  char *label;
} Bouton;

typedef enum{HAUT=0, DROITE=1, BAS=2, GAUCHE=3} Direction;


struct fourmi{
  POINT pos;
  Direction d;

};
typedef struct fourmi Fourmi;

/* Définition de la structure image */

typedef struct {unsigned char R,V,B;} Pixel;

typedef struct {
  int largeur;
  int hauteur;
  int max_col;
  Pixel **contenu;
} Image;




//retourne le reste de la division de a par b, avec -b <= a, et b>0
int modulo(int a, int b){
  if(a >= b)
    return a - b;
  else if(a < 0)
    return a + b;
  else
    return a;
}

int max(int a, int b){
  return (a>b) ? a:b;
}

int min(int a, int b){
  return (a<b) ? a:b;
}

/*génère une grille vide*/
Grille init_grille(){
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
  g.def = min(HAUTEUR, LARGEUR-200)/(g.taille+1);
  return g;
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
      g.t[i][j] = (alea_int(1000)<500);
    }
  }
  g.def = min(HAUTEUR, LARGEUR-200)/(g.taille+1);

  return g;
}






int clic_bouton(POINT P, Bouton b){
  return (P.x > b.bg.x) && (P.y > b.bg.y) && (P.x < b.hd.x) && (P.y < b.hd.y);
}

Bouton *init_boutons(int nombre_bouton){
  Bouton *bouton_tab = malloc(sizeof(Bouton)*nombre_bouton);
  int nombre_boutons_colonne = (HAUTEUR -50) /125; 
  for(int i = 0; i < nombre_bouton; i++){
    bouton_tab[i].bg.x = LARGEUR  - 200 -(i/nombre_boutons_colonne)*200; 
    bouton_tab[i].bg.y =  25 + (i % nombre_boutons_colonne)*125;
    bouton_tab[i].hd.x =  LARGEUR  - 25 - (i/nombre_boutons_colonne)*200;
    bouton_tab[i].hd.y =  125 +(i % nombre_boutons_colonne)*125;
    bouton_tab[i].cou = gris;
  }
  return bouton_tab;
}



/* Fonctions d'entrée sortie */

Grille lire_image(Grille g){
  FILE *f;
  char adresse[64];
  int taille, toto;
  int i,j;
  Pixel pix;
  char* p;
  
  printf("Entrer le nom du fichier PPM à ouvrir\n");
  fgets(adresse, 64, stdin);
  adresse[strlen(adresse)-1] = '\0';
  f = fopen(adresse, "r");
  if(f == NULL){
    printf("échec ouverture fichier %s\n", adresse);
    exit(0);
  }
  free(g.t);
  
  while(fgetc(f) != '\n');//enlève une ligne
  fscanf(f,"%d",&taille);
  fscanf(f,"%d",&taille);
  fscanf(f,"%d",&toto);
  while(fgetc(f) != '\n');//enlève une ligne

  g.taille = taille;
  g.t = calloc(1,g.taille*g.taille+g.taille*sizeof(char*));
  p = (char*) (g.t + g.taille);
  for(i=0; i<g.taille; i++)
    g.t[i] = p + i*g.taille;


  for(j= g.taille - 1; j>=0; j--){
    for(i=0; i < g.taille; i++){
      fread(&pix,sizeof(Pixel),1,f);
      if(pix.R == 255)
	g.t[i][j] = 1;
    }
  }
  g.def = min(HAUTEUR, LARGEUR-200)/(g.taille+1);
  fclose(f);
  return g;
}

void ecrire_image(Grille g){
  FILE *f;
  char adresse[64];
  int i,j;
  Pixel pix;

  printf("Entrer le nom du fichier de sauvegarde\n");
  fgets(adresse, 64, stdin);
  adresse[strlen(adresse)-1] = '\0';
  f = fopen(adresse, "w");
  if(f == NULL){
    printf("échec ouverture fichier %s\n", adresse);
    exit(0);
  }
  fprintf(f,"P6\n%d %d\n%d\n", g.taille, g.taille, 255);
  for(j= g.taille - 1; j>=0; j--){
    for(i=0; i < g.taille; i++){
      pix.R = pix.V = pix.B = g.t[i][j]*255;
      fwrite(&pix, sizeof(Pixel), 1, f);
    }
  }
  fclose(f);
}

/* Fonctions d'affichage */

void affiche_bouton(Bouton b){
  draw_fill_rectangle(b.bg, b.hd, b.cou);
  POINT p;
  p.x = (19*b.bg.x + b.hd.x)/20;
  p.y = (3*b.bg.y + 7*b.hd.y)/10;
  aff_pol(b.label, 25, p, noir);
}


Grille change_grille(Grille g, POINT p){
  int i,j;
  if(!(p.x <= g.taille*g.def && p.y <= g.taille*g.def))//si on clique en dehors de la grille
    return g;
  i = p.x / g.def;
  j = p.y / g.def;
  g.t[i][j] = 1-g.t[i][j];
  return g;
}


void montre_grille(Grille g, Fourmi f){
  int i,j;
  POINT p1,p2,p3,p4;
  COULEUR col = blanc;
  
  p1.x =0; p1.y=0;
  p2.x =0; p2.y=g.taille*g.def;
  p3.x =0; p3.y=0;
  p4.x =g.taille*g.def; p4.y=0;
  for(i=0;i<=g.taille;i++){
    draw_line(p1,p2,col);
    draw_line(p3,p4,col);
    p1.x+=g.def;
    p2.x+=g.def;
    p3.y+=g.def;
    p4.y+=g.def;
    col = (col == blanc)? gris : blanc;
  }
  p1.x = 1 ; 
  p2.x = g.def -1;
  for(i=0;i<g.taille;i++){
    p1.y = 1;
    p2.y = g.def-1;
    for(j=0;j<g.taille;j++){
	draw_fill_rectangle(p1,p2,tab[g.t[i][j]]);
      p1.y+= g.def;
      p2.y+= g.def;
    }
    p1.x+= g.def;
    p2.x+= g.def;
  }
  //dessine fourmi
  p1.x = f.pos.x * g.def + g.def/2;
  p1.y = f.pos.y * g.def + g.def/2;
  p2 = p1;
  draw_circle(p1, g.def/6, vert);
  if(f.d == GAUCHE)  p2.x = (f.pos.x) * g.def + g.def/6;
  if(f.d == DROITE)  p2.x = (f.pos.x+1) * g.def - g.def/6;
  if(f.d == BAS)  p2.y = (f.pos.y) * g.def + g.def/6;
  if(f.d == HAUT)  p2.y = (f.pos.y+1) * g.def - g.def/6;
  draw_circle(p2, g.def/6, vert);
  draw_line(p1,p2,vert);
}

void update_image(Bouton *bouton_tab, int bouton_number, Grille g, Fourmi f){
  int i;
  fill_screen(noir);
  for(i = 0; i<bouton_number; i++) affiche_bouton(bouton_tab[i]);
  if(g.taille > 0)
    montre_grille(g, f);
  affiche_all();
}



Grille init(Grille g){
  Grille res = g;
  char* p;
  int i;
  
  res.t = calloc(1,g.taille*g.taille+g.taille*sizeof(char*));
  p = (char*) (res.t + g.taille);
  for(i=0; i<g.taille; i++)
    res.t[i] = p + i*g.taille;

  return res;
}
