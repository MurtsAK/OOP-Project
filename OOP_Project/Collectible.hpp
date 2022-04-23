#pragma once
#include <SDL.h>
#include <time.h>
// Unit class is well implemented, no need to change it

class Collectible
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    Collectible(SDL_Renderer *, SDL_Texture *);
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual int healthIncrease();
    virtual void dropCollectibles();
    virtual void removeCollectible();
    virtual bool getIsClicked();
    virtual void setIsClicked();
    virtual SDL_Rect getMov();
};
