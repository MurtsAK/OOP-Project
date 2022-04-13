#include "Lemon.hpp"

Lemon::Lemon(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Fruit(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {150, 220, 150, 169};
}

void Lemon::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Lemon::cutAnimation()
{
    src = {314, 261, 136, 129};
}

void Lemon::dropFruits()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Lemon::getMov()
{
    return mover;
}

bool Lemon::getIsClicked()
{
    return isClicked;
}

void Lemon::setIsClicked()
{
    isClicked = true;
}