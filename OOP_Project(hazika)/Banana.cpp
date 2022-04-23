#include "Banana.hpp"
// red astroid
Banana::Banana(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Fruit(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {552, 1120, 114, 114};
}

void Banana::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Banana::cutAnimation()
{
    // src = {1185, 613, 135, 99};
    src = {552, 1120, 114, 114};
}

void Banana::dropFruits()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Banana::getMov()
{
    return mover;
}

bool Banana::getIsClicked()
{
    return isClicked;
}

void Banana::setIsClicked()
{
    isClicked = true;
}