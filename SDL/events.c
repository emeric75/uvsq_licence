#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
 
#define WIDTH  800
#define HEIGHT 600

int main(int argc, char *argv[]){
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//init ecran
	SDL_Surface *ecran = NULL;
	SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"),NULL);
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE /*| SDL_RESIZABLE*/ | SDL_DOUBLEBUF);
	if (ecran==NULL){
		fprintf(stderr, "RIP mode video: %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//corps
	SDL_EnableKeyRepeat(10,1);
	SDL_Surface *front = NULL;
	front = SDL_LoadBMP("pack_images_sdz/zozor.bmp");
	SDL_Rect front_pos = {(ecran->w - front->w)/2, (ecran->h - front->h)/2};
	SDL_SetColorKey(front, SDL_SRCCOLORKEY, SDL_MapRGB(front->format, 0, 0, 255));
	SDL_Event event;
	
	int continuer = 1;
	while(continuer){
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_UP: 
						front_pos.y--;
						break;
					case SDLK_LEFT: 
						front_pos.x--;
						break;
					case SDLK_DOWN: 
						front_pos.y++;
						break;
					case SDLK_RIGHT: 
						front_pos.x++;
						break;
					default: break;
				}
				break;
		}
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
		SDL_BlitSurface(front,NULL,ecran,&front_pos);
		SDL_Flip(ecran);
	}
	
	//exit
	SDL_Quit();
    return EXIT_SUCCESS;
}
    
