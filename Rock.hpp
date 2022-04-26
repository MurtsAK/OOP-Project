#include "Obstacle.hpp"

class Rock : public Obstacle
{
    SDL_Rect src, mover;
    bool isClicked = false;

public:
    Rock(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    void cutAnimation();
    void dropObstacles();
    bool getIsClicked();
    void setIsClicked();
    SDL_Rect getMov();
};