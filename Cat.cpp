#include "Cat.h"

Cat::Cat(const LoaderParams* params) : SDLGameObject(params) {}

void Cat::draw() {
    SDLGameObject::draw();
}

void Cat::update() {
    x += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 8);
    std::cout << "current frame: " << currentFrame << std::endl;
}