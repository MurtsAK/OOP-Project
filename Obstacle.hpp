#pragma once
#include <SDL.h>
#include <time.h>
// Unit class is well implemented, no need to change it

class Obstacle
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    Obstacle(SDL_Renderer *, SDL_Texture *);
    virtual SDL_Rect getMov();
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual void cutAnimation();
    virtual void dropObstacles();
    virtual bool getIsClicked();
    virtual void setIsClicked();
};
