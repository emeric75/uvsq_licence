#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uvsqgraphics.h>

#define LARGEUR 1200
#define HAUTEUR 800

/* Définitions des boutons pour l'interface */
typedef struct {
  POINT bg;
  POINT hd;
  COULEUR cou;
  char *label;
} Bouton;


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

/* Définition de la structure image */

typedef struct {unsigned char R,V,B;} Pixel;

typedef struct {
  int largeur;
  int hauteur;
  int max_col;
  Pixel **contenu;
} Image;


int max(int a, int b){
  return (a>b) ? a:b;
}

int min(int a, int b){
  return (a<b) ? a:b;
}

/* Fonctions d'entrée sortie */

Image init_image(int largeur, int hauteur){
	Image res;
	res.largeur = largeur;
  	res.hauteur = hauteur;
  	res.contenu = malloc(sizeof(Pixel*)*res.largeur);
  	for(int i=0; i < res.largeur;i++){
    	res.contenu[i] = malloc(res.hauteur * sizeof(Pixel));
  	}
  	return res;
}

Image lire_image(char *adresse){
  FILE *Fbinaire;
  Image img;
  int i,j;
  Fbinaire = fopen(adresse,"r");
  while(fgetc(Fbinaire) != '\n');//enlève une ligne
  fscanf(Fbinaire,"%d",&img.largeur);
  fscanf(Fbinaire,"%d",&img.hauteur);
  fscanf(Fbinaire,"%d",&img.max_col);
  while(fgetc(Fbinaire) != '\n');//enlève une ligne
  img.contenu = malloc(sizeof(Pixel*)*img.hauteur);
  for(i=0; i < img.largeur;i++){
    img.contenu[i] = malloc(img.hauteur * sizeof(Pixel));
  }
  for(j= img.hauteur - 1; j>=0; j--){
    for(i=0; i < img.largeur; i++){
      fread(&img.contenu[i][j],sizeof(Pixel),1,Fbinaire);
    }
  }
  fclose(Fbinaire);
  return img;
}

void ecrire_image(Image img, char *adresse){
  FILE *Fbinaire;
  int i,j;
  Fbinaire = fopen(adresse,"w");
  fprintf(Fbinaire,"P6\n%d %d\n%d\n", img.largeur, img.hauteur, 255);
  for(j= img.hauteur - 1; j>=0; j--){
    for(i=0; i < img.largeur; i++){
      fwrite(&img.contenu[i][j],sizeof(Pixel),1,Fbinaire);
    }
  }
  fclose(Fbinaire);
}

/* Fonctions d'affichage */

void affiche_bouton(Bouton b){
  draw_fill_rectangle(b.bg, b.hd, b.cou);
  POINT p;
  p.x = (19*b.bg.x + b.hd.x)/20;
  p.y = (3*b.bg.y + 7*b.hd.y)/10;
  aff_pol(b.label, 25, p, noir);
}


void montre_image(Image img){
  POINT p;
  for(int x = 0; x < img.largeur && x < LARGEUR - 200; x++){
    for(int y = 0; y < img.hauteur; y++){
      	p.x = x + 25;
      	p.y = y + 25;
      	draw_pixel(p,couleur_RGB(img.contenu[x][y].R,img.contenu[x][y].V,
      	img.contenu[x][y].B));
    }
  }
}

void update_image(Bouton *bouton_tab, int bouton_number, Image img){
  fill_screen(noir);
  for(int i = 0; i<bouton_number; i++) affiche_bouton(bouton_tab[i]);
  montre_image(img);
  affiche_all();
}

/*Fonctions cryptographiques */

char *get_message(){
  char *secret = malloc(sizeof(char)*256);
  printf("Entrer la phrase secrète à coder dans l'image: \n");  
  scanf("\n");  
  fgets(secret+1,255,stdin);
  secret[0] = strlen(secret+1);//stocke la taille du message en première position
  //secret contient la phrase secrète
  return secret;
}

void encrypte(Image img, char *secret){ //pour simplifier, on codera la phrase secrète sur la première ligne de l'image 
                              //qu'on supposera assez grande. Le premier caractère contient la taille du message.
  
  int taille = secret[0];
  //on écrit un caractère de secret par pixel
  for(int j = 0; j < taille; j++){ //on vire le caractère de retour à la ligne
    //mettre ici le caractere secret[j] dans le pixel img.contenu[0][j]
  }
}


char *decrypte(Image img){
  //on calcule la taille
  int taille = 0; //changer 0 par la taille lue dans le premier pixel
  char *res = malloc(sizeof(char)*(taille+1));
  for(int j = 0; j < taille;j++){
    //lire chaque pixel et mettre le résultat dans res[j]
  }
  res[taille] = '\0';
  return res;
}

char *code(char *message){
  char code[256];
  printf("Rentrez votre code secret. \n");
  scanf("\n");
  fgets(code,256,stdin);
  int taille_message = message[0];
  int taille_code = strlen(code);
  for(int i = 1; i < taille_message; i++){
    //coder le message grace au code secret en utilisant un XOR noté ^ en C
  }
  return message;
}

int signature(Image img){
  int res = 0;
  for(int i=0; i <img.largeur; i++){
    for(int j=0; j<img.hauteur; j++){
    //accumuler l'information de img.contenu[i][j] dans res
    }
  }
  return res;
}

void parite(Image img){
  //bit de parité sur les colonnes
  for(int i=0; i <img.largeur-1; i++){
    int bit = 0;
    for(int j=0; j<img.hauteur-1; j++){
      //calculer le bit de parité sur la colonne i
    }
    //modifier img.contenu[i][img.hauteur-1].R  pour lui mettre le bit de parité calculé comme bit de poids faible
  }
  //bit de parité sur les lignes
  for(int j=0; j <img.hauteur-1; j++){
    int bit = 0;
    for(int i=0; i<img.largeur-1; i++){
     //calculer le bit de parité sur la ligne j
    }
    //modifier img.contenu[img.largeur-1][j].R   pour lui mettre le bit de parité calculé comme bit de poids faible
  }
}



void parite_verifie(Image img){
  //vérification des bit de parité sur les colonnes
  int ok = 1;
  for(int i=0; i <img.largeur-1; i++){
    int bit = 0;
    for(int j=0; j<img.hauteur-1; j++){
      //calcul du bit de parité
    }
    if(bit != img.contenu[i][img.hauteur-1].R%2) {
      // que faire ???
    }
  }
  //vérification des bits de parité sur les lignes
  for(int j=0; j <img.hauteur-1; j++){
    int bit = 0;
    for(int i=0; i<img.largeur-1; i++){
       //calcul du bit de parité
    }
    if(bit != img.contenu[img.largeur-1][j].R%2) {
      // que faire ???
    }
  }
  if(ok) printf("Image non corrompue\n");
}

int main(int argc, char **argv){ //la ligne de commande va contenir deux noms, le fichier d'entrée et 
//le fichier de sauvegarde
  if(argc != 3) {printf("Il doit y avoir deux arguments, l'image à éditer et la destination de l'image modifiée"); exit(1);}
  POINT p;
  init_graphics(LARGEUR, HAUTEUR);
  affiche_auto_off();
  Image source = lire_image(argv[1]);


  /* Initialisation des boutons */
  int nombre_bouton = 8;
  Bouton *bouton_tab = init_boutons(nombre_bouton);

  bouton_tab[0].label = "Terminer";
  bouton_tab[1].label = "Encrypter";
  bouton_tab[2].label = "Decrypter";
  bouton_tab[3].label = "Encrypter++";
  bouton_tab[4].label = "Decrypter++";
  bouton_tab[5].label = "Signature";
  bouton_tab[6].label = "Bit parite";
  bouton_tab[7].label = "Verifier";
  update_image(bouton_tab,nombre_bouton,source);
  
  while(1){
    p = wait_clic();
    if(clic_bouton(p,bouton_tab[0])) break;//sort de la boucle
    if(clic_bouton(p,bouton_tab[1])) encrypte(source, get_message()); 
    if(clic_bouton(p,bouton_tab[2])) {
      char* message_decrypte = decrypte(source);
      printf("Message secret de taille %d: %s \n",message_decrypte[0],message_decrypte+1);
    }
    if(clic_bouton(p,bouton_tab[3])) encrypte(source,code(get_message()));
    if(clic_bouton(p,bouton_tab[4])) {
      char* message_decrypte = code(decrypte(source));
      printf("Message secret de taille %d: %s \n",message_decrypte[0],message_decrypte+1);
    }
    if(clic_bouton(p,bouton_tab[5])) printf("Signature: %d\n",signature(source));
    if(clic_bouton(p,bouton_tab[6])) parite(source);
    if(clic_bouton(p,bouton_tab[7])) parite_verifie(source);
  }
  ecrire_image(source, argv[2]);//enregistre l'image modifiée
  exit(0);
}
