#include "Cat.h"

Cat::Cat(const LoaderParams* params) : SDLGameObject(params) {}

void Cat::draw() {
    SDLGameObject::draw();
}

void Cat::update() {
    position.setX(position.getX() + 1);
    currentFrame = int((SDL_GetTicks() / 100) % 8);
}