#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <map>
#include "SDL.h"
#include "SDL_image.h"

// Texture Manager handles the drawing work and rendering part of an object
// Singleton : It allows us to create only one object of a type and use it throughout our code

class TextureManager
{
private:
    TextureManager() {} // private constructor to make it a Singleton

    std::map<std::string, SDL_Texture *> textureMap; // map of pointers to the SDL_Texture objects, keyed using strings.

    // Texture Variables
    SDL_Texture *texture = NULL; // our texture variable {for images}
    SDL_Surface *surface = NULL; // surface object for drawing which is converted to texture for fast loading

    // variables for making The Texture Manager a Singleton
    static TextureManager *TMInstance;

public:
    // This function checks whether we already have an instance of our TextureManager. If
    // not, then it constructs it, otherwise it simply returns the static instance
    static TextureManager *Instance()
    {
        if (TMInstance == 0)
        {
            TMInstance = new TextureManager();
            return TMInstance;
        }
        return TMInstance;
    }

    bool load(std::string fileName, std::string id, SDL_Renderer *renderer);                // loads the image
    void draw(std::string id, int x, int y, int srcWidth, int srcHeight, int destWidth, int destHeight, SDL_Renderer *renderer); // draw static image
    // draws dynamic image, moving image
    void drawFrame(std::string id, int x, int y, int srcWidth, int srcHeight, int destWidth, int destHeight, int currentRow, int currentFrame, SDL_Renderer *renderer);
    void clean(); // cleans the textures and the surfaces
    void clearFromTextureMap(std::string id);

    ~TextureManager(); // destructor for texture manager
};

// simply giving another name
typedef TextureManager TheTextureManager;

#endif