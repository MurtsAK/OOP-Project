#include "Orange.hpp"

Orange::Orange(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Fruit(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {826, 44, 146, 162};
}

void Orange::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Orange::cutAnimation()
{
    src = {998, 44, 139, 146};
}

void Orange::dropFruits()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Orange::getMov()
{
    return mover;
}

bool Orange::getIsClicked()
{
    return isClicked;
}

void Orange::setIsClicked()
{
    isClicked = true;
}