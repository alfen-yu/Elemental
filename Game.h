#ifndef __Game__
#define __Game__
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Player.h"
#include "Cat.h"
#include <vector>

// What happens in Game Class : {Handles all the initialisation, drawing, rendering, loading textures,
//                               basically every main thing is happening in the game class}
// Game class is also a Singleton
// The reason to make this a singleton: Since game class is handling everything, therefore, we
//                                      won't be needing to create it again and again, we only need it once

class Game
{
private:
    Game() {} // constructor private to make it a singleton
    static Game *GInstance;

    bool running; // tells the loop when to stop the game

    SDL_Window *window = NULL;     // our window variable
    SDL_Renderer *renderer = NULL; // our renderering variable

    // int currentFrame; // keeps the count of the x height
    int catFrame;     // keeps the count of the x height of cat

    // objects created using game object will be passed here similar to texture manager
    std::vector<GameObject *> gameObjects;

public:
    // Singleton code
    static Game *Instance()
    {
        if (GInstance == 0)
        {
            GInstance = new Game();
            return GInstance;
        }
        return GInstance;
    }

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags); // handles initialisation of: SDL, Window, Renderer
    void handleEvents();                                                                // handles new input
    void render();                                                                      // renders to new events
    void update();                                                                      // updates the rendering to the screen
    void clean();                                                                       // cleans the game

    // getter function for running variable
    bool getRunningState()
    {
        return running;
    }

    SDL_Renderer *getRenderer() const { return renderer; }

    ~Game(); // destructor
};

// type definition for the game object
typedef Game TheGame;

#endif