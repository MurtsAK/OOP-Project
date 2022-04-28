#include "Diamond.hpp"

Diamond::Diamond(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Collectible(rend, ast)
{
    // Diamond's location in asset.png
    mover = mov;
    // src = {1262, 840, 164, 156};
    // src={310,249,29,27};
    src = {1272, 850, 164, 156};
}

void Diamond::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    // Collectible::draw();
    Collectible::draw(gRenderer,assets,src,mover);
}

SDL_Rect Diamond::getSrc() //getting coordinates
{
    return src;
}

bool Diamond::outOfScreen() //checking if diamond has moved out of screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void Diamond::dropCollectibles() //dropping it at a random speed
{
    // Collectible::dropCollectibles();
    srand(time(0));
    int randomY;
    randomY = 20 + rand() % 15;
    mover.y += randomY;
}

int Diamond::healthIncrease() 
{
    return 1;
}

SDL_Rect Diamond::getMov() //getting its movement
{
    return mover;
}

void Diamond::removeCollectible() //removing when collected
{
    src = {0, 0, 0, 0};
}

bool Diamond::getIsClicked()
{
    return isClicked;
}

void Diamond::setIsClicked()
{
    isClicked = true;
}