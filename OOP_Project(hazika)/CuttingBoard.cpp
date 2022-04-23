#include "CuttingBoard.hpp"
#include <iostream>
#include <time.h>
#include "Score.hpp"
#include "HealthPoints.hpp"

void CuttingBoard::deleteObjects()
{
    SDL_Rect ObjectMov;
    for (auto E : Enemies)
    {
        ObjectMov = E->getMov();
        if (ObjectMov.y > 700)
        {
            delete E;
            Enemies.remove(E);
        }
    }
    for (auto F : Fruits)
    {
        ObjectMov = F->getMov();
        if (ObjectMov.y > 700)
        {
            delete F;
            Fruits.remove(F);
        }
    }
    for (auto C : Collectibles)
    {
        ObjectMov = C->getMov();
        if (ObjectMov.y > 700)
        {
            delete C;
            Collectibles.remove(C);
        }
    }
}

void CuttingBoard::checkMouseClick(int x, int y, int &Screen)
{
    SDL_Rect getmov;
    bool isclicked;

    for (auto S : Spaceships)
    {
        S->setMov(x, y);
    }
    for (auto F : Fruits)
    {
        isclicked = F->getIsClicked();
        getmov = F->getMov();
        if (((y + 90) > getmov.y && (y - 90) < getmov.y) && ((x + 70) > getmov.x && (x - 70) < getmov.x))
        {
            if (!isclicked)
            {
                F->setIsClicked();
                F->cutAnimation();
                totalScore.ScoreUpdate();
            }
        }
    }
    for (auto E : Enemies)
    {
        isclicked = E->getIsClicked();
        getmov = E->getMov();
        if (((y + 90) > getmov.y && (y - 90) < getmov.y) && ((x + 70) > getmov.x && (x - 70) < getmov.x))
        {
            if (!isclicked)
            {
                E->setIsClicked();
                totalHealth.updateHealth(E->LifeDeduct());
                if (totalHealth.getHealth() <= 0)
                {
                    Screen = 7;
                }
            }
        }
    }
    for (auto C : Collectibles)
    {
        isclicked = C->getIsClicked();
        getmov = C->getMov();
        if (((y + 90) > getmov.y && (y - 90) < getmov.y) && ((x + 70) > getmov.x && (x - 70) < getmov.x))
        {
            if (!isclicked)
            {
                C->setIsClicked();
                C->removeCollectible();
                totalHealth.updateHealth(C->healthIncrease());
            }
        }
    }
}

void CuttingBoard::displayScore()
{
    // Score is already updated.
    // Current Score can be retrieved using totalScore.getScore()
    // Uncomment line 228
    TTF_Init();
    // Initialize SDL_ttf
    // this opens a font style and sets a size
    TTF_Font *font = TTF_OpenFont("arial.ttf", 28);

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color color = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    // string text_to_display = to_string();
    std::string score_text = std::to_string(totalScore.getScore());
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(font, score_text.c_str(), color);

    // now you can convert it into a texture
    SDL_Texture *Message = SDL_CreateTextureFromSurface(gRenderer, surfaceMessage);

    SDL_Rect Message_rect; // create a rect
    Message_rect.x = 1100; // controls the rect's x coordinate
    Message_rect.y = 60;   // controls the rect's y coordinte
    Message_rect.w = 50;   // controls the width of the rect
    Message_rect.h = 50;   // controls the height of the rect

    // (0,0) is on the top left of the window/screen,
    // think a rect as the text's box,
    // that way it would be very simple to understand

    // Now since it's a texture, you have to put RenderCopy
    // in your game loop area, the area where the whole code executes

    // you put the renderer's name first, the Message,
    // the crop size (you can ignore this if you don't want
    // to dabble with cropping), and the rect which is the size
    // and coordinate of your texture
    SDL_RenderCopy(gRenderer, Message, NULL, &Message_rect);

    // Don't forget to free your surface and texture
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);

    TTF_Quit();
}

void CuttingBoard::displayHealth()
{
    if (totalHealth.getHealth() >= 0)
    {
        SDL_Rect src = {1039, 813, 183, 183};
        SDL_Rect mover = {1100, 160, 30, 30};
        for (int i = 0; i < totalHealth.getHealth(); i++)
        {
            if (i % 3 == 0)
            {
                mover.x = 1100;
                mover.y += 40;
            }
            SDL_RenderCopy(gRenderer, assets, &src, &mover);
            mover.x += 20;
        }
    }
}

void CuttingBoard::drawObjects()
{
    bool isclicked;
    // totalHealth.displayHealth(gRenderer, assets);
    for (auto E : Enemies)
    {
        E->draw(gRenderer, assets);
        E->dropEnemies();
        isclicked = E->getIsClicked();
        if (isclicked)
        {
            E->animateEnemy();
        }
    }

    for (auto F : Fruits)
    {
        F->draw(gRenderer, assets);
        F->dropFruits();
    }
    for (auto C : Collectibles)
    {
        C->draw(gRenderer, assets);
        C->dropCollectibles();
    }
}
void CuttingBoard::drawSpaceship()
{
    bool Collision;
    for (auto S : Spaceships)
    {
        S->draw(gRenderer, assets);
    }
}

void CuttingBoard::createObject()
{
    int randomObject, randomEnemy, randomFruit, randomCollectible, randomX;
    srand(time(0));
    randomX = 1 + rand() % 10;
    randomX = 100 * randomX;
    // if (randomX == 0)
    // {
    //     randomX = 200;
    // }
    // else if (randomX == 1)
    // {
    //     randomX = 400;
    // }
    // else if (randomX == 2)
    // {
    //     randomX = 600;
    // }
    // else if (randomX == 3)
    // {
    //     randomX = 800;
    // }
    // else
    // {
    //     randomX = 1000;
    // }

    // std::cout << randomX << std::endl;

    SDL_Rect objectMov = {randomX, 10, 75, 90};

    randomObject = 1 + rand() % 100;
    if (randomObject < 61)
    {
        randomFruit = rand() % 5;
        if (randomFruit == 0)
        {
            Fruits.push_back(new Banana(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomFruit == 1)
        {
            Fruits.push_back(new Kiwi(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomFruit == 2)
        {
            Fruits.push_back(new Lemon(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomFruit == 3)
        {
            Fruits.push_back(new Orange(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else
        {
            Fruits.push_back(new Watermelon(gRenderer, assets, objectMov));
            // artificialDelay();
        }
    }
    else if (randomObject < 86)
    {
        randomEnemy = rand() % 3;
        if (randomEnemy == 0)
        {
            Enemies.push_back(new Bomb(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomEnemy == 1)
        {
            Enemies.push_back(new RottenFruit(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else
        {
            Enemies.push_back(new Fish(gRenderer, assets, objectMov));
            // artificialDelay();
        }
    }
    else
    {
        randomCollectible = rand() % 2;
        if (randomCollectible == 0)
        {
            Collectibles.push_back(new Health(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomCollectible == 1)
        {
            Collectibles.push_back(new Diamond(gRenderer, assets, objectMov));
            // artificialDelay();
        }
    }
}

// Turretmov and Bodymov creates rectangular frames at specific x,y values for each individual object
//  Turretmov have an increment of 40 in x coordinate in order to place the turret on the right edge of tank body

// Enemies.push_back(new Fish(gRenderer, assets, EnemyMov));
// Using the two objects TankBody and TankTurret, a new Tank is created dynamically everytime a mouse is clicked
void CuttingBoard::createSpaceship(int spaceship)
{
    SDL_Rect spaceship_mover = {400, 570, 100, 100};
    Spaceships.push_back(new Spaceship(gRenderer, assets, spaceship_mover, spaceship));
}
CuttingBoard::CuttingBoard(SDL_Renderer *renderer, SDL_Texture *asst, Score &totalScore, HealthPoints &totalHealth) : gRenderer(renderer), assets(asst), totalScore(totalScore), totalHealth(totalHealth)
{
}

// Deconstructor deletes all objects of Tanks and Bullets from list and clears all pointers

CuttingBoard::~CuttingBoard()
{
    // for (auto B : Bombs)
    // {
    //     delete B;
    // }
    // for (auto F : Fishes)
    // {
    //     delete F;
    // }
    // for (auto Rf : RottenFruits)
    // {
    //     delete Rf;
    // }
    // Fishes.clear();
    // Bombs.clear();
    // RottenFruits.clear();
    for (auto E : Enemies)
    {
        delete E;
    }
    for (auto F : Fruits)
    {
        delete F;
    }
    for (auto C : Collectibles)
    {
        delete C;
    }
    Collectibles.clear();
    Fruits.clear();
    Enemies.clear();
    std::cout << "Objects deleted";
}