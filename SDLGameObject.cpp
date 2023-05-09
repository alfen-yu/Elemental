#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params),
                                                           position(params->getX(), params->getY()), velocity(0, 0),
                                                           acceleration(0, 0)
{
    srcWidth = params->getSrcWidth();
    srcHeight = params->getSrcHeight();
    destWidth = params->getDestWidth();
    destHeight = params->getDestHeight();
    textureID = params->getID();
    currentRow = params->getCurrentRow();
    currentFrame = params->getCurrentFrame();
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, (int)position.getX(), (int)position.getY(), srcWidth, srcHeight, destWidth, destHeight, currentRow, currentFrame,
                                             TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    // operator overloading can be seen here
    velocity += acceleration;
    position += velocity;
}

void SDLGameObject::clean() {
    std::cout << "SDL Game Object Cleaned \n";
}

SDLGameObject::~SDLGameObject() {
    std::cout << "SDL Game Object Destructor Called \n";
}