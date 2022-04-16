#pragma once
#include <SDL.h>

class Spaceship
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    SDL_Rect mover, src;
    bool Collision = false;

    public:
    Spaceship(SDL_Renderer *, SDL_Texture *, SDL_Rect mov, SDL_Rect srcR);
    virtual SDL_Rect getMov();
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual void blastAnimation();
    virtual void Fire();
    virtual bool getCollision();
    virtual void setCollision();

};
