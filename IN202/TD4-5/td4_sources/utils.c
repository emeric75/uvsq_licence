#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uvsqgraphics.h>

#define LARGEUR 1200
#define HAUTEUR 600
#define TAILLE 128 //taille de la grille carrée

typedef struct{
  int taille;
  char** t;//tableau à 2 dimensions avec des valeurs 0 et 1 (cellule morte ou vivante)
}Grille;

/* Définitions des boutons pour l'interface */
typedef struct {
  POINT bg;
  POINT hd;
  COULEUR cou;
  char *label;
} Bouton;



/* Définition de la structure image */

typedef struct {unsigned char R,V,B;} Pixel;

typedef struct {
  int largeur;
  int hauteur;
  int max_col;
  Pixel **contenu;
} Image;


enum{LIFE, UN_D, MARGOLUS, TRON, CRITTER, ROTATION};




void reverse_perm(int margo[16], int margoR[16]);



//retourne le reste de la division de a par b, avec -b <= a, et b>0
int modulo(int a, int b){
  if(a >= b)
    return a - b;
  else if(a < 0)
    return a + b;
  else
    return a;
}




void Margo(int* margo, int* margoR, char* str){
  int i=0;  
  char* token;
  printf("%s", str);
  token = strtok(str, ",");  
  while( token != NULL && i <16) {
    sscanf(token, "%d", margo+i);
    token = strtok(NULL, ",");
    i++;
  }
  reverse_perm(margo, margoR);
}


void init_Margo_rule(int* margo, int* margoR){
  char str[256];

  printf("Entrer le code pour la regle de Margolus: \n Format type attendu: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15\n");  
  fgets(str, 256, stdin);
  Margo(margo, margoR, str);
}



void Margo_rule(int rule, int* margo, int* margoR){
  char s_tron[64] = "15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0\n";
  char s_crit[64] = "15,14,13,3,11,5,6,1,7,9,10,2,12,4,8,0\n";
  char s_rot[64] = "0,2,8,3,1,5,6,7,4,9,10,11,12,13,14,15\n";
  if(rule == TRON)
    Margo(margo, margoR, s_tron);
  if(rule == CRITTER)
    Margo(margo, margoR, s_crit);
  if(rule == ROTATION)
    Margo(margo, margoR, s_rot);
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


int max(int a, int b){
  return (a>b) ? a:b;
}

int min(int a, int b){
  return (a<b) ? a:b;
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
  int def = min(HAUTEUR, LARGEUR-200)/(g.taille+1);
  int i,j;
  if(!(p.x <= g.taille*def && p.y <= g.taille*def))//si on clique en dehors de la grille
    return g;
  i = p.x / def;
  j = p.y / def;
  g.t[i][j] = 1-g.t[i][j];
  return g;
}


void montre_grille(Grille g){
  int i,j;
  POINT p1,p2,p3,p4;
  COULEUR col = blanc;
  int def = min(HAUTEUR, LARGEUR-200)/(g.taille+1);
  
  p1.x =0; p1.y=0;
  p2.x =0; p2.y=g.taille*def;
  p3.x =0; p3.y=0;
  p4.x =g.taille*def; p4.y=0;
  for(i=0;i<=g.taille;i++){
    draw_line(p1,p2,col);
    draw_line(p3,p4,col);
    p1.x+=def;
    p2.x+=def;
    p3.y+=def;
    p4.y+=def;
    col = (col == blanc)? gris : blanc;
  }
  p1.x = 1 ; 
  p2.x = def -1;
  for(i=0;i<g.taille;i++){
    p1.y = 1;
    p2.y = def-1;
    for(j=0;j<g.taille;j++){
      if(g.t[i][j]){
	draw_fill_rectangle(p1,p2,rouge);
      }
      else{
	draw_fill_rectangle(p1,p2,noir);
      }
      p1.y+= def;
      p2.y+= def;
    }
    p1.x+= def;
    p2.x+= def;
  }
}

void update_image(Bouton *bouton_tab, int bouton_number, Grille g){
  int i;
  fill_screen(noir);
  for(i = 0; i<bouton_number; i++) affiche_bouton(bouton_tab[i]);
  montre_grille(g);
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
