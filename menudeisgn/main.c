#include "fonction.h"



int main(int argc, char *argv[])
{

    //initialisation
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    int fullscreen = 0;






    //initialiser screen

    SDL_Surface *screen = InitScreen(1918,839);




    //initialiser les images

    SDL_Surface *Image0 = LoadImage("welcome.png");
SDL_Surface *Image1 = LoadImage("menu1_.png");
SDL_Surface *Image2 = LoadImage("menu2_.png");
SDL_Surface *Image3 = LoadImage("menu3_.png");
SDL_Surface *Image4 = LoadImage("menu4_.png");
SDL_Surface *Image5 = LoadImage("menu5_.png");
SDL_Surface *Image6 = LoadImage("menu6_.png");
SDL_Surface *Image7 = LoadImage("menu7_.png");
SDL_Surface *Image8 = LoadImage("menu8_.png");
SDL_Surface *Image9 = LoadImage("menu9_.png");
SDL_Surface *Image10 = LoadImage("menu10_.png");
SDL_Surface *Image11 = LoadImage("about 01.png");
SDL_Surface *Image12 = LoadImage("about1.2.png");
SDL_Surface *Image13 = LoadImage("about1.3.png");
SDL_Surface *Image14 = LoadImage("about1.4.png");
SDL_Surface *Image15 = LoadImage("about1.5.png");
SDL_Surface *Image16 = LoadImage("about1.6.png");


    SDL_Surface *Start = LoadImage("play.png");
    SDL_Surface *Start2 = LoadImage("play1.png");
    SDL_Surface *Option = LoadImage("options.png");
    SDL_Surface *Option2 = LoadImage("options1.png");
    SDL_Surface *End = LoadImage("quit.png");
    SDL_Surface *End2 = LoadImage("quit1.png");
    SDL_Surface *Back = LoadImage("back.png");
    SDL_Surface *moin = LoadImage("moins.png");
    SDL_Surface *plus = LoadImage("plus.png");
SDL_Surface *confirmation = LoadImage("confirmation.png");
SDL_Surface *about = LoadImage("about.png");
SDL_Surface *about = LoadImage("about1.png");
    SDL_Surface *Texte1 ;

    //position ds images

    SDL_Rect PositionImage;
    PositionImage.x=0;
    PositionImage.y=0;
    PositionImage.w = Image->w;
    PositionImage.h = Image->h;

    SDL_Rect PositionImage2;
    PositionImage2.x=0;
    PositionImage2.y=0;
    PositionImage2.w = Image2->w;
    PositionImage2.h = Image2->h;

    SDL_Rect PositionImage3;
    PositionImage3.x=0;
    PositionImage3.y=0;
    PositionImage3.w = Image3->w;
    PositionImage3.h = Image3->h;

    SDL_Rect PositionImage4;
    PositionImage3.x=0;
    PositionImage3.y=0;
    PositionImage3.w = Image3->w;
    PositionImage3.h = Image3->h;

    SDL_Rect PositionStart;
    PositionStart.x=340;
    PositionStart.y=320;
    PositionStart.w = Start->w;
    PositionStart.h = Start->h;

    SDL_Rect PositionBack;
    PositionBack.x=0;
    PositionBack.y=370;
    PositionBack.w = Back->w;
    PositionBack.h = Back->h;

    SDL_Rect PositionOption;
    PositionOption.x=340;
    PositionOption.y=420;
    PositionOption.w = Start->w;
    PositionOption.h = Start->h;

    SDL_Rect PositionEnd;
    PositionEnd.x=340;
    PositionEnd.y=540;
    PositionEnd.w = Start->w;
    PositionEnd.h = Start->h;

    SDL_Rect Positionmoin;
    Positionmoin.x=400;
    Positionmoin.y=290;
    Positionmoin.w = moin->w;
    Positionmoin.h = moin->h;

    SDL_Rect Positionplus;
    Positionplus.x=650;
    Positionplus.y=290;
    Positionplus.w = plus->w;
    Positionplus.h = plus->h;




    // ajouter son principale
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *music = Mix_LoadMUS("song.mp3");
    int volume = 64;
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music, -1);


    // ajout du son bref

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *sound = Mix_LoadWAV("son.wav");
    Mix_VolumeChunk(sound, 5);



   //boucle d'event
    SDL_Event event;
    int run=1;
    int det=0;

    while(run != 0)
    {
        switch (run)
        {
        //page d'ouverture 
        case 1 :
            DisplayImage( screen, Image0, PositionImage);
            afficherTexte( screen, "Welcome", 680, 200, 0, 0, 0,"ka1.ttf",50);
            


            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_QUIT:
                    run = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        run = 0;
                    else
                        run=2;


                    break;

                }

            }
            break;
//*******************************************************************************************************************************************************************
        //menu prcipale 
        case 2:
            DisplayImage( screen, Image, PositionImage);
            DisplayImage( screen, Start, PositionStart);
            DisplayImage( screen, Option, PositionOption);
            DisplayImage( screen, End, PositionEnd);
            afficherTexte(screen, "HELLO", 0, 250, 255, 0, 0,"PrStart.ttf",100);
            if (det==1)
                DisplayImage( screen, Start2, PositionStart);
            if(det==2)
                DisplayImage( screen, Option2, PositionOption);
            if (det==3)
                DisplayImage( screen, End2, PositionEnd);


            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {

                case SDL_QUIT:
                    run = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        run = 0;
                    break;
                case SDL_MOUSEBUTTONUP :
                    if (event.button.x >= PositionEnd.x && event.button.x < PositionEnd.x + PositionEnd.w &&
                            event.button.y >= PositionEnd.y && event.button.y < PositionEnd.y + PositionEnd.h)
                        run = 0;

                    if (event.button.x >= PositionStart.x && event.button.x < PositionStart.x + PositionStart.w &&
                            event.button.y >= PositionStart.y && event.button.y < PositionStart.y + PositionStart.h)
                        run = 3;
                    if (event.button.x >= PositionOption.x && event.button.x < PositionOption.x + PositionOption.w &&
                            event.button.y >= PositionOption.y && event.button.y < PositionOption.y + PositionOption.h)
                        run = 4;
                    break ;
                case SDL_MOUSEMOTION:

                    if (event.motion.x >= PositionStart.x && event.motion.x <= PositionStart.x + PositionStart.w &&
                            event.motion.y >= PositionStart.y && event.motion.y <= PositionStart.y + PositionStart.h)
                    {
                        det=1;
                    }
                    else if
                    (event.motion.x >= PositionOption.x && event.motion.x <= PositionOption.x + PositionOption.w &&
                            event.motion.y >= PositionOption.y && event.motion.y <= PositionOption.y + PositionOption.h)
                    {
                        det=2;
                    }
                    else if
                    (event.motion.x >= PositionEnd.x && event.motion.x <=  PositionEnd.x +  PositionEnd.w &&
                            event.motion.y >=  PositionEnd.y && event.motion.y <=  PositionEnd.y +  PositionEnd.h)
                    {
                        det=3;
                    }
                    else
                        det=0;
                    playSound(event,  PositionStart, sound);
                    playSound(event,  PositionOption, sound);
                    playSound(event,  PositionEnd, sound);

                    break;
                }

            }

            break;

//*******************************************************************************************************************************************************************
        // play screen 
        case 3 :
            DisplayImage(screen, Image3, PositionImage3);
            DisplayImage(screen, Back, PositionBack);
            if(det==1)
                DisplayImage(screen, Back, PositionBack);


            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_QUIT:
                    run = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        run = 0;
                    break;
                case SDL_MOUSEBUTTONUP :
                    if (event.button.x >= PositionBack.x && event.button.x < PositionBack.x + PositionBack.w &&
                            event.button.y >= PositionBack.y && event.button.y < PositionBack.y + PositionBack.h)
                        run=2;
                    break;
                case SDL_MOUSEMOTION:
                    if (event.button.x >= PositionBack.x && event.button.x < PositionBack.x + PositionBack.w &&
                            event.button.y >= PositionBack.y && event.button.y < PositionBack.y + PositionBack.h)
                    {
                        det=1;
                    }
                    else
                        det=0;

                    break;

                }

            }
            break;
//*******************************************************************************************************************************************************************
        //option screen
        case 4 :
            DisplayImage(screen, Image2, PositionImage2);
            DisplayImage(screen, Back, PositionBack);
            DisplayImage(screen, moin, Positionmoin);
            DisplayImage(screen, plus, Positionplus);
            if(det==1)
                DisplayImage(screen, Back, PositionBack);

            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                case SDL_QUIT:
                    run = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        run = 0;
                    if (event.key.keysym.sym == SDLK_SPACE)
                        toggleFullscreen(screen, fullscreen);
                    break;
                case SDL_MOUSEBUTTONUP :
                    if (event.button.x >= PositionBack.x && event.button.x < PositionBack.x + PositionBack.w &&
                            event.button.y >= PositionBack.y && event.button.y < PositionBack.y + PositionBack.h)
                        run=2;
                    if (event.button.x >= Positionmoin.x && event.button.x < Positionmoin.x + Positionmoin.w &&
                            event.button.y >= Positionmoin.y && event.button.y < Positionmoin.y + Positionmoin.h)
                        volume=volume-32;
                    Mix_VolumeMusic(volume);
                    if (event.button.x >= Positionplus.x && event.button.x < Positionplus.x + Positionplus.w &&
                            event.button.y >= Positionplus.y && event.button.y < Positionplus.y + Positionplus.h)
                        volume=volume+32;
                    Mix_VolumeMusic(volume);
                    break;
                case SDL_MOUSEMOTION:
                    if (event.button.x >= PositionBack.x && event.button.x < PositionBack.x + PositionBack.w &&
                            event.button.y >= PositionBack.y && event.button.y < PositionBack.y + PositionBack.h)
                    {
                        det=1;
                    }
                    else
                        det=0;
                    break;
                }
            }
            break;
//*******************************************************************************************************************************************************************
        }


        SDL_Flip(screen);
    }














    //libere memoire
    Mix_FreeMusic(music);
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_FreeSurface(screen);
    SDL_FreeSurface(Image);
    SDL_FreeSurface(Image2);
    SDL_FreeSurface(Image3);
    SDL_FreeSurface(Start);
    SDL_FreeSurface(Option);
    SDL_FreeSurface(End);
    SDL_FreeSurface(Back);
    TTF_Quit();
    SDL_Quit();






    return 0;
}
