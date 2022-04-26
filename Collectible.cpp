#include "Collectible.hpp"

// Unit class is well implemented, no need to change it

Collectible::Collectible(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Collectible::draw(SDL_Renderer *gRenderer, SDL_Texture *assets, SDL_Rect src, SDL_Rect mover) {
    SDL_RenderCopy(gRenderer,assets,&src,&mover);
}

void Collectible::dropCollectibles() {}

int Collectible::healthIncrease() {}

SDL_Rect Collectible::getMov() {}
SDL_Rect Collectible::getSrc() {}

void Collectible::removeCollectible() {}

bool Collectible::getIsClicked() {}

void Collectible::setIsClicked() {}

bool Collectible::outOfScreen() {}