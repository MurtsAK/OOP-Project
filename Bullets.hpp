#pragma once
#include <SDL.h>

class Bullets
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    bool BulletCollision;
    SDL_Rect moverB,srcB;

public:
    Bullets(SDL_Renderer *, SDL_Texture *, SDL_Rect mov, int bullet_type);
    void draw(SDL_Renderer *, SDL_Texture *);
    void operator ++ ();
    SDL_Rect getLocation();
};

