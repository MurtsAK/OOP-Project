#pragma once
#include <SDL.h>

class HealthPoints
{
    // SDL_Rect src, mover;
    int totalHealth;

public:
    HealthPoints(int);
    void updateHealth(int);
    int getHealth();
    // void displayHealth(SDL_Renderer *gRenderer, SDL_Texture *assets);
};