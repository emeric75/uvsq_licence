#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define WIDTH  800
#define HEIGHT 600

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
	IMG_Init(IMG_INIT_JPG);
	//init ecran
	SDL_Surface *ecran = NULL;
	SDL_WM_SetIcon(SDL_LoadBMP("pack_images_sdz/sdl_icone.bmp"),NULL);
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE /*| SDL_RESIZABLE*/);
	if (ecran==NULL){
		fprintf(stderr, "RIP mode video: %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
	}
	//corps
	SDL_Surface *image_fond = NULL, *front = NULL;
	image_fond = SDL_LoadBMP("pack_images_sdz/lac_en_montagne.bmp");
	front = IMG_Load("pack_images_sdz/sapin.png");
	SDL_Rect pos_fond = {0,0};
	SDL_Rect pos_front = {200,400};
	
	//SDL_SetColorKey(front, SDL_SRCCOLORKEY, SDL_MapRGB(front->format, 255, 255, 255));
	//SDL_SetAlpha(front, SDL_SRCALPHA, 128);
	
	SDL_BlitSurface(image_fond,NULL,ecran,&pos_fond);
	SDL_BlitSurface(front,NULL,ecran,&pos_front);
	SDL_Flip(ecran);
	pause();
	
	//exit
	SDL_Quit();
    return EXIT_SUCCESS;
}
