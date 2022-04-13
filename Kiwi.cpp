#include "Kiwi.hpp"

Kiwi::Kiwi(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Fruit(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {826, 225, 142, 160};
}

void Kiwi::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Kiwi::cutAnimation()
{
    src = {1001, 256, 142, 129};
}

void Kiwi::dropFruits()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Kiwi::getMov()
{
    return mover;
}

bool Kiwi::getIsClicked()
{
    return isClicked;
}

void Kiwi::setIsClicked()
{
    isClicked = true;
}