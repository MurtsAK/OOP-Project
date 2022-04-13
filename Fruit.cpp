#include "Fruit.hpp"

// Unit class is well implemented, no need to change it

Fruit::Fruit(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Fruit::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {}

void Fruit::cutAnimation() {}

void Fruit::dropFruits() {}

SDL_Rect Fruit::getMov() {}

bool Fruit::getIsClicked() {}

void Fruit::setIsClicked() {}