#include "TextureManager.h"

TextureManager *TextureManager::TMInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *renderer)
{
    surface = IMG_Load(fileName.c_str()); // surface object

    if (surface == 0)
    {
        return false;
        std::cout << "issues with loading surface! SDL_Error: %s\n", SDL_GetError();
    }

    // surface is run on processor, texture is run on GPU therefore faster
    texture = SDL_CreateTextureFromSurface(renderer, surface); // creates a texture from a surface
    if (texture != 0)
    {
        // getting in here is assumed that the texture was created successfully
        textureMap[id] = texture;
        return true;
    }
    else
    {
        std::cout << "issues with the texture! SDL_Error: %s\n", SDL_GetError();
    }

    // shouldve return true from the if clause otherwise reaching here means that something bad happened
    return false;
}

// the reason for creating sdl rects twice in both functions is that if a single one was used, the next image
// drawn would create problems for the first one

void TextureManager::draw(std::string id, int x, int y, int srcWidth, int srcHeight, int destWidth, int destHeight, SDL_Renderer *renderer)
{
    SDL_Rect srcRect;  // source rectangle which is a parent rectangle of destination
    SDL_Rect destRect; // destination rectangle is a subset of source rectangle

    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = x;
    destRect.y = y;
    srcRect.w = srcWidth;
    srcRect.h = srcHeight;
    destRect.w = destWidth;
    destRect.h = destHeight;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawFrame(std::string id, int x, int y, int srcWidth, int srcHeight, int destWidth, int destHeight, int currentRow, int currentFrame, SDL_Renderer *renderer)
{
    SDL_Rect srcRect;  // source rectangle which is a parent rectangle of destination
    SDL_Rect destRect; // destination rectangle is a subset of source rectangle

    srcRect.x = srcWidth * currentFrame;
    srcRect.y = srcHeight * currentRow;

    srcRect.w = srcWidth;
    srcRect.h = srcHeight;

    destRect.w = destWidth;
    destRect.h = destHeight;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::clearFromTextureMap(std::string id) {
    textureMap.erase(id);
}

void TextureManager::clean()
{
    SDL_FreeSurface(surface);    // for freeing the surface
    SDL_DestroyTexture(texture); // for freeing the memory taken by the texture
    // delete TMInstance;
    // delete TextureManager::TMInstance;
    // delete TextureManager::Instance();
    // TextureManager::TMInstance = nullptr;
    // texture = nullptr;
    // surface = nullptr;
    std::cout << "Texture Manager Cleaned \n";
}

// destructor definition for the texture manager
TextureManager::~TextureManager() {
    std::cout << "Texture Manager Destructor Called \n";
}