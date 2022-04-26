
#include "health_and_score.hpp"
#include <iostream>

void health_and_score::updateHealth(int h)
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

void health_and_score::health_status(int x)
{
	// int health_left = SpaceX.get_health_remaining();
	if (x == 1)
	{
		SDL_Rect statusSrc, statusMover;
		statusSrc = {1039, 813, 183, 183};
		statusMover = {30, 550, 30, 30};

		for (int i = 0; i < totalHealth; i++)
		{
			SDL_RenderCopy(gRenderer, assets, &statusSrc, &statusMover);
			statusMover.x += 30;
		}
	}
	else if (x == 2)
	{
		SDL_Rect statusSrc, statusMover;
	statusSrc = {1272, 850, 164, 156};
	statusMover = {30, 350, 30, 30};

	for(int i=0;i< totalHealth ; i++){
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=30;
	}
	}
}
int health_and_score::getHealth()
{
	return totalHealth;
}

health_and_score::health_and_score(int th) : totalHealth(th)
{
}

void health_and_score::update(SDL_Renderer *renderer, SDL_Texture *asst, int x)
{
	health_status(x);
	// printing_score();
	SDL_RenderPresent(gRenderer);
	SDL_Delay(5);
}