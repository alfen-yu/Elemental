#include "GirlHouse.h"

const std::string GirlHouse::screenID = "house1";

void GirlHouse::backToScreen() {
    if ((player->getPosition().getX() >= 707 && player->getPosition().getX() >= 852) && 
        player->getPosition().getY() >= 615)
    {
        TheGame::Instance()->getStateMachine()->popState();
    }
}

void GirlHouse::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
    player->getPosition().printXAndY();

    GirlHouse::backToScreen();
}

void GirlHouse::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool GirlHouse::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/room.png", "interior", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainPlayer/alchemist.png", "hero", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *screenThree = new SDLGameObject(new LoaderParams(0, 0, 1381, 790, 1380, 715, "interior"));
    player = new Player(new LoaderParams(707, 650, 137, 206.1, 60, 89, "hero", 3));

    gameObjects.push_back(screenThree);
    gameObjects.push_back(player);

    return true;
}

bool GirlHouse::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("interior");
    TheTextureManager::Instance()->clearFromTextureMap("hero");
}