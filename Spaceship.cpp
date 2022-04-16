#include "Spaceship.hpp"


Spaceship::Spaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : gRenderer(rend), assets(ast) {
    mover = mov;
    src = {41,644,418,425};
}

void Spaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Spaceship::setMov(int x, int y){
    mover.x = x;
    if (y>450){
        mover.y = y;
    }
}

void Spaceship::blastAnimation() {}

void Spaceship::Fire() {}

SDL_Rect Spaceship::getMov() {
    return mover;
}

bool Spaceship::getCollision() {}

void Spaceship::setCollision() {}

