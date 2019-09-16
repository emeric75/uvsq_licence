
#define EST_RIEN   0
#define EST_FLECHE 1
#define EST_TOUCHE 2
#define EST_CLIC   3

#define FLECHE_GAUCHE 270
#define FLECHE_DROITE  90
#define FLECHE_DROIT FLECHE_DROITE
#define FLECHE_BAS 180
#define FLECHE_HAUTE 0
#define FLECHE_HAUT FLECHE_HAUTE



// 3.2.5 Attend que l'on appuie soit sur une lettre, une flèche ou que l'on clique.
	// La fonction modifie la touche la flèche ou le point selon le premier événement qui arrive.
	// La fonction renvoie le type d'événement (touche, fleche ou point) 
	// Cette fonction est bloquante.
int wait_key_arrow_clic (char *touche, int *fleche, POINT *P) { // Made by qst & pc
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE)) exit(0);
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_LEFT))  { *fleche = FLECHE_GAUCHE; return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RIGHT)) { *fleche = FLECHE_DROITE; return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_UP))    { *fleche = FLECHE_HAUTE;  return EST_FLECHE; }
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_DOWN))  { *fleche = FLECHE_BAS;    return EST_FLECHE; }
		if ((event.type == SDL_KEYUP) && ('a' <= event.key.keysym.sym) &&  (event.key.keysym.sym <= 'z'))  { *touche = event.key.keysym.sym-'a'+'A'; return EST_TOUCHE; }
//		if ((event.type == SDL_KEYUP)) { *touche = event.key.keysym.sym; return EST_TOUCHE; }
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT)) { P->x = event.button.x; P->y = HEIGHT-event.button.y; return EST_CLIC;}
	}
	return EST_RIEN;
}
