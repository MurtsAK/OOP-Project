#include "Fruit.hpp"

class Lemon : public Fruit
{
    SDL_Rect src, mover;
    bool isClicked = false;

public:
    Lemon(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    void cutAnimation();
    void dropFruits();
    bool getIsClicked();
    void setIsClicked();
    SDL_Rect getMov();
};