#pragma once
#include <SDL.h>
#include <time.h>
// Unit class is well implemented, no need to change it

class Fruit
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    Fruit(SDL_Renderer *, SDL_Texture *);
    virtual SDL_Rect getMov();
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual void cutAnimation();
    virtual void dropFruits();
    virtual bool getIsClicked();
    virtual void setIsClicked();
};
