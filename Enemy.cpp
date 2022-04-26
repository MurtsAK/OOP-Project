#include "Enemy.hpp"

// Unit class is well implemented, no need to change it

Enemy::Enemy(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Enemy::draw(SDL_Renderer *gRenderer, SDL_Texture *assets, SDL_Rect src, SDL_Rect mover) {
    SDL_RenderCopy(gRenderer,assets,&src,&mover);
}

void Enemy::dropEnemies() {}

int Enemy::LifeDeduct() {}

SDL_Rect Enemy::getMov(
    //ObjectMov.y+=10;
) {}

SDL_Rect Enemy::getSrc() {}

void Enemy::animateEnemy() {}

bool Enemy::getIsClicked() {}

void Enemy::setIsClicked() {}

bool Enemy::outOfScreen() {}