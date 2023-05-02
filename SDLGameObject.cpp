#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params)
{
    x = params->getX();
    y = params->getY();
    width = params->getWidth();
    height = params->getHeight();
    currentFrame = params->getCurrentFrame();
    currentRow = params->getCurrentRow();
    textureID = params->getID();

    // currentRow = 1;
    // currentFrame = 1;
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->draw(textureID, x, y, width, height, TheGame::Instance()->getRenderer());
}

void SDLGameObject::drawFrame()
{
    TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame,
                                             TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    std::cout << "current frame: " << currentFrame << std::endl;
}