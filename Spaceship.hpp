#pragma once
#include <SDL.h>

class Spaceship
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    public:
    Spaceship(SDL_Renderer *, SDL_Texture *);
    virtual SDL_Rect getMov();
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual void blastAnimation();
    virtual void Fire();
    virtual bool getIsClicked();
    virtual void setIsClicked();

};
