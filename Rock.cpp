#include "Rock.hpp"
// rock
Rock::Rock(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {150, 220, 150, 169};
    // src = {144, 10, 124, 102};
    src = {658, 1254, 50, 50};
}

void Rock::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

bool Rock::outOfScreen()
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void Rock::cutAnimation()
{
    // src = {314, 261, 136, 129};
    src = {658, 1254, 50, 50};
}

void Rock::dropObstacles()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Rock::getMov()
{
    return mover;
}

bool Rock::getIsClicked()
{
    return isClicked;
}

void Rock::setIsClicked()
{
    isClicked = true;
}