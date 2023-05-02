#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params), position(params->getX(), params->getY())
{
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getID();
    x = params->getX();
    y = params->getY();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame,
                                             TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    std::cout << "current frame: " << currentFrame << std::endl;
}