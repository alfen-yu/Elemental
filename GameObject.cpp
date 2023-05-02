#include "GameObject.h"

void GameObject::load(int gx, int gy, int gwidth, int gheight, std::string gtextureID) {
    x = gx;
    y = gy; 
    width = gwidth;
    height = gheight;
    textureID = gtextureID;

    currentRow = 1;
    currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* renderer) {
    TheTextureManager::Instance()->draw(textureID, x, y, width, height, renderer);
}

void GameObject::draw(SDL_Renderer* renderer, int currentRow = 1, int currentFrame = 1) {
    TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, renderer);
}

void GameObject::update() {
    x += 0;
}