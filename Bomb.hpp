#include "Enemy.hpp"

class Bomb : public Enemy
{
    SDL_Rect src, mover;
    bool isClicked = false;

public:
    Bomb(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    int LifeDeduct();
    void dropEnemies();
    void animateEnemy();
    bool getIsClicked();
    void setIsClicked();
    bool outOfScreen();
    SDL_Rect getMov();
};