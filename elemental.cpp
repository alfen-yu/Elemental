#include <SDL.h>
#include <iostream>
#include "Game.h"

int windowFlags;

int main(int argc, char *args[])
{
    windowFlags = SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

    if (TheGame::Instance()->init("Elemental", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, windowFlags))
    {
        while (TheGame::Instance()->getRunningState())
        {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->render();
            TheGame::Instance()->update();

            SDL_Delay(10);
        }
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }

    // handling memory leaks
    delete TheGame::Instance();

    return 0;
}