#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
 
#define WIDTH  800
#define HEIGHT 542

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main(int argc, char *argv[]){
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//init ecran
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE /*| SDL_RESIZABLE*/);
	if (ecran==NULL){
		fprintf(stderr, "RIP mode video: %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//corps
	SDL_Surface *rectangles[HEIGHT];
	SDL_Rect pos;
	//for(int i = 0; i<256;i++) rectangles[i] = NULL;
	for(int i = 0; i<HEIGHT;i++){ 
		rectangles[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,WIDTH,1,32,0,0,0,0);
		SDL_FillRect(rectangles[i],NULL,SDL_MapRGB(ecran->format,2*i,i,i/2));
		pos.x = 0; pos.y = i; 
		SDL_BlitSurface(rectangles[i],NULL,ecran,&pos);
	}
	SDL_Flip(ecran);
	pause();
	
	//exit
	for(int i = 0; i<HEIGHT; i++) SDL_FreeSurface(rectangles[i]);
	SDL_Quit();
    return EXIT_SUCCESS;
}
