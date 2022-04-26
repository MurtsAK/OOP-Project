#include "game.hpp"
// #include "MainMenu.hpp"
#include <vector>
#include "SpaceX.hpp"
#include "Score.hpp"
#include "HealthPoints.hpp"
#include "Spaceship.hpp"
#include <time.h>
bool Game::init() //this is our game initliaziting function 
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

bool Game::loadMedia() //this function will load all our media including our main menu screen, playing screen, assests and sounds.
{
    // Loading success flag
    bool success = true;

    assets = loadTexture("assets.png"); //getting assests
    gTexture = loadTexture("MainMenu.png"); //getting our mainmenu screen
    if (assets == NULL || gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    gMusic = Mix_LoadMUS("bg_music.mp3"); //getting the background music
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void Game::close() //this function would close the game when it ended naturally or forcefully ended by the user
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

void Game::run() //this is the most important function of out game class which helps in the dynamicity and running of our game
{
    bool quit = false;
    SDL_Event e;
    static int Screen = 0;
    if (Screen != 6)
    {
        Mix_PlayMusic(gMusic, -2);
    }
    Score totalScore(0); //initializing score
    HealthPoints totalHealth(3); //initializing health
    SpaceX SpaceX(gRenderer, assets, totalScore, totalHealth); //initiliazing our game screen
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

                SDL_GetMouseState(&xMouse, &yMouse);
                std::cout << xMouse << " " << yMouse << std::endl; //outputting our mouse clicks
                if (xMouse >= 142 && xMouse <= 378 && yMouse >= 456 && yMouse <= 583 && Screen == 0) //checking when the about button is pressed by checking the coordinates
                {
                    Screen = 1;
                    gTexture = loadTexture("ABOUT_Menu.png");
                }
                else if (xMouse >= 461 && xMouse <= 695 && yMouse >= 456 && yMouse <= 583 && Screen == 0) //checking when the levels button is pressed by checking the coordinates
                {
                    Screen = 2;
                    gTexture = loadTexture("Levels.png");
                }
                else if (xMouse >= 768 && xMouse <= 1006 && yMouse >= 456 && yMouse <= 583 && Screen == 0)  //checking when the how to play button is pressed by checking the coordinates
                {
                    Screen = 3;
                    gTexture = loadTexture("HowToPlay.png");
                }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && (Screen == 1 || Screen==2 || Screen == 3))  //checking when the console button on the top left is pressed by checking the coordinates
                {
                        gTexture = loadTexture("MainMenu.png");
                        Screen = 0;
                }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && Screen==4)  //checking when the console button is pressed by checking the coordinates while on screen 4
                {
                        gTexture = loadTexture("Levels.png");
                        Screen = 2;
                }
                else if (xMouse >= 19 && xMouse <= 67 && yMouse >= 26 && yMouse <= 64 && Screen==6) //checking when the console button is pressed by checking the coordinates while on screen 6
                {
                        gTexture = loadTexture("Spaceships.png");
                        Screen = 4;
                }
                else if (xMouse>=406 && xMouse<= 750 && yMouse >= 35 && yMouse<= 210 && Screen ==2) //checking the coordinate for the respective level and then loading the spaceship screen
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
                }
                else if(xMouse>=406 && xMouse<= 750 && yMouse >= 250 && yMouse<= 425 && Screen ==2)  //checking the coordinate for the respective level and then loading the spaceship screen
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
                }
                else if(xMouse>=406 && xMouse<= 750 && yMouse >= 470 && yMouse<= 645 && Screen ==2) //checking the coordinate for the respective level and then loading the spaceship screen
                {
                    gTexture = loadTexture("Spaceships.png");
                    Screen = 4;
                }

                //the next set of else if statements would check that which spaceship is selected by checking the coordinate of each spaceship and then loading the main playing screen
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
            if (e.type == SDL_KEYDOWN){
                SpaceX.checkMouseClick(xMouse,yMouse, Screen);
                //implementing going back when the escape key is pressed
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
                // pressing space fires the bullets
                if (e.key.keysym.sym == SDLK_SPACE && Screen == 6)
                {
                    SpaceX.getSpaceship()->createBullets();
                }

                //pressing left right arrow keys moves the spaceship
                if (e.key.keysym.sym == SDLK_LEFT && Screen == 6)
                {
                    //operator overloading 
                    ++(*SpaceX.getSpaceship());
                }
                else if(e.key.keysym.sym == SDLK_RIGHT && Screen == 6)
                {
                    //operator overloading
                    (*SpaceX.getSpaceship())++;
                }
            }
        }
        if (Screen == 6)
        {
            srand(time(0));
            int randomWait;
            randomWait = rand() % 2;
            //checking if there is any object created on the game screen
            if (objectCreated == false)
            {
                // SDL_Delay(100);
                SpaceX.createObject();
                objectCreated = true;
                // SpaceX.artificialDelay();
            }
        } 
        //at the end displaying the game over screen 
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