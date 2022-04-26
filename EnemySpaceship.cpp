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
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

bool EnemySpaceship::outOfScreen()
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void EnemySpaceship::dropEnemies()
{
    srand(time(0));
    int randomY;
    randomY = 5 + rand() % 15;
    mover.y += randomY;
}

int EnemySpaceship::LifeDeduct()
{
    return -1;
}

SDL_Rect EnemySpaceship::getMov()
{
    return mover;
}

void EnemySpaceship::animateEnemy()
{
    static int currentState = 0;
    if (currentState == 0)
    {
        // src = {516, 19, 90, 200};
        src = {552, 1254, 86, 80};
        currentState = 1;
    }
    else if (currentState == 1)
    {
        // src = {585, 800, 82, 200};
        src = {552, 1254, 86, 80};
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