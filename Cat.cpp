#include "Cat.h"

void Cat::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x, y, width, height, textureID);
}

void Cat::draw(SDL_Renderer* renderer) {
    GameObject::draw(renderer, currentRow, currentFrame);
}

void Cat::update() {
    x += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 8);
}