#pragma once
#include <SDL.h>

class Spaceship
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    SDL_Rect mover, src;
    bool Collision = false;

    public:
    Spaceship(SDL_Renderer *, SDL_Texture *, SDL_Rect mov);
    SDL_Rect getMov();
    void draw(SDL_Renderer *, SDL_Texture *);
    void blastAnimation();
    void Fire();
    bool getCollision();
    void setCollision();
    void setMov(int x, int y);
};
