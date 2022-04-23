#include "Spaceship.hpp"

Spaceship::Spaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int spaceship) : gRenderer(rend), assets(ast)
{
    mover = mov;
    src = {10, 144, 86, 80};
    if (spaceship == 1)
    {
        // src = {41,644,418,425};
        src = {41, 1677, 194, 134};
    }
    else if (spaceship == 2)
    {
        // src = {21,2312,1558,1517};
        src = {37, 1913, 202, 166};
    }
    else if (spaceship == 3)
    {
        // src = {907,1277,920,977};
        src = {41, 2161, 194, 170};
    }
    else if (spaceship == 4)
    {
        // src = {1067,617,555,644};
        src = {37, 4089, 202, 258};
    }
    else if (spaceship == 5)
    {
        // src = {532,639,448,465};
        src = {37, 3075, 202, 266};
    }
    else if (spaceship == 6)
    {
        // src = {188,1315,532,790};
        src = {89, 3497, 98, 86};
    }
}

void Spaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Spaceship::setMov(int x, int y)
{
    mover.x = x;
}

void Spaceship::blastAnimation() {}

void Spaceship::Fire() {}

SDL_Rect Spaceship::getMov()
{
    return mover;
}

bool Spaceship::getCollision() {}

void Spaceship::setCollision() {}
