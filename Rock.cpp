#include "Rock.hpp"
// rock
Rock::Rock(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Rock's location in asset.png
    mover = mov;
    // src = {150, 220, 150, 169};
    // src = {144, 10, 124, 102};
    src = {658, 1254, 50, 50};
}

void Rock::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn 
    Obstacle::draw(gRenderer,assets,src,mover);
}

bool Rock::outOfScreen() //checking if it is still in screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void Rock::cutAnimation() //animation when collision takes place
{
    // src = {314, 261, 136, 129};
    src = {1439, 438, 107, 121};
}

void Rock::dropObstacles() //dropping it at a random speed
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

SDL_Rect Rock::getMov() //movement checker
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

SDL_Rect Rock::getSrc() //getting coordinates
{
    return src;
}