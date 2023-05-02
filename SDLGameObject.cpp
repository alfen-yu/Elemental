#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params),
                                                           position(params->getX(), params->getY()), velocity(0, 0),
                                                           acceleration(0, 0)
{
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getID();

    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, (int)position.getX(), (int)position.getY(), width, height, currentRow, currentFrame,
                                             TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    // operator overloading can be seen here
    velocity += acceleration;
    position += velocity;
}