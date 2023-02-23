#include "fonction.h"



SDL_Surface* InitScreen(int width, int height)
{
    SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de la fenêtre: %s\n", SDL_GetError());
        return NULL;
    }

    return screen;
}


//************************************************************************************************************************************************************************************
SDL_Surface* LoadImage(const char* fileName)
{
  
    SDL_Surface* loadedImage = IMG_Load(fileName);
    if (loadedImage == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", fileName, SDL_GetError());
        return NULL;
    }

    return loadedImage;
}



//************************************************************************************************************************************************************************************



void DisplayImage(SDL_Surface* screen, SDL_Surface* image, SDL_Rect imagePosition)
{
    SDL_BlitSurface(image, NULL, screen, &imagePosition);
}


//************************************************************************************************************************************************************************************

void afficherTexte(SDL_Surface *screen, const char *texte, int x, int y, Uint8 r, Uint8 g, Uint8 b,const char *policename,int taille)
{
    TTF_Font *police=NULL;
    police=TTF_OpenFont(policename, taille);
    if(police==NULL)
    {
        printf("Impossible de charger la police. Erreur: %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Surface *texteSurface;
    SDL_Color couleurFont = {r, g, b};
    texteSurface=TTF_RenderText_Solid(police, texte, couleurFont);
    SDL_Rect positionTexte = {x, y, 0, 0};
    SDL_BlitSurface(texteSurface, NULL, screen, &positionTexte);
    SDL_FreeSurface(texteSurface);
    TTF_CloseFont(police);
}






//************************************************************************************************************************************************************************************


void playSound(SDL_Event event , SDL_Rect  imagePosition, Mix_Chunk * sound)

{
   

    if (event.motion.x >= imagePosition.x && event.motion.x <= imagePosition.x + imagePosition.w &&
      event.motion.y >= imagePosition.y && event.motion.y <= imagePosition.y + imagePosition.h) 
    {
        Mix_PlayChannel(-1, sound, 0);
    }

    
}

//************************************************************************************************************************************************************************************
void toggleFullscreen(SDL_Surface* screen,int fullscreen)
{
    fullscreen = !fullscreen;
    SDL_WM_ToggleFullScreen(screen);
}
