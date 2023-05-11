#include "Screen2.h"

const std::string Screen2::playID = "Screen2";

void Screen2::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void Screen2::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool Screen2::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/mainScreen2.png", "background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *background = new SDLGameObject(new LoaderParams(0, 0, 1380, 780, 1366, 786, "background"));

    gameObjects.push_back(background);

    return true;
}

bool Screen2::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("background");
}