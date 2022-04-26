#include "Shuriken.hpp"
// jelly type
Shuriken::Shuriken(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {830, 392, 130, 154};
    src = {728, 1254, 49, 49};
}

void Shuriken::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Shuriken::cutAnimation()
{
    src = {728, 1254, 49, 49};
}

void Shuriken::dropObstacles()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Shuriken::getMov()
{
    return mover;
}

bool Shuriken::getIsClicked()
{
    return isClicked;
}

void Shuriken::setIsClicked()
{
    isClicked = true;
}