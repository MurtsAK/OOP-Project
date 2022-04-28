#include "EnemySpaceship.hpp"
// blue astroid
EnemySpaceship::EnemySpaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Enemy(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {585, 800, 82, 200};
    // src = {288, 55, 39, 39};
    src = {552, 1254, 86, 80};
}

void EnemySpaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    Enemy::draw(gRenderer,assets,src,mover);
}

SDL_Rect EnemySpaceship::getSrc() //getting cooradinates
{
    return src;
}

bool EnemySpaceship::outOfScreen() //checkin gif it has moved out of screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void EnemySpaceship::dropEnemies() //dropping it at random speed
{
    srand(time(0));
    int randomY;
    randomY = 5 + rand() % 15;
    mover.y += randomY;
}

int EnemySpaceship::LifeDeduct() //life deduction when collided
{
    return -1;
}

SDL_Rect EnemySpaceship::getMov()
{
    return mover;
}

void EnemySpaceship::animateEnemy() //animation on collision
{
    static int currentState = 0;
    if (currentState == 0)
    {
        // src = {516, 19, 90, 200};
        src = {1439, 438, 107, 121};
        currentState = 1;
    }
    else if (currentState == 1)
    {
        // src = {585, 800, 82, 200};
        src = {1439, 438, 107, 121};
        currentState = 0;
    }
}

bool EnemySpaceship::getIsClicked()
{
    return isClicked;
}

void EnemySpaceship::setIsClicked()
{
    isClicked = true;
}