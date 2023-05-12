#include "Cat.h"

Cat::Cat(const LoaderParams *params) : SDLGameObject(params) {}

void Cat::draw()
{
    SDLGameObject::draw();
}

void Cat::update()
{
    if (position.getX() <= 950)
    {
        position.setX(position.getX() + 1);
        currentFrame = int((SDL_GetTicks() / 100) % 8);
    }
    else
    {
        TheTextureManager::Instance()->load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Stretching.png", "cat", TheGame::Instance()->getRenderer());
        currentFrame = int((SDL_GetTicks() / 500) % 8 );
    }
}

void Cat::clean()
{
    std::cout << "Cat Object Cleaned \n";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called \n";
}