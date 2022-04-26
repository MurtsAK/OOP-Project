#include "game.hpp"
// #include "MainMenu.hpp"
#include <vector>
#include "SpaceX.hpp"
#include "Score.hpp"
#include "HealthPoints.hpp"
#include "Spaceship.hpp"
#include <time.h>
bool Game::init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("Obstacle Ninja", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                // Initialize SDL_mixer
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool Game::loadMedia()
{
    // Loading success flag
    bool success = true;

    assets = loadTexture("assets.png");
    gTexture = loadTexture("MainMenu.png");
    if (assets == NULL || gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    gMusic = Mix_LoadMUS("bg_music.mp3");
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void Game::close()
{
    // Free loaded images
    SDL_DestroyTexture(assets);
    assets = NULL;

    SDL_DestroyTexture(gTexture);

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
}

SDL_Texture *Game::loadTexture(std::string path)
{
    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Game::run()
{
    bool quit = false;
    SDL_Event e;
    static int Screen = 0;
    if (Screen != 6)
    {
        Mix_PlayMusic(gMusic, -2);
    }
    Score totalScore(0);
    HealthPoints totalHealth(3);
    SpaceX SpaceX(gRenderer, assets, totalScore, totalHealth);
    bool objectCreated = false;
    int frameCounter = 0;
    // MainMenu MainMenu(gRenderer, assets);
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {

            int xMouse, yMouse;
            // bool mousePressed = false;

            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                // this is a good location to add pigeon in linked list.
                //  mousePressed = true;

                SDL_GetMouseState(&xMouse, &yMouse);
                std::cout << xMouse << " " << yMouse << std::endl;
                // SpaceX.createObject(xMouse, yMouse);
                // MainMenu.createObject(xMouse, yMouse);
                if (xMouse >= 142 && xMouse <= 378 && yMouse >= 456 && yMouse <= 583 && Screen == 0)
                {
                    Screen = 1;
                    gTexture = loadTexture("ABOUT_Menu.png");
                }
                else if (xMouse >= 461 && xMouse <= 695 && yMouse >= 456 && yMouse <= 583 && Screen == 0)
                {
                    Screen = 2;
                    gTexture = loadTexture("Levels.png");
                    // if (Screen == 2 && xMouse >= 405 && xMouse <= 748 && yMouse >= 36 && yMouse <= 641)
                    // {
                    //     Screen = 0;
                    //     gTexture = loadTexture("Spaceships.png");
                    // }
                }
                else if (xMouse >= 768 && xMouse <= 1006 && yMouse >= 456 && yMouse <= 583 && Screen == 0)
                {
                    Screen = 3;
                    gTexture = loadTexture("HowToPlay.png");
                }

                // if (Screen == 2 && xMouse >= 405 && xMouse <= 748 && yMouse >= 36 && yMouse <= 641 ){
                //     Screen =5;
                //     gTexture =loadTexture("GameBoard1.png");
                // }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && (Screen == 1 || Screen==2 || Screen == 3))
                {
                        gTexture = loadTexture("MainMenu.png");
                        Screen = 0;
                }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && Screen==4)
                {
                        gTexture = loadTexture("Levels.png");
                        Screen = 2;
                }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && Screen==6)
                {
                        gTexture = loadTexture("Spaceships.png");
                        Screen = 4;
                }
                else if (xMouse>=406 && xMouse<= 750 && yMouse >= 35 && yMouse<= 210 && Screen ==2)
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
                }
                else if(xMouse>=406 && xMouse<= 750 && yMouse >= 250 && yMouse<= 425 && Screen ==2)
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
<<<<<<< Updated upstream
=======
                    
>>>>>>> Stashed changes
                }
                else if(xMouse>=406 && xMouse<= 750 && yMouse >= 470 && yMouse<= 645 && Screen ==2)
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
                }
                else if(xMouse>=165 && xMouse<=400 && yMouse>=140 && yMouse<=300 && Screen == 4)
                {
                    //Spaceship 1
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(1);
                }
                else if(xMouse>=210 && xMouse<=400 && yMouse>=370 && yMouse<=545 && Screen == 4)
                {
                    //Spaceship 2
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(2);
                }
                else if(xMouse>=490 && xMouse<=660 && yMouse>=180 && yMouse<=395 && Screen == 4)
                {
                    //Spaceship 3
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(3);
                }
                else if(xMouse>=480 && xMouse<=690 && yMouse>=440 && yMouse<=565 && Screen == 4)
                {
                    //Spaceship 4
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(4);
                }
                else if(xMouse>=750 && xMouse<=980 && yMouse>=130 && yMouse<=290 && Screen == 4)
                {
                    //Spaceship 5
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(5);
                }
                else if(xMouse>=760 && xMouse<=940 && yMouse>=330 && yMouse<=560 && Screen == 4)
                {
                    //Spaceship 6
                    gTexture = loadTexture("SpaceX.png");
                    Screen = 6;
                    SpaceX.createSpaceship(6);
                }

            }
            // if (Screen == 2 and xMouse >= 404 && xMouse <= 752 && yMouse >= 36 && yMouse <= 645)
            // {
            //     gTexture = loadTexture("spaceships.png");
            //     Screen = 6;
            // }

            // if (Screen ==6 and )

            // if (e.type == SDL_MOUSEBUTTONUP)
            // {
            //     mousePressed = false;
            // }
            if (e.type == SDL_KEYDOWN){
                SpaceX.checkMouseClick(xMouse,yMouse, Screen);
                if (e.key.keysym.sym == SDLK_ESCAPE && (Screen == 1 || Screen == 2 || Screen == 3))
                {
                    gTexture = loadTexture("Mainmenu.png");
                    Screen = 0;
                }
                else if (e.key.keysym.sym == SDLK_ESCAPE && Screen == 4)
                {
                    gTexture = loadTexture("Levels.png");
                    Screen = 2;
                }
                if (e.key.keysym.sym == SDLK_SPACE && Screen == 6)
                {
                    SpaceX.getSpaceship()->createBullets();
                }
                if (e.key.keysym.sym == SDLK_LEFT && Screen == 6)
                {
                    SpaceX.getSpaceship()->moveLeft();
                }
                else if(e.key.keysym.sym == SDLK_RIGHT && Screen == 6)
                {
                    SpaceX.getSpaceship()->moveRight();
                }
            }

            // if (e.type == SDL_MOUSEMOTION && Screen == 6)
            // {
            //     SDL_GetMouseState(&xMouse, &yMouse);
            //     SpaceX.checkMouseClick(xMouse, yMouse, Screen);
            //     // if (mousePressed == true)
            //     // {
            //     //     SDL_GetMouseState(&xMouse, &yMouse);
            //     //     SpaceX.checkMouseClick(xMouse, yMouse);
            //     // }
            // }
            // if (Screen == 2 and xMouse >= 404 && xMouse <= 752 && yMouse >= 36 && yMouse <= 645)
            // {
            //     Screen = 4;
            //     // gTexture = loadTexture("SpaceX.png");
            //     gTexture = loadTexture("SpaceX.png");
            // }
            // else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && Screen == 4)
            // {
            //     Screen = 5;
            //     gTexture = loadTexture("SpaceX1.png");
            // }
            // if (Screen == 4)
            // {

            //     if (e.type == SDL_KEYDOWN)
            //     {

            //         if (e.key.keysym.sym == SDLK_1)
            //         // if (xMouse >= 169 && xMouse <= 393 && yMouse >= 144 && yMouse <= 295)
            //         {
            //             // Spaceship 1
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(1);
            //         }
            //         if (e.key.keysym.sym == SDLK_2)
            //         // if (xMouse >= 211 && xMouse <= 394 && yMouse >= 373 && yMouse <= 543)
            //         {
            //             // Spaceship 2
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(2);
            //         }
            //         if (e.key.keysym.sym == SDLK_3)
            //         // if (xMouse >= 760 && xMouse <= 980 && yMouse >= 133 && yMouse <= 287)
            //         {
            //             // Spaceship 3
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(3);
            //         }
            //         // if (xMouse >= 754 && xMouse <= 940 && yMouse >= 330 && yMouse <= 556)
            //         if (e.key.keysym.sym == SDLK_4)
            //         {
            //             // Spaceship 4
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(4);
            //         }
            //         // if (xMouse >= 493 && xMouse <= 660 && yMouse >= 181 && yMouse <= 398)
            //         if (e.key.keysym.sym == SDLK_5)
            //         {
            //             // Spaceship 5
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(5);
            //         }
            //         if (e.key.keysym.sym == SDLK_6)
            //         // if (xMouse >= 480 && xMouse <= 688 && yMouse >= 443 && yMouse <= 563)
            //         {
            //             // Spaceship 6
            //             Screen = 6;
            //             gTexture = loadTexture("SpaceX.png");
            //             SpaceX.createSpaceship(6);
            //         }
                    // if (e.key.keysym.sym == SDLK_1)
                    // else if (xMouse >= 480 && xMouse <= 688 && yMouse >= 443 && yMouse <= 563)
                    // {
                    //     // Spaceship 6
                    //     Screen = 5;
                    //     gTexture = loadTexture("SpaceX.png");
                    //     SpaceX.createSpaceship(6);
                    // }
            //     }
            // }

            // okay wala
            // if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && Screen == 5)
            // {
            //     Screen = 6;
            //     gTexture = loadTexture("SpaceX.png");
            // }
            // BattleField.fire();
        //}
        // if (Screen == 2 and xMouse >= 404 && xMouse <= 752 && yMouse >= 36 && yMouse <= 645)
        // {
        //     Screen = 6;
        //     gTexture = loadTexture("Spaceships.png");
        // }
        }
        if (Screen == 6)
        {
            srand(time(0));
            int randomWait;
            randomWait = rand() % 2;

            if (objectCreated == false)
            {
                // SDL_Delay(100);
                SpaceX.createObject();
                objectCreated = true;
                // SpaceX.artificialDelay();
            }
        }
        if (Screen == 7)
        {
            gTexture = loadTexture("GameOver.png");
        }

        SDL_RenderClear(gRenderer);                      // removes everything from renderer
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); // Draws background to renderer
        //***********************draw the objects here********************
        if (Screen >= 6)
        {
            SpaceX.drawSpaceship();
            SpaceX.drawObjects();
            SpaceX.displayScore();
            SpaceX.displayHealth();
            SpaceX.deleteObjects();
        }
        // MainMenu.drawObjects();

        //****************************************************************
        SDL_RenderPresent(gRenderer); // displays the updated renderer

        SDL_Delay(100); // causes sdl engine to delay for specified miliseconds
        frameCounter += 1;
        if (frameCounter == 15)
        {
            objectCreated = false;
            frameCounter = 0;
        }
}
}