#include "Game.h"

Game *Game::GInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    // initialize SDL
    int initialiser = SDL_Init(SDL_INIT_EVERYTHING);

    if (initialiser >= 0)
    { // returns -1 if unsuccessful
        // if initialisation is successful then create our window
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        // if window was a success then create renderer
        if (window != NULL)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (!TheTextureManager::Instance()->load("assests/sprite.bmp",
                                                     "hero", renderer))
            {
                return false;
            }

            if (!TheTextureManager::Instance()->load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Run.png",
                                                     "cat", renderer))
            {
                return false;
            }
            if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/mainImage1.png",
                                                     "background", renderer))
            {
                return false;
            }
            gameObjects.push_back(new Player(new LoaderParams(0, 0, 64, 64, "hero")));
            gameObjects.push_back(new Cat(new LoaderParams(100, 100, 50, 50, "cat")));
        }
        else
        {
            std::cout << "SDL could not create renderer! SDL_Error: %s\n", SDL_GetError();
            // SDL was unable to create a window
            return false;
        }
    }
    else
    {
        std::cout << "SDL could not create window! SDL_Error: %s\n", SDL_GetError();
        return false; // SDL was unable to create window and returns false
    }

    running = true;
    return true; // returns true if the function was a success
}

// handling user inputs and events
void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

// rendering on the screen
void Game::render()
{
    if (renderer != NULL)
    {
        // if everyting works fine then draw on the window
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // gives the color to the renderer
        SDL_RenderClear(renderer);                            // cleans the renderer to draw the color

        // drawings
        TheTextureManager::Instance()->draw("background", 0, 0, 1400, 800, renderer);
        // TheTextureManager::Instance()->draw("hero", 0, 0, 32, 48, renderer);
        // TheTextureManager::Instance()->drawFrame("hero", 100, 100, 32, 48, 1, currentFrame, renderer);
        // TheTextureManager::Instance()->drawFrame("cat", 200, 200, 50, 50, 1, catFrame, renderer);

        // loops through all the objects and create them according to their id
        // the loop doesnt care what the type of object is, it just creates it
        for (std::vector<GameObject *>::size_type i = 0; i != gameObjects.size(); i++)
        {
            gameObjects[i]->draw();
        }
        SDL_RenderPresent(renderer); // presents the color on the screen
    }
    else
    {
        std::cout << "issues with the renderer! SDL_Error: %s\n", SDL_GetError();
    }
}

void Game::update()
{
    for (std::vector<GameObject *>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Game::clean()
{
    delete Game::GInstance;
    Game::GInstance = nullptr;

    delete Game::Instance();
    delete Game::getRenderer();
    std::cout << "Game Specific Variables Cleaned \n";

    TheTextureManager::Instance()->clean(); // texture cleaning takes place here
    TheInputHandler::Instance()->clean();
}

Game::~Game()
{
    // // GameObject::clean();
    // // SDLGameObject::clean();
    // std::cout << "Other Objects Cleaned \n";
    SDL_DestroyWindow(window);     // frees up the space taken by the window
    SDL_DestroyRenderer(renderer); // frees up the space taken by the renderer
    // renderer = nullptr;
    // window = nullptr;
    SDL_Quit(); // cleans SDL
    std::cout << "Game Cleaned \n";
    std::cout << "Game Destructor Called \n";
};