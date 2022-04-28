#pragma once
#include <SDL.h>
#include <time.h>
// Unit class is well implemented, no need to change it

class Obstacle
{
    protected:
    SDL_Rect src, mover;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    bool isClicked = false;

public:
    Obstacle(SDL_Renderer *, SDL_Texture *);
    virtual SDL_Rect getMov();
    virtual SDL_Rect getSrc();
    virtual void draw(SDL_Renderer *, SDL_Texture *, SDL_Rect, SDL_Rect);
    virtual void cutAnimation();
    virtual void dropObstacles();
    virtual bool getIsClicked();
    virtual void setIsClicked();
    virtual bool outOfScreen();
};
