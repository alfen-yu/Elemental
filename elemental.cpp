#include <SDL.h>
#include <iostream>
#include "Game.h"

Game* game = 0; // Game Object

int main(int argc, char *args[])
{
    game = new Game();

    game->init("Elemental", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);


    while (game->getRunningState()) { // game loop
        game->handleEvents();
        game->render();
        // game->update();
    }

    game->clean();

    return 0;
}