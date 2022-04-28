#include "YellowEnemy.hpp"
// yellow enemy
YellowEnemy::YellowEnemy(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Obstacle(rend, ast)
{
    // Object's location in asset.png
    mover = mov;
    // src = {826, 225, 142, 160};
    // src = {144, 10, 124, 102};
    src = {830, 1165, 39, 39};
}

void YellowEnemy::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn 
    Obstacle::draw(gRenderer,assets,src,mover);
}

SDL_Rect YellowEnemy::getSrc() //getting coordinates
{
    return src;
}

bool YellowEnemy::outOfScreen() //checking if still in screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void YellowEnemy::cutAnimation() //animation when collision occurs
{
    // src = {1001, 256, 142, 129};
    // src = {144, 10, 124, 102};
    //src = {830, 1165, 39, 39};
    src = {1439, 438, 107, 121};
}

void YellowEnemy::dropObstacles() //dropping at a random speed
{
    srand(time(0));
    int randomY;
    // randomY = 10 + rand() % 15;
    randomY = 10;
    mover.y +=randomY;
}

SDL_Rect YellowEnemy::getMov() //movement check
{
    return mover;
}

bool YellowEnemy::getIsClicked()
{
    return isClicked;
}

void YellowEnemy::setIsClicked()
{
    isClicked = true;
}