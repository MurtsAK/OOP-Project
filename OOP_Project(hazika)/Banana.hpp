#include "Fruit.hpp"

class Banana : public Fruit
{
    SDL_Rect src, mover;
    bool isClicked = false;

public:
    Banana(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    void cutAnimation();
    void dropFruits();
    bool getIsClicked();
    void setIsClicked();
    SDL_Rect getMov();
};