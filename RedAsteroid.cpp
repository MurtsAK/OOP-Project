#include "RedAsteroid.hpp"
// red astroid
RedAsteroid::RedAsteroid(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {552, 1120, 114, 114};
}

void RedAsteroid::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    Obstacle::draw(gRenderer,assets,src,mover);
}

SDL_Rect RedAsteroid::getSrc()
{
    return src;
}

bool RedAsteroid::outOfScreen()
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void RedAsteroid::cutAnimation()
{
    // src = {1185, 613, 135, 99};
    src = {1439, 438, 107, 121};
}

void RedAsteroid::dropObstacles()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect RedAsteroid::getMov()
{
    return mover;
}

bool RedAsteroid::getIsClicked()
{
    return isClicked;
}

void RedAsteroid::setIsClicked()
{
    isClicked = true;
}