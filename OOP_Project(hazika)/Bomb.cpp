#include "Bomb.hpp"

Bomb::Bomb(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Enemy(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {155, 794, 196, 198};
    // src={10,144,86,80};
    src = {165, 804, 198, 198};
}

void Bomb::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Bomb::dropEnemies()
{
    srand(time(0));
    int randomY;
    randomY = 10 + rand() % 15;
    mover.y += randomY;
}

int Bomb::LifeDeduct()
{
    return -3;
}

SDL_Rect Bomb::getMov()
{
    return mover;
}

void Bomb::animateEnemy()
{
    static int currentState = 0;
    if (currentState == 0)
    {
        // src = {1470, 749, 24, 25};
        src = {1480, 759, 24, 24};
        currentState = 1;
    }
    else if (currentState == 1)
    {
        // src = {1452, 668, 61, 63};
        src = {1462, 678, 61, 63};
        currentState = 2;
    }
    else if (currentState == 2)
    {
        // src = {1433, 554, 99, 108};
        src = {1443, 564, 99, 108};
        currentState = 3;
    }
    else if (currentState == 3)
    {
        // src = {1429, 428, 107, 121};
        src = {1439, 438, 107, 121};
        currentState = 4;
    }
    else if (currentState == 4)
    {
        // src = {1429, 297, 107, 122};
        src = {1439, 307, 107, 122};
        currentState = 5;
    }
    else if (currentState == 5)
    {
        // src = {1432, 165, 100, 110};
        src = {1442, 175, 100, 110};
        currentState = 6;
    }
    else if (currentState == 6)
    {
        src = {0, 0, 0, 0};
    }
}

bool Bomb::getIsClicked()
{
    return isClicked;
}

void Bomb::setIsClicked()
{
    isClicked = true;
}