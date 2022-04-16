#include "Spaceship.hpp"


Spaceship::Spaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, SDL_Rect srcR) : gRenderer(rend), assets(ast) {
    mover = mov;
    
}

void Spaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {}

void Spaceship::blastAnimation() {}

void Spaceship::Fire() {}

SDL_Rect Spaceship::getMov() {}

bool Spaceship::getCollision() {}

void Spaceship::setCollision() {}