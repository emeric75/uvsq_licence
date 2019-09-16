#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
//#include "io.c"
//#include "ingame.c"
//#include "struct.c"

#define WIDTH  600
#define HEIGHT 600
#define INTRO 0
#define INGAME 1
#define EDITOR 2
#define EXIT 3

typedef struct niveau {char grille[15][15];}NIVEAU;
typedef struct mario {int* pos; int dir;}MARIO;

void wait_change(int *mode){
	SDL_Event event;
	while(*mode == INTRO){
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				*mode = EXIT;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_s:
						*mode = INGAME;
						printf("ingame\n");
						break;
					case SDLK_e:
						*mode = EDITOR;
						printf("editeur\n");
						break;
					case SDLK_q:
						*mode = EXIT;
						break;
					default: break;
				}
			default: break;
		}
	}
}

NIVEAU read_level(char *name){
	FILE* f = fopen(name,"r");
	if(f == NULL) {SDL_Quit(); exit(EXIT_FAILURE);}
	NIVEAU out;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			fscanf(f,"%c",&(out.grille[i][j])); 
		}
		fscanf(f,"\n");
	}
	fclose(f);
	printf("chargement lvl ok\n");
	return out;
}


void aff_level(NIVEAU level, SDL_Surface *ecran){
	SDL_Color white = {255, 255, 255};
	TTF_Font *police = NULL;
	police = TTF_OpenFont("verdana.ttf",30);
	SDL_Surface *stomates[225];
	SDL_Rect pos;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++){
			stomates[i] = TTF_RenderText_Blended(police, &level.grille[i][j], white);
			pos.x = 20 + 40*i; pos.y=20+40*j;
			SDL_BlitSurface(stomates[i],NULL,ecran,&pos);
		}
	}
	TTF_CloseFont(police);
}


int main(int argc, char *argv[]){
	int mode = INTRO;
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	TTF_Init();
	//init ecran
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE /*| SDL_RESIZABLE*/);
	if (ecran==NULL){
		fprintf(stderr, "RIP mode video: %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//corps
		//menu intro
			//todo : image intro
	while(mode != EXIT){
		switch(mode){
			case INTRO:
				wait_change(&mode);
				break;
			case INGAME:
				;
				NIVEAU truc;
				truc = read_level("1.lvl");
				printf("niveau lu\n");
				aff_level(truc,ecran);
				printf("niveau affiché");
				for(int i = 1; i>0; i++ );
			case EDITOR:
				exit(EXIT_SUCCESS);
			case EXIT:
				break;
		}
	}
	//exit
	SDL_Quit();
	TTF_Quit();
    return EXIT_SUCCESS;
}
