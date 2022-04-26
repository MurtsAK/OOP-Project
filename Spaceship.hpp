#pragma once
#include <SDL.h>
#include <list>
#include "Bullets.hpp"
#include <SDL_ttf.h>
using namespace std;

class Spaceship
{
    list<Bullets *> bullets;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    SDL_Rect mover, src;
    int spaceship_type;
    bool Collision = false;
    int restTime = 0;

public:
    Spaceship(SDL_Renderer *, SDL_Texture *, SDL_Rect mov, int spaceship);
    SDL_Rect getMov();
    void draw(SDL_Renderer *, SDL_Texture *);
    void moveLeft();
    void moveRight();
    void createBullets();
    void blastAnimation();
    void Fire();
    bool getCollision();
    void setCollision();
    ~Spaceship();
    list<Bullets*> getBullets();  
};