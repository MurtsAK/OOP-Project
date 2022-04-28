#include "BlueRing.hpp"

BlueRing::BlueRing(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Enemy(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {392, 835, 87, 154};
    src = {830, 1283, 34, 34};
}

void BlueRing::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    Enemy::draw(gRenderer,assets,src,mover);
}

SDL_Rect BlueRing::getSrc() //returns the coordinates
{
    return src;
}

void BlueRing::dropEnemies() //dropping object at a random speed
{
    srand(time(0));
    int randomY;
    randomY = 5 + rand() % 15;
    mover.y += randomY;
}

int BlueRing::LifeDeduct() //deduction of life if collided
{
    return -1;
}

SDL_Rect BlueRing::getMov() //getting dimension
{
    return mover;
}

void BlueRing::animateEnemy() //animation when bullet is hit
{
{
    src = {1439, 438, 107, 121};
}

bool BlueRing::outOfScreen() //function to check if our object has movedd out of screen or not
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

bool BlueRing::getIsClicked()
{
    return isClicked;
}

void BlueRing::setIsClicked()
{
    isClicked = true;
}