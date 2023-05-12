#include "Screen2.h"

const std::string Screen2::screenID = "Screen2";

// Element picking coords: x: (809, 1141)
// y = (270, 1057)



void Screen2::thirdScreenTransition()
{
    if ((player->getPosition().getX() >= 441 && player->getPosition().getX() <= 512) &&
        player->getPosition().getY() >= 682)
    {
        TheGame::Instance()->getStateMachine()->changeState(new Screen3());
    }
}

bool Screen2::chlorineToolTip()
{
    if ((player->getPosition().getX() >= 820 && player->getPosition().getX() <= 1150) && (player->getPosition().getY() >= 270 && player->getPosition().getY() <= 510))
    {
        if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip Cg.png", "tpChlorine", TheGame::Instance()->getRenderer()))
        {
            return false;
        }
    }
}

void Screen2::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }

    Screen2::chlorineToolTip();
    Screen2::thirdScreenTransition();
    player->getPosition().printXAndY();
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
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/mainScreen2.png", "screen2", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainPlayer/alchemist.png", "hero", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    // TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip Cg.png", "tpChlorine", TheGame::Instance()->getRenderer());

    GameObject *screenTwo = new SDLGameObject(new LoaderParams(0, 0, 1380, 780, 1370, 705, "screen2"));
    player = new Player(new LoaderParams(420, 0, 137, 206.1, 60, 89, "hero"));
    GameObject *chlorineTT = new SDLGameObject(new LoaderParams(947, 360, 439, 170, 170, 80, "tpChlorine"));

    gameObjects.push_back(screenTwo);
    gameObjects.push_back(player);
    gameObjects.push_back(chlorineTT);

    return true;
}

bool Screen2::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("screen2");
    TheTextureManager::Instance()->clearFromTextureMap("hero");
    TextureManager::Instance()->clearFromTextureMap("tpChlorine");
}