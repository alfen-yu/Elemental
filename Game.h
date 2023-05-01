#ifndef __Game__
#define __Game__
#include "SDL.h"
#include <iostream>

class Game {
    private:
        bool running; // tells the loop when to stop the game

        SDL_Window *window = NULL;     // our window variable
        SDL_Renderer *renderer = NULL; // our renderering variable

        // Texture Variables
        SDL_Texture* texture = NULL;  // our texture variable {for images}
        SDL_Surface* surface = NULL;
        SDL_Rect srcRect; // rectangle 1 
        SDL_Rect destRect;     // rectangle 2

    public:
        Game(){}
        ~Game(){}

        bool init(const char *title, int xpos, int ypos, int width, int height, int flags); // handles initialisation of: SDL, Window, Renderer
        void handleEvents(); // handles new input
        void render(); // renders to new events
        void update(); // updates the rendering to the screen
        void clean(); // cleans the game

        // getter function for running variable 
        bool getRunningState() {
            return running;
        }
};


#endif