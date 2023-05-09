#include "Cat.h"

Cat::Cat(const LoaderParams* params) : SDLGameObject(params) {}

void Cat::draw() {
    SDLGameObject::draw();
}

void Cat::update() {
    position.setX(position.getX() + 1);
    currentFrame = int((SDL_GetTicks() / 100) % 8);
}

void Cat::clean() {
    std::cout << "Cat Object Cleaned \n";
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called \n";
}