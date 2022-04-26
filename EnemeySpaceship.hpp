#include "Enemy.hpp"

class EnemeySpaceship : public Enemy
{
    SDL_Rect src, mover;
    bool isClicked = false;

public:
    EnemeySpaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);

    void draw(SDL_Renderer *, SDL_Texture *enemies);
    int LifeDeduct();
    void dropEnemies();
    void animateEnemy();
    bool getIsClicked();
    void setIsClicked();
    SDL_Rect getMov();
};