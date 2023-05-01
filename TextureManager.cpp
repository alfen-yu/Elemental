#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *renderer)
{
    surface = IMG_Load(fileName.c_str()); // surface object

    if (surface == 0)
    {
        return false;
        std::cout << "issues with the renderer! SDL_Error: %s\n", SDL_GetError();
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
        std::cout << "issues with the renderer! SDL_Error: %s\n", SDL_GetError();
    }

    // shouldve return true from the if clause otherwise reaching here means that something bad happened
    return false;
}

// the reason for creating sdl rects twice in both functions is that if a single one was used, the next image
// drawn would create problems for the first one

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer)
{
    SDL_Rect srcRect;  // source rectangle which is a parent rectangle of destination
    SDL_Rect destRect; // destination rectangle is a subset of source rectangle

    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect.w = width;
    destRect.h = srcRect.h = height;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer)
{
    SDL_Rect srcRect;  // source rectangle which is a parent rectangle of destination
    SDL_Rect destRect; // destination rectangle is a subset of source rectangle

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    destRect.w = srcRect.w = width;
    destRect.h = srcRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::clean()
{
    SDL_FreeSurface(surface);    // for freeing the surface
    SDL_DestroyTexture(texture); // for freeing the memory taken by the texture
}