#include "Enemy.hpp"

// Unit class is well implemented, no need to change it

Enemy::Enemy(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast) {}

void Enemy::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) {}

void Enemy::dropEnemies() {}

int Enemy::LifeDeduct() {}

SDL_Rect Enemy::getMov() {}

void Enemy::animateEnemy() {}

bool Enemy::getIsClicked() {}

void Enemy::setIsClicked() {}