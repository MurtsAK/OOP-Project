#include "BlueAsteroid.hpp"
// blue astroid
BlueAsteroid::BlueAsteroid(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {826, 44, 146, 162};
    src = {686, 1120, 124, 102};
}

void BlueAsteroid::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    Obstacle::draw(gRenderer,assets,src,mover);
}

SDL_Rect BlueAsteroid::getSrc(){
    return src;
}

void BlueAsteroid::cutAnimation()
{
    // src = {998, 44, 139, 146};
    // src={116,144,50,50};
    src = {1439, 438, 107, 121};
}

bool BlueAsteroid::outOfScreen()
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}
void BlueAsteroid::dropObstacles()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect BlueAsteroid::getMov()
{
    return mover;
}

bool BlueAsteroid::getIsClicked()
{
    return isClicked;
}

void BlueAsteroid::setIsClicked()
{
    isClicked = true;
}