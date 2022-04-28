#include "Shuriken.hpp"
// jelly type
Shuriken::Shuriken(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Object's location in asset.png
    mover = mov;
    // src = {830, 392, 130, 154};
    src = {728, 1254, 49, 49};
}

void Shuriken::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn 
    Obstacle::draw(gRenderer,assets,src,mover);
}

SDL_Rect Shuriken::getSrc() //getting coordinates
{
    return src;
}

bool Shuriken::outOfScreen() //checking if it is still in screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void Shuriken::cutAnimation() //animation when collided
{
    src = {1439, 438, 107, 121};
}

void Shuriken::dropObstacles() //dropping at a random speed
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Shuriken::getMov() //movement checker
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