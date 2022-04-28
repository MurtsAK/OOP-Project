#include "Health.hpp"

Health::Health(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Collectible(rend, ast)
{
    // Health's location in asset.png
    mover = mov;
    // src = {1039, 813, 183, 183};
    src = {1049, 823, 183, 183};
}

void Health::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    // Body is drawn and moves horizontal direction at the speed of 4 units
    // Collectible::draw();
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

bool Health::outOfScreen() //checking if health(heart) is still in screen
{
    if (mover.y>700)
    {
        return true;
    }
    return false;
}

void Health::dropCollectibles() //dropping at a random screen
{
    // Collectible::dropCollectibles();
    srand(time(0));
    int randomY;
    randomY = 25 + rand() % 15;
    mover.y += randomY;
}

Health::healthIncrease() //total increase in health
{
    return 2;
}

SDL_Rect Health::getMov()
{
    return mover;
}

void Health::removeCollectible() //removing when the user collects the health
{
    src = {0, 0, 0, 0};
}

bool Health::getIsClicked()
{
    return isClicked;
}

void Health::setIsClicked()
{
    isClicked = true;
}