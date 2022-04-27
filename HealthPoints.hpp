#pragma once
#include <SDL.h>

class HealthPoints
{
    // SDL_Rect src, mover;
    int totalHealth;
    int totalGems = 0;

public:
    HealthPoints(int);
    void updateHealth(int);
    int getHealth();
    int getGems();
    void updateGems();
    // void displayHealth(SDL_Renderer *gRenderer, SDL_Texture *assets);
};