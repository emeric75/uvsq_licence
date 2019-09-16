#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
 
#define WIDTH  800
#define HEIGHT 600 

#define W_RECT 200
#define H_RECT 100

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


int main(int argc, char *argv[])
{
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
	SDL_WM_SetCaption("wow",NULL);
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,100,120,200));
	
	SDL_Surface *rectangle = NULL;
	rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, W_RECT, H_RECT, 32, 0, 0, 0, 0);
	SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format,200,120,100));
	
	SDL_Rect pos_rectangle = {(WIDTH-W_RECT)/2,(HEIGHT-H_RECT)/2};
	SDL_BlitSurface(rectangle,NULL,ecran,&pos_rectangle);
	
	SDL_Flip(ecran);
	pause();
	
	//exit
	SDL_FreeSurface(rectangle);
	SDL_Quit();
    return EXIT_SUCCESS;
}
