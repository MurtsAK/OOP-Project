
#include "health_and_score.hpp"
#include<iostream>

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

void health_and_score::health_status(){
	// int health_left = CuttingBoard.get_health_remaining();
	SDL_Rect statusSrc, statusMover;
	statusSrc = {1039, 813, 183, 183};
	statusMover = {30, 550, 30, 30};

	for(int i=0;i< totalHealth ; i++){
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=30;
	}
}
int health_and_score::getHealth()
{
    return totalHealth;
}
	
health_and_score::health_and_score(int th) : totalHealth(th)
{

}



void health_and_score::update(SDL_Renderer *renderer, SDL_Texture *asst){
	health_status();
	// printing_score();
	SDL_RenderPresent( gRenderer );
	SDL_Delay(5);
}