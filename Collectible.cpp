#include "Collectible.hpp"

// Unit class is well implemented, no need to change it

Collectible::Collectible(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Collectible::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {}

void Collectible::dropCollectibles() {}

int Collectible::healthIncrease() {}

SDL_Rect Collectible::getMov() {}

void Collectible::removeCollectible() {}

bool Collectible::getIsClicked() {}

void Collectible::setIsClicked() {}

bool Collectible::outOfScreen() {}