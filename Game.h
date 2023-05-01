#ifndef __Game__
#define __Game__
#include "SDL.h"
#include <iostream>

class Game {
    private:
        bool running; // tells the loop when to stop the game

        SDL_Window *window = 0;     // our window variable
        SDL_Renderer *renderer = 0; // our renderering variable

    public:
        Game(){}
        ~Game(){}

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags); // handles initialisation of: SDL, Window, Renderer
    void handleEvents(); // handles new input
    void render(); // renders to new events
    // void update(); // updates the rendering to the screen
    void clean(); // cleans the game

    // getter function for running variable 
    bool getRunningState() {
        return running;
    }
};

#endif