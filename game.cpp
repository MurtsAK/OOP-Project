#include "game.hpp"
// #include "MainMenu.hpp"
#include <vector>
#include "CuttingBoard.hpp"
#include "Score.hpp"
#include "HealthPoints.hpp"
#include "Spaceship.hpp"
#include <time.h>
bool Game::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO ||SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                	  //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool Game::loadMedia()
{
    //Loading success flag
    bool success = true;

    assets = loadTexture("assets.png");
    gTexture = loadTexture("MainMenu.png");
    if (assets == NULL || gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }
    gMusic = Mix_LoadMUS( "bg_music.mp3" );
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void Game::close()
{
    //Free loaded images
    SDL_DestroyTexture(assets);
    assets = NULL;
    SDL_DestroyTexture(gTexture);

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
}

SDL_Texture *Game::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture *newTexture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Game::run()
{
    bool quit = false;
    SDL_Event e;
    static int Screen = 0;
    if (Screen !=4){
        Mix_PlayMusic(gMusic, -2);
    }
    Score totalScore(0);
    HealthPoints totalHealth(3);
    CuttingBoard CuttingBoard(gRenderer, assets, totalScore, totalHealth);
    bool objectCreated = false;
    int frameCounter = 0;
    // MainMenu MainMenu(gRenderer, assets);
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {

            int xMouse, yMouse;
            // bool mousePressed = false;

            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                //this is a good location to add pigeon in linked list.
                // mousePressed = true;

                SDL_GetMouseState(&xMouse, &yMouse);
                // std::cout << xMouse << " " << yMouse << std::endl;
                // CuttingBoard.createObject(xMouse, yMouse);
                // MainMenu.createObject(xMouse, yMouse);
                if (xMouse >= 47 && xMouse <= 580 && yMouse >= 473 && yMouse <= 530 && Screen == 0)
                {
                    Screen = 1;
                    gTexture = loadTexture("ABOUT_Menu.png");
                }
                if (xMouse >= 207 && xMouse <= 405 && yMouse >= 384 && yMouse <= 436 && Screen == 0)
                {
                    Screen = 2;
                    gTexture = loadTexture("GameBoard1.png");
                }
                if (xMouse >= 221 && xMouse <= 408 && yMouse >= 568 && yMouse <= 622 && Screen == 0)
                {
                    Screen = 3;
                    gTexture = loadTexture("HowToPlay.png");
                }
                if (Screen != 0 && Screen != 2 && Screen != 4)
                {
                    if (xMouse >= 1087 && xMouse <= 1166 && yMouse >= 50 && yMouse <= 124)
                    {
                        gTexture = loadTexture("MainMenu.png");
                        Screen = 0;
                    }
                }
            }
            if (Screen == 2){
            if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_1){
                    //Spaceship 1
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(1);
                }
                if (e.key.keysym.sym == SDLK_2){
                    //Spaceship 2
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(2);
                }
                if (e.key.keysym.sym == SDLK_3){
                    //Spaceship 3
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(3);
                }
                if (e.key.keysym.sym == SDLK_4){
                    //Spaceship 4
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(4);
                }
                if (e.key.keysym.sym == SDLK_5){
                    //Spaceship 5
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(5);
                }
                if (e.key.keysym.sym == SDLK_6){
                    //Spaceship 6
                    Screen = 4;
                    gTexture = loadTexture("CuttingBoard.png");
                    CuttingBoard.createSpaceship(6);
                }
                }
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE && (Screen == 1 || Screen == 2 || Screen == 3)){
                gTexture = loadTexture("Mainmenu.png");
                Screen = 0;
            }

            // if (e.type == SDL_MOUSEBUTTONUP)
            // {
            //     mousePressed = false;
            // }

            if (e.type == SDL_MOUSEMOTION && Screen == 4)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
                CuttingBoard.checkMouseClick(xMouse, yMouse, Screen);
                // if (mousePressed == true)
                // {
                //     SDL_GetMouseState(&xMouse, &yMouse);
                //     CuttingBoard.checkMouseClick(xMouse, yMouse);
                // }
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && Screen == 2)
            {
                Screen = 4;
                gTexture = loadTexture("CuttingBoard.png");
            }
            // // BattleField.fire();
        }
        if (Screen == 4)
        {
            srand(time(0));
            int randomWait;
            randomWait = rand() % 10;
            if (objectCreated == false)
            {
                // SDL_Delay(100);
                CuttingBoard.createObject();
                objectCreated = true;
                // CuttingBoard.artificialDelay();
            }
        }
        if (Screen == 5)
        {
            gTexture = loadTexture("GameOver.png");
        }

        SDL_RenderClear(gRenderer);                      //removes everything from renderer
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //Draws background to renderer
        //***********************draw the objects here********************
        if (Screen >= 4)
        {
            CuttingBoard.drawSpaceship();
            CuttingBoard.drawObjects();
            CuttingBoard.displayScore();
            CuttingBoard.displayHealth();
            CuttingBoard.deleteObjects();
        }
        // MainMenu.drawObjects();

        //****************************************************************
        SDL_RenderPresent(gRenderer); //displays the updated renderer

        SDL_Delay(200); //causes sdl engine to delay for specified miliseconds
        frameCounter += 1;
        if (frameCounter == 15)
        {
            objectCreated = false;
            frameCounter = 0;
        }
    }
}
