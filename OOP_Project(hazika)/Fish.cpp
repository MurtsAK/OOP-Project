#include "Fish.hpp"
// blue astroid
Fish::Fish(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Enemy(rend, ast)
{
    // Tank Body's location in asset.png
    mover = mov;
    // src = {585, 800, 82, 200};
    // src = {288, 55, 39, 39};
    src = {552, 1254, 86, 80};
}

void Fish::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

void Fish::dropEnemies()
{
    srand(time(0));
    int randomY;
    randomY = 5 + rand() % 15;
    mover.y += randomY;
}

int Fish::LifeDeduct()
{
    return -1;
}

SDL_Rect Fish::getMov()
{
    return mover;
}

void Fish::animateEnemy()
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

bool Fish::getIsClicked()
{
    return isClicked;
}

void Fish::setIsClicked()
{
    isClicked = true;
}