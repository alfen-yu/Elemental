#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <map>
#include "SDL.h"

class TextureManager
{
private:
    std::map<std::string, SDL_Texture *> textureMap; // map of pointers to the SDL_Texture objects, keyed using strings.
public:
    bool load(std::string fileName, std::string id, SDL_Renderer *renderer);                // loads the image
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer); // draw static image
    // draws dynamic image
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer);
};

#endif