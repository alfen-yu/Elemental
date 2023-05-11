#include <SDL.h>
#include <iostream>
#include "Game.h"

int windowFlags;

// Fixed Frame Rate between loops to update the objects
const int FPS = 60; // frames per second
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *args[])
{
    Uint32 frameStart, frameTime;

    windowFlags = SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;

    if (TheGame::Instance()->init("Elemental", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, windowFlags))
    {
        while (TheGame::Instance()->getRunningState())
        {
            frameStart = SDL_GetTicks(); // ticks/time when the loops starts

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            // how long it took to run the instructions "subtracted with" the ticks when the loop starts
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }

    TheGame::Instance()->clean();

    return 0;
}