#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <map>
#include "SDL.h"
#include "SDL_image.h"

class TextureManager
{
private:
    std::map<std::string, SDL_Texture *> textureMap; // map of pointers to the SDL_Texture objects, keyed using strings.

    // Texture Variables
    SDL_Texture *texture = NULL; // our texture variable {for images}
    SDL_Surface *surface = NULL; // surface object for drawing which is converted to texture for fast loading

public:
    TextureManager() {} // constructor

    bool load(std::string fileName, std::string id, SDL_Renderer *renderer);                // loads the image
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer); // draw static image
    // draws dynamic image, moving image
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer);
    void clean(); // cleans the textures and the surfaces

    ~TextureManager(); // destructor for texture manager
};

#endif