#include "Watermelon.hpp"
// jelly type
Watermelon::Watermelon(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Fruit(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {830, 392, 130, 154};
    src = {728, 1254, 49, 49};
}

void Watermelon::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Watermelon::cutAnimation()
{
    src = {728, 1254, 49, 49};
}

void Watermelon::dropFruits()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Watermelon::getMov()
{
    return mover;
}

bool Watermelon::getIsClicked()
{
    return isClicked;
}

void Watermelon::setIsClicked()
{
    isClicked = true;
}