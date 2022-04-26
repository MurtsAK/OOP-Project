#pragma once
#include <SDL.h>

class HealthPoints
{
    // SDL_Rect src, mover;
    int totalHealth;
    int totalGems;

public:
    HealthPoints(int);
    void updateHealth(int);
    int getHealth();
    int getGems();
    void updateGems(int);
    // void displayHealth(SDL_Renderer *gRenderer, SDL_Texture *assets);
};