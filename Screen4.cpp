#include "Screen4.h"

const std::string Screen4::screenID = "Screen4";

// void Screen4::lastScreenTransition() {
//     if ((player->getPosition().getX() >= 1340) &&
//         player->getPosition().getY() >= 98 && player->getPosition().getY() <= 172)
//     {
//         TheGame::Instance()->getStateMachine()->changeState(new Screen4() );
//     }
// }

// x : 303, 366
// y : 181, 439

bool Screen4::sulfurToolTip()
{
    if ((player->getPosition().getX() >= 303 && player->getPosition().getX() <= 366) && (player->getPosition().getY() >= 181 && player->getPosition().getY() <= 439))
    {
        if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip S.png", "tpSulfur", TheGame::Instance()->getRenderer()))
        {
            return false;
        }
    }
}

// x : 469, 520, 568, 520
// y : 183, 216, 180, 138

void Screen4::pickupSulfur()
{
    static bool sulfurPickedUp = false;

    if (!sulfurPickedUp && (player->getPosition().getX() >= 469 && player->getPosition().getX() <= 568) &&
        (player->getPosition().getY() >= 132 && player->getPosition().getY() <= 191))
    {
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            sulfurPickedUp = true;

            if (sulfurTT != nullptr && sulfurElem != nullptr)
            {
                auto it = std::remove_if(gameObjects.begin(), gameObjects.end(),
                                         [this](GameObject *obj)
                                         { return obj == sulfurTT || obj == sulfurElem; });

                gameObjects.erase(it, gameObjects.end());

                delete sulfurTT;
                sulfurTT = nullptr;
                delete sulfurElem;
                sulfurElem = nullptr;
            }

            TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/gameScreen4.png", "screen4", TheGame::Instance()->getRenderer());
        }
    }
}

void Screen4::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }

    Screen4::sulfurToolTip();
    Screen4::pickupSulfur();

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

    if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/sulfurMain.png", "sulfur", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    // if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/boulders.png", "boulders", TheGame::Instance()->getRenderer()))
    // {
    //     return false;
    // }

    GameObject *screenFour = new SDLGameObject(new LoaderParams(0, 0, 1381, 780, 1380, 715, "screen4"));
    sulfurElem = new SDLGameObject(new LoaderParams(510, 208, 281, 202, 80, 50, "sulfur"));
    player = new Player(new LoaderParams(213, 609, 137, 206.1, 60, 89, "hero", 3));
    sulfurTT = new SDLGameObject(new LoaderParams(515, 140, 439, 170, 170, 80, "tpSulfur"));
    // GameObject* boulder = new

    gameObjects.push_back(screenFour);
    gameObjects.push_back(sulfurElem);
    gameObjects.push_back(player);
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