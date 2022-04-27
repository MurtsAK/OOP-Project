#include "SpaceX.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include "Score.hpp"
#include "HealthPoints.hpp"
using namespace std;

void SpaceX::deleteObjects()
{
    SDL_Rect ObjectMov;
    for (auto E : Enemies)
    {
        ObjectMov = E->getMov();
        if (ObjectMov.y > 700) // if enemy out of screen, destroy it
        {
            delete E;
            Enemies.remove(E);
        }
    }
    for (auto F : Obstacles)
    {
        ObjectMov = F->getMov();
        if (ObjectMov.y > 700) // if obstacle out of screen, destroy it
        {
            delete F;
            Obstacles.remove(F);
        }
    }
    for (auto C : Collectibles)
    {
        ObjectMov = C->getMov();
        if (ObjectMov.y > 700) // if collectible out of screen, destroy it
        {
            delete C;
            Collectibles.remove(C);
        }
    }
}

void SpaceX::checkMouseClick(int x, int y, int &Screen) // fucntion where objects of the game are interacting with the bullets and co.
{
    SDL_Rect getmov;              // variable to store movements and locations of enemies, collectibles & obstacles
    SDL_Rect spaceship_loc;       // variable to store movements and locations of spaceship chosen
    SDL_Rect bullet_loc;          // variable to store movement and location of bullet fired
    bool isclicked;               // boolean variable to confirm collision
    list<Bullets *> bullets_list; // variable to store every bullet fired, for use in locating

    bullets_list = spaceship_in_game->getBullets();
    spaceship_loc = spaceship_in_game->getMov();
    int m = 0;
    for (auto B : bullets_list)
    {
        bullet_loc = B->getLocation(); // get bullet location
        // cout << "bullet location X: " << bullet_loc.x << " Y: " << bullet_loc.y << endl;

        for (auto F : Obstacles) // first loop around every obstacle present on screen
        {
            isclicked = F->getIsClicked(); // get status of wether collision has happened or not
            getmov = F->getMov();          // get obstacles location
            // cout << "obstacle location X: " << getmov.x << " Y: " << getmov.y << endl;

            // if ((((bullet_loc.x + 10) > getmov.x) && ((bullet_loc.x) < getmov.x)) && (((bullet_loc.y + 10) > getmov.y) && ((bullet_loc.y) < getmov.y)))
            if (!isclicked)
            {
                if (SDL_HasIntersection(&bullet_loc, &getmov))
                {
                    cout << "inside isclicked" << endl;
                    F->setIsClicked();
                    F->cutAnimation();
                    B->removeBullet();
                    totalScore.ScoreUpdate();
                    // list<Bullets*>::iterator it4 = bullets_list.begin();
                    // advance(it4,m);
                    // bullets_list.erase(it4);
                    // delete B;
                }

                cout << "collide" << endl;
            }
            m++;
        }
        for (auto E : Enemies) // now loop over all enemies
        {
            isclicked = E->getIsClicked();  // get status of collision
            getmov = E->getMov();           // get movement and location of enemy
            if (spaceship_loc.y < getmov.y) // if the enemy goes through the screen unharmed you lose health
            {
                if (!isclicked)
                {
                    E->setIsClicked();                         // status changed to collided
                    totalHealth.updateHealth(E->LifeDeduct()); // reduce health by 1 point
                    if (totalHealth.getHealth() <= 0)          // if health goes to 0, game over
                    {
                        Screen = 7; // game over screen
                    }
                }
            }
            // else if ((((bullet_loc.x + 10) > getmov.x) && ((bullet_loc.x) < getmov.x)) && (((bullet_loc.y + 10) > getmov.y) && ((bullet_loc.y) < getmov.y)))
            else if (SDL_HasIntersection(&bullet_loc, &getmov))
            {
                E->setIsClicked();
                E->animateEnemy();
                totalScore.ScoreUpdate();
                B->removeBullet();
            }
        }
        for (auto C : Collectibles) // finally, loop over all collectibles present on screen
        {
            string checker = typeid(*C).name();
            // cout <<"hello  " << checker << endl;
            isclicked = C->getIsClicked();
            getmov = C->getMov();
            // if ((((spaceship_loc.x + 10) > getmov.x) && ((spaceship_loc.x) < getmov.x)) && (((spaceship_loc.y + 10) > getmov.y) && ((spaceship_loc.y) < getmov.y)))
            if (SDL_HasIntersection(&spaceship_loc, &getmov))
            {
                if (!isclicked)
                {
                    if (checker == "7Diamond")
                    {
                        C->setIsClicked();      // change status to obtained
                        C->removeCollectible(); // remove collectible from screen
                        totalHealth.updateGems();
                    }
                    else
                    {
                        C->setIsClicked();                             // change status to obtained
                        C->removeCollectible();                        // remove collectible from screen
                        totalHealth.updateHealth(C->healthIncrease()); // increase user health by 1 point
                    }
                }
            }
        }
    }
}

//  void SpaceX::collisionDetection(SDL_Rect b, SDL_Rect sp) {
//     for(int c=0; b.x; c++) {
//         for(int r=0; r<b.y; r++) {
//             var check = b[c][r];
//             if(sp.x > check.x && sp.x < b.x+b.w && sp.y > check.y && sp.y < check.y+b.h) {
//                 dy = -dy;
//             }
//         }
//     }
//}

void SpaceX::displayScore()
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

void SpaceX::displayHealth()
{
    if (totalHealth.getHealth() >= 0) // if game not over essentially
    {
        SDL_Rect src = {1039, 813, 183, 183};
        SDL_Rect mover = {1100, 300, 50, 50};
        for (int i = 0; i < totalHealth.getHealth(); i++)
        {
            if (i % 3 == 0)
            { // positioning of health icons on screen
                mover.x = 1100;
                mover.y += 40;
            }
            SDL_RenderCopy(gRenderer, assets, &src, &mover);
            mover.x += 20;
        }
    }
    if (totalHealth.getGems() >= 0) // if game not over essentially
    {
        SDL_Rect srcGem = {1272, 850, 164, 156};
        SDL_Rect moverGem = {30, 350, 30, 30};
        for (int i = 0; i < totalHealth.getGems(); i++)
        {
            if (i % 3 == 0)
            { // positioning of health icons on screen
                moverGem.x = 1100;
                moverGem.y += 40;
            }
            SDL_RenderCopy(gRenderer, assets, &srcGem, &moverGem);
            moverGem.x += 20;
        }
    }
}

void SpaceX::drawObjects()
{
    bool isclicked;
    int i = 0;
    int j = 0;
    int k = 0;
    // totalHealth.displayHealth(gRenderer, assets);
    for (auto E : Enemies)
    {
        if (!E->outOfScreen())
        {
            E->draw(gRenderer, assets, E->getSrc() , E->getMov()); // draw enemies on screen
            E->dropEnemies();           // drop them from the top
            isclicked = E->getIsClicked();
            if (isclicked)
            {
                E->animateEnemy();
            }
        }
        else
        {
            list<Enemy *>::iterator it1 = Enemies.begin();
            advance(it1, i);
            Enemies.erase(it1);
            delete E; // if out of screen, delete enemy object
        }
        i++;
    }

    for (auto F : Obstacles) // exactly same function as above for enemies objects
    {
        if (!F->outOfScreen())
        {
            F->draw(gRenderer, assets,F->getSrc(),F->getMov());
            F->dropObstacles();
        }
        else
        {
            list<Obstacle *>::iterator it2 = Obstacles.begin();
            advance(it2, j);
            Obstacles.erase(it2);
            delete F;
        }
    }
    for (auto C : Collectibles) // exactly same functions as above for enemies and obstaces objects
    {
        if (!C->outOfScreen())
        {
            C->draw(gRenderer, assets,C->getSrc(),C->getMov());
            C->dropCollectibles();
        }
        else
        {
            list<Collectible *>::iterator it3 = Collectibles.begin();
            advance(it3, k);
            Collectibles.erase(it3);
            delete C;
        }
    }
}
void SpaceX::drawSpaceship() // function to draw chosen spaceship
{
    bool Collision;
    spaceship_in_game->draw(gRenderer, assets);
}

Spaceship *SpaceX::getSpaceship() // function to return pointer of the spaceship object
{
    return spaceship_in_game;
}

void SpaceX::createObject() // function to make spacehsip
{
    int randomObject, randomEnemy, randomObstacle, randomCollectible, randomX;
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
        randomObstacle = rand() % 5;
        if (randomObstacle == 0)
        {
            Obstacles.push_back(new RedAsteroid(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomObstacle == 1)
        {
            Obstacles.push_back(new YellowEnemy(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomObstacle == 2)
        {
            Obstacles.push_back(new Rock(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else if (randomObstacle == 3)
        {
            Obstacles.push_back(new BlueAsteroid(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else
        {
            Obstacles.push_back(new Shuriken(gRenderer, assets, objectMov));
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
            Enemies.push_back(new BlueRing(gRenderer, assets, objectMov));
            // artificialDelay();
        }
        else
        {
            Enemies.push_back(new EnemySpaceship(gRenderer, assets, objectMov));
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

// Enemies.push_back(new EnemySpaceship(gRenderer, assets, EnemyMov));
// Using the two objects TankBody and TankTurret, a new Tank is created dynamically everytime a mouse is clicked
void SpaceX::createSpaceship(int spaceship)
{
    SDL_Rect spaceship_mover = {400, 570, 100, 100};
    spaceship_in_game = new Spaceship(gRenderer, assets, spaceship_mover, spaceship);
}
SpaceX::SpaceX(SDL_Renderer *renderer, SDL_Texture *asst, Score &totalScore, HealthPoints &totalHealth) : gRenderer(renderer), assets(asst), totalScore(totalScore), totalHealth(totalHealth)
{
}

// Deconstructor deletes all objects of Tanks and Bullets from list and clears all pointers

SpaceX::~SpaceX()
{
    // for (auto B : Bombs)
    // {
    //     delete B;
    // }
    // for (auto F : EnemySpaceshipes)
    // {
    //     delete F;
    // }
    // for (auto Rf : BlueRings)
    // {
    //     delete Rf;
    // }
    // EnemySpaceshipes.clear();
    // Bombs.clear();
    // BlueRings.clear();
    for (auto E : Enemies)
    {
        delete E;
    }
    for (auto F : Obstacles)
    {
        delete F;
    }
    for (auto C : Collectibles)
    {
        delete C;
    }
    delete spaceship_in_game;
    spaceship_in_game = NULL;
    Collectibles.clear();
    Obstacles.clear();
    Enemies.clear();
    std::cout << "Objects deleted";
}