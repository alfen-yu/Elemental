#include "Game.h"

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
            // surface is run on processor, texture is run on GPU therefore faster
            surface = IMG_Load("assests/mainPlayer.png"); // surface object
            texture = SDL_CreateTextureFromSurface(renderer, surface);           // creates a texture from a surface
            srcRect.w = 32; // for the main player
            srcRect.h = 48; // for the main player
            destRect.x = srcRect.x = 0;
            destRect.y = srcRect.y = 0;
            destRect.w = srcRect.w;
            destRect.h = srcRect.h;
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
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT: // handles the quit functionality, on click the x button
            running = false;
            break;
        default:
            break;
        }
    }
}

// rendering on the screen
void Game::render()
{
    if (renderer != NULL)
    {
        // if everyting works fine then draw on the window
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);              // gives the color to the renderer
        SDL_RenderClear(renderer);                                         // cleans the renderer to draw the color
        SDL_RenderCopy(renderer, texture, &srcRect, &destRect); // copy the image to the render target
        // SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);                                       // presents the color on the screen
    }
    else
    {
        std::cout << "issues with the renderer! SDL_Error: %s\n", SDL_GetError();
    }
}

void Game::update()
{
    srcRect.x = 32 * int((SDL_GetTicks() / 100) % 4);
}

void Game::clean()
{
    std::cout << "cleaning game \n";
    SDL_DestroyWindow(window); // frees up the space taken by the window
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer); // frees up the space taken by the renderer
    SDL_Quit();                    // cleans SDL
}