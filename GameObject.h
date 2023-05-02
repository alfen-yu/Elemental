#ifndef __GameObject__
#define __GameObject__
#include <iostream>
#include "SDL.h"
#include "TextureManager.h"

// Game Object is like the parent class that handles the creation of every object in the game to avoid redundancy
class GameObject {
    protected:
        // variables for loading an image
        int x, y;
        std::string textureID;
        int currentFrame, currentRow;
        int width, height;
    public:
        // virtual keywords ensures overridden behaviour
        virtual void load(int x, int y, int width, int height, std::string textureID);
        virtual void draw(SDL_Renderer* renderer);
        virtual void draw(SDL_Renderer* renderer, int currentRow, int currentFrame);
        virtual void update();
        // virtual void clean();
};

#endif 