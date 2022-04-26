#include "Obstacle.hpp"

// Unit class is well implemented, no need to change it

Obstacle::Obstacle(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Obstacle::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {}

void Obstacle::cutAnimation() {}

void Obstacle::dropObstacles() {}

SDL_Rect Obstacle::getMov(
   // ObjectMov.y+=10;
) {}

bool Obstacle::getIsClicked() {}

void Obstacle::setIsClicked() {}

bool Obstacle::outOfScreen() {}