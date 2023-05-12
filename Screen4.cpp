#include "Screen4.h"

const std::string Screen4::screenID = "Screen4";

void Screen4::lastScreenTransition() {
    if ((player->getPosition().getX() >= 1340) &&
        player->getPosition().getY() >= 98 && player->getPosition().getY() <= 172)
    {
        TheGame::Instance()->getStateMachine()->changeState(new Screen4() );
    }
}

// bool Screen4::sulfurToolTip()
// {
//     if ((player->getPosition().getX() >= 820 && player->getPosition().getX() <= 1150) && (player->getPosition().getY() >= 270 && player->getPosition().getY() <= 510))
//     {
//         if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip Cg.png", "tpChlorine", TheGame::Instance()->getRenderer()))
//         {
//             return false;
//         }
//     }
// }

// void Screen4::pickupSulfur()
// {
//     static bool sulfurPickedUp = false;

//     if (!sulfurPickedUp && (player->getPosition().getX() >= 940 && player->getPosition().getX() <= 1000) &&
//         (player->getPosition().getY() >= 345 && player->getPosition().getY() <= 420))
//     {
//         if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
//         {
//             sulfurPickedUp = true;

//             if (sulfurTT != nullptr)
//             {
//                 auto it = std::remove_if(gameObjects.begin(), gameObjects.end(),
//                                          [this](GameObject *obj)
//                                          { return obj == sulfurTT; });
//                 gameObjects.erase(it, gameObjects.end());
//                 delete sulfurTT;
//                 sulfurTT = nullptr;
//             }

//             TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/gameScreen4.png", "screen4", TheGame::Instance()->getRenderer());
//         }
//     }
// }

void Screen4::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
    player->getPosition().printXAndY();
}

void Screen4::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool Screen4::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/gameScreen4.png", "screen4", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainPlayer/alchemist.png", "hero", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/sulfur.png", "sulfur", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip S.png", "tpSulfur", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *screenFour = new SDLGameObject(new LoaderParams(0, 0, 1381, 780, 1380, 715, "screen4"));
    player = new Player(new LoaderParams(213, 609, 137, 206.1, 60, 89, "hero", 3));
    GameObject* sulfurElem = new SDLGameObject(new LoaderParams(518, 180, 920, 600, 300, 140, "sulfur"));
    sulfurTT = new SDLGameObject(new LoaderParams(528, 150, 439, 170, 170, 80, "tpSulfur"));

    gameObjects.push_back(screenFour);
    gameObjects.push_back(player);
    gameObjects.push_back(sulfurElem);
    gameObjects.push_back(sulfurTT);

    return true;
}

bool Screen4::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("screen4");
    TheTextureManager::Instance()->clearFromTextureMap("hero");
    TheTextureManager::Instance()->clearFromTextureMap("sulfur");
    TheTextureManager::Instance()->clearFromTextureMap("tpSulfur");
}