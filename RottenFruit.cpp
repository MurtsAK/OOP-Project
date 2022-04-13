#include "RottenFruit.hpp"

RottenFruit::RottenFruit(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Enemy(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    src = {392, 835, 87, 154};
}

void RottenFruit::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void RottenFruit::dropEnemies()
{
    srand(time(0));
    int randomY;
    randomY = 5 + rand() % 15;
    mover.y += randomY;
}

int RottenFruit::LifeDeduct()
{
    return -1;
}

SDL_Rect RottenFruit::getMov()
{
    return mover;
}

void RottenFruit::animateEnemy()
{
    static int currentState = 0;
    if (currentState == 0)
    {
        src = {183, 42, 85, 156};
        currentState = 1;
    }
    else if (currentState == 1)
    {
        src = {392, 835, 87, 154};
        currentState = 0;
    }
}

bool RottenFruit::getIsClicked()
{
    return isClicked;
}

void RottenFruit::setIsClicked()
{
    isClicked = true;
}