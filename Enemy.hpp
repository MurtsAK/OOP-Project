#pragma once
#include <SDL.h>
#include <time.h>

// Unit class is well implemented, no need to change it

class Enemy
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    // SDL_Rect getMov();
    Enemy(SDL_Renderer *, SDL_Texture *);
    virtual void draw(SDL_Renderer *, SDL_Texture *);
    virtual void dropEnemies();
    virtual void animateEnemy();
    virtual int LifeDeduct();
    virtual SDL_Rect getMov();
    virtual bool getIsClicked();
    virtual void setIsClicked();
    virtual bool outOfScreen();
};
