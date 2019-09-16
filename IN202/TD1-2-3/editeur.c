#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uvsqgraphics.h>

/* Définitions des boutons pour l'interface */
typedef struct {
  POINT bg;
  POINT hd;
  COULEUR cou;
  char *label;
} Bouton;

/* Définition de l'image */

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
  for(i=0; i < img.hauteur;i++){
    img.contenu[i] = malloc(img.largeur * sizeof(Pixel));
  }
  for(i=0; i < img.hauteur; i++){
    for(j=0; j < img.largeur; j++){
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
  for (i=0 ; i<img.hauteur ; i++)
  {
    for (j=0 ; j<img.largeur ; j++)
    {
     fwrite(&img.contenu[i][j],sizeof(Pixel),1,Fbinaire);
    }
  }
  fclose(Fbinaire);
}

/* Fonctions d'affichage */

void affiche_bouton(Bouton b){
  draw_fill_rectangle(b.bg, b.hd, b.cou);
  POINT p;
  p.x = (9*b.bg.x + b.hd.x)/10;
  p.y = (b.bg.y + 9*b.hd.y)/10;
  aff_pol(b.label, 25, p, noir);
}


void montre_image(Image img){
  POINT p;
  for(p.y = 700; p.y > 700 - img.largeur && p.y > 200; p.y--){
    for(p.x = (WIDTH-img.hauteur)/2; p.x < img.hauteur + (WIDTH-img.hauteur)/2 && p.x < 1000; p.x++){
      draw_pixel(p,couleur_RGB(img.contenu[700 - p.y][p.x -(WIDTH-img.hauteur)/2].R,img.contenu[700 - p.y][p.x -(WIDTH-img.hauteur)/2].V,img.contenu[700 - p.y][p.x -(WIDTH-img.hauteur)/2].B));
    }
  }
}


/*Fonctions de transformation d'image*/


Image zoom(Image img){
  Image res = init_image(img.largeur*2,img.hauteur*2);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
    res.contenu[i][j] = img.contenu[i/2][j/2];
    }
  }
  return res;
}

Image shrink(Image img){
  Image res = init_image(img.largeur/2,img.hauteur/2);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
    res.contenu[i][j].R = (img.contenu[2*i][2*j].R + img.contenu[2*i+1][2*j].R + img.contenu[2*i][2*j+1].R + img.contenu[2*i+1][2*j+1].R)/4;
    res.contenu[i][j].B = (img.contenu[2*i][2*j].B + img.contenu[2*i+1][2*j].B + img.contenu[2*i][2*j+1].B + img.contenu[2*i+1][2*j+1].B)/4;
    res.contenu[i][j].V = (img.contenu[2*i][2*j].V + img.contenu[2*i+1][2*j].V + img.contenu[2*i][2*j+1].V + img.contenu[2*i+1][2*j+1].V)/4;
    }
  }
  return res;
}



Image flou(Image img, int rayon){ 
  Image res = init_image(img.largeur,img.hauteur);
  double moyenner,moyennev,moyenneb,cmpt;
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
      moyenner = 0;
      moyenneb = 0;
      moyennev = 0;
      cmpt = 0;
      for(int k=max(0,i-rayon); k < min(i+1+rayon,res.largeur);k++){
        for(int l=max(0,j-rayon); l < min(j+1+rayon,res.hauteur);l++){
            moyenner += img.contenu[k][l].R*((float)1.0f/(k+1));
            moyenneb += img.contenu[k][l].B*((float)1.0f/(k+1));
            moyennev += img.contenu[k][l].V*((float)1.0f/(k+1));
            cmpt += ((float)1.0f/(k+1));
        }
      }
     res.contenu[i][j].R = moyenner/cmpt;
     res.contenu[i][j].V = moyennev/cmpt;
     res.contenu[i][j].B = moyenneb/cmpt;
    }   
  }
  return res;
}

Image miroir(Image img){ 
    Image res = init_image(img.largeur,img.hauteur);
    for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		res.contenu[i][j] = img.contenu[i][img.hauteur-j-1];
    }
  }

    return res;
}
Image to_gris(Image img){
  Image res = init_image(img.largeur,img.hauteur);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		res.contenu[i][j].R = res.contenu[i][j].V = res.contenu[i][j].B = (img.contenu[i][j].R + img.contenu[i][j].V + img.contenu[i][j].B)/3;
	}
   }
  return res;
}

Image rotationCCW(Image img){
  Image res = init_image(img.hauteur,img.largeur);
  img = miroir(img);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		res.contenu[i][j] = img.contenu[j][i];
	}
	}
  return res;
}

Image rotationCW(Image img){
  Image res = init_image(img.hauteur,img.largeur);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		res.contenu[i][j] = img.contenu[j][i];
	}
  }
  res = miroir(res);
  return res;
}

Image psych(Image img){
	Image res = init_image(img.hauteur,img.largeur);
	
	for(int c=0; c<4;c++){
		
		for(int i=0;i<res.largeur;i++){
		for(int j=0;j<res.hauteur;j++){
			res.contenu[i][j].R += img.contenu[i][j].R/4;
			res.contenu[i][j].V += img.contenu[i][j].V/4;
			res.contenu[i][j].B += img.contenu[i][j].B/4;
		}
		}
		img=rotationCW(img);
	}
	return res;
	
}

Image noiretblanc(Image img){
  Image res = init_image(img.largeur,img.hauteur);
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		if((img.contenu[i][j].R + img.contenu[i][j].V + img.contenu[i][j].B)/3 < 128){
			res.contenu[i][j].R = res.contenu[i][j].V = res.contenu[i][j].B = 0;
		}else{
			res.contenu[i][j].R = res.contenu[i][j].V = res.contenu[i][j].B = 255;
		}
	}
	}
  return res;
}

Image light(Image img){//intensité en pourcentage de la luminosité d'origine
  printf("Entrer un entier qui donne le pourcentage de luminsotié désiré. 100: pas de changement, 50: deux fois moins lumineux, 200: deux fois plus lumineux/\n");
  int intensite = lire_entier_clavier();
  Image res = init_image(img.largeur,img.hauteur);
  float coeff;
  for(int i=0;i<res.largeur;i++){
    for(int j=0;j<res.hauteur;j++){
		coeff = (float)intensite*2.55;
		res.contenu[i][j].R = img.contenu[i][j].R*(coeff/255);
		res.contenu[i][j].V = img.contenu[i][j].V*(coeff/255);
		res.contenu[i][j].B = img.contenu[i][j].B*(coeff/255);
    }
  }
  return res;
}



int clic_bouton(POINT P, Bouton b){
  return (P.x > b.bg.x) && (P.y > b.bg.y) && (P.x < b.hd.x) && (P.y < b.hd.y);
}

void update_image(Bouton *bouton_tab, int bouton_number, Image img){
  fill_screen(noir);
  for(int i = 0; i<bouton_number; i++) affiche_bouton(bouton_tab[i]);
  montre_image(img);
  affiche_all();
}

int main(int argc, char **argv){ //la ligne de commande va contenir deux noms, le fichier d'entrée et 
//le fichier de sauvegarde
  if(argc != 3) {printf("Il doit y avoir deux arguments, l'image à éditer et la destination de l'image modifiée"); exit(1);}
  POINT p;
  init_graphics(900, 700);
  affiche_auto_off();
  Image source = lire_image(argv[1]);


  /* Initialisation des boutons */
  int nombre_bouton = 10;
  Bouton *bouton_tab = malloc(sizeof(Bouton)*nombre_bouton);

  for(int i = 0; i < nombre_bouton; i++){
    bouton_tab[i].bg.x = 25 + (i%8)*110; 
    bouton_tab[i].bg.y = 25 + (i/8)*62;
    bouton_tab[i].hd.x = 110 + (i%8)*110;
    bouton_tab[i].hd.y = 62 + (i/8)*62;
    bouton_tab[i].cou = orange;
  }
  bouton_tab[0].label = "Fin";
  bouton_tab[1].label = "Flou";
  bouton_tab[2].label = "Zoom";
  bouton_tab[3].label = "Dezoom";
  bouton_tab[4].label = "Miroir";
  bouton_tab[5].label = "Gris";
  bouton_tab[6].label = "Light";
  bouton_tab[7].label = "90CCW";
  bouton_tab[8].label = "90CW";
  bouton_tab[9].label = "psych";
  update_image(bouton_tab,nombre_bouton,source);
  
  while(1){
    p = wait_clic();
    if(clic_bouton(p,bouton_tab[0])) break;//sort de la boucle
    if(clic_bouton(p,bouton_tab[1])) source = flou(source, 5);   
    if(clic_bouton(p,bouton_tab[2])) source = zoom(source);
    if(clic_bouton(p,bouton_tab[3])) source = shrink(source); 
    if(clic_bouton(p,bouton_tab[4])) source = miroir(source); 
    if(clic_bouton(p,bouton_tab[5])) source = to_gris(source);
    if(clic_bouton(p,bouton_tab[6])) source = light(source);
    if(clic_bouton(p,bouton_tab[7])) source = rotationCCW(source);
    if(clic_bouton(p,bouton_tab[8])) source = rotationCW(source);
    if(clic_bouton(p,bouton_tab[9])) source = psych(source);
    update_image(bouton_tab,nombre_bouton,source);
  }
  ecrire_image(source, argv[2]);//enregistre l'image modifiée
  exit(0);
}
