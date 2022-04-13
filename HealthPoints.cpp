#include "HealthPoints.hpp"
#include <iostream>

HealthPoints::HealthPoints(int th) : totalHealth(th)
{
    // src = {1039, 813, 183, 183};
    // mover = {5, 100, 30, 30};
}

void HealthPoints::updateHealth(int h)
{
    if (h == -3)
    {
        totalHealth -= totalHealth;
    }
    else
    {
        totalHealth += h;
    }
}

int HealthPoints::getHealth()
{
    return totalHealth;
}

// void HealthPoints::displayHealth(SDL_Renderer *gRenderer, SDL_Texture *assets)
// {
//     // if (totalHealth >= 0)
//     // {
//     //     for (int i = 0; i < totalHealth; i++)
//     //     {
//     //         if (i % 5 == 0)
//     //         {
//     //             mover.x = 5;
//     //             mover.y += 40;
//     //         }
//     //         SDL_RenderCopy(gRenderer, assets, &src, &mover);
//     //         mover.x += 20;
//     //     }
//     // }
// }