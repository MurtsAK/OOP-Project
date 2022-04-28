#include "Spaceship.hpp"

Spaceship::Spaceship(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int spaceship) : gRenderer(rend), assets(ast)
{ //defining coordinates for each spaceship from the assets file
    mover = mov;
    spaceship_type = spaceship;
    // src = {10, 144, 86, 80};
    if (spaceship == 1)
    {
        // src = {41,644,418,425};
        src = {41, 1677, 194, 134};
    }
    else if (spaceship == 2)
    {
        // src = {21,2312,1558,1517};
        src = {37, 1913, 202, 166};
    }
    else if (spaceship == 3)
    {
        // src = {907,1277,920,977};
        src = {37, 3705, 202, 266};
    }
    else if (spaceship == 4)
    {
        // src = {1067,617,555,644};
        src = {73, 1181, 130, 102};
    }
    else if (spaceship == 5)
    {
        // src = {532,639,448,465};
        src = {41, 2161, 194, 170};
    }
    else if (spaceship == 6)
    {
        // src = {188,1315,532,790};
        src = {37, 4089, 202, 258};
    }
}

void Spaceship::draw(SDL_Renderer *gRenderer, SDL_Texture *assets) //drwaing the spacehship
{
    if (!bullets.empty()){
        restTime+=1;
    }
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
    int i=0;
    for (auto B :  bullets){
        if (!B->outOfScreen()){
            B->draw(gRenderer,assets);
            ++(*B); //operator overloading for bullets which moves them
        }else{
            list<Bullets*>::iterator it = bullets.begin();
            advance(it,i);
            bullets.erase(it);
            delete B;
        }
        i++;
    }
}

void Spaceship::operator ++ (){ //operator overloading for horizontal movement
    if(mover.x>1){
        mover.x -= 50;
    }
}

void Spaceship::operator ++ (int y){ //operator overloading for horizontal movement
    if(mover.x<1100){
        mover.x += 50;
    }
}

void Spaceship::blastAnimation() {}

void Spaceship::createBullets() //creating bullets for the spaceship when spacebar is pressed
{
    if (bullets.empty()){
        bullets.push_back(new Bullets(gRenderer, assets, mover, spaceship_type));
    }else{
    if (restTime>5){
        bullets.push_back(new Bullets(gRenderer, assets, mover, spaceship_type));
        restTime=0;
    }
    }
}

void Spaceship::Fire() {}

SDL_Rect Spaceship::getMov() //movement checker
{
    return mover;
}

bool Spaceship::getCollision() {}

void Spaceship::setCollision() {}

Spaceship::~Spaceship() //destructor destroying the spaceship when game ended
{
    for (auto B : bullets){
        delete B;
    }
    bullets.clear();
}

list<Bullets*> Spaceship::getBullets() //list of bullets fired
{
    return bullets;
}