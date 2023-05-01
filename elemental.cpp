#include <SDL.h>
#include <iostream>
#include "Game.h"

Game *game = 0; // Game Object
int windowFlags;

int main(int argc, char *args[])
{
    game = new Game();
    windowFlags = SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

    game->init("Elemental", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, windowFlags);

    while (game->getRunningState())
    { // game loop
        game->handleEvents();
        game->render();
        // game->update();
    }

    game->clean();

    return 0;
}