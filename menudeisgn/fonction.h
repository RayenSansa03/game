#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



SDL_Surface* InitScreen(int width, int height);
SDL_Surface* LoadImage(const char* fileName);
void DisplayImage(SDL_Surface* screen, SDL_Surface* image, SDL_Rect imagePosition);
void afficherTexte(SDL_Surface *screen, const char *texte, int x, int y, Uint8 r, Uint8 g, Uint8 b,const char *policename,int taille);
void playSound(SDL_Event event , SDL_Rect  imagePosition, Mix_Chunk * sound);
void toggleFullscreen(SDL_Surface* screen,int fullscreen);
