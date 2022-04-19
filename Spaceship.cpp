#include "Spaceship.hpp"


Spaceship::Spaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int spaceship) : gRenderer(rend), assets(ast) {
    mover = mov;
    if (spaceship == 1){
        src = {41,644,418,425};
    }
    else if(spaceship == 2){
        src = {21,2312,1558,1517};
    }else if(spaceship == 3){
        src = {907,1277,920,977};
    }else if(spaceship ==4){
        src = {1067,617,555,644};
    }else if(spaceship == 5){
        src = {532,639,448,465};
    }else if(spaceship == 6){
        src = {188,1315,532,790};
    }
}

void Spaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Spaceship::setMov(int x, int y){
    mover.x = x;
}

void Spaceship::blastAnimation() {}

void Spaceship::Fire() {}

SDL_Rect Spaceship::getMov() {
    return mover;
}

bool Spaceship::getCollision() {}

void Spaceship::setCollision() {}

