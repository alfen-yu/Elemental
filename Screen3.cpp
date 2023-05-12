#include "Screen3.h"

const std::string Screen3::screenID = "Screen4";

// y position: 690
// x position lower quartile : 654
// x position upper quartile : 760

// fourth screen x: -56
// fourth screen y top: 469
// fourth screen y bottom: 538

void Screen3::fourthScreenTransition() {
    if ((player->getPosition().getX() <= -56) &&
        player->getPosition().getY() >= 469 && player->getPosition().getY() <= 538)
    {
        TheGame::Instance()->getStateMachine()->changeState(new Screen4() );
    }
}

//mercury position: (1170, 396)

//x 856//x
//y 534// 359
bool Screen3::mercuryToolTip()
{
    if ((player->getPosition().getX() >= 856) && (player->getPosition().getY() >= 359 && player->getPosition().getY() <= 534))
    {
        if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/tooltip M.png", "tpMercury", TheGame::Instance()->getRenderer()))
        {
            return false;
        }
    }
}

// entering girl's house coordinates: (702, 250), (770, 250)

void Screen3::enterHouse() {
    if ((player->getPosition().getX() >= 702 && player->getPosition().getX() <= 770) && (player->getPosition().getY() <= 250))
    {
        TheGame::Instance()->getStateMachine()->pushState( new GirlHouse() );
    }
}

void Screen3::pickupMercury()
{
    static bool mercuryPickedUp = false;

    if (!mercuryPickedUp && (player->getPosition().getX() >= 1049 && player->getPosition().getX() <= 1183) &&
        (player->getPosition().getY() >= 293 && player->getPosition().getY() <= 389))
    {
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            mercuryPickedUp = true;

            if (mercuryTT != nullptr && mercuryElem != nullptr)
            {
                auto it = std::remove_if(gameObjects.begin(), gameObjects.end(),
                                         [this](GameObject *obj)
                                         { return obj == mercuryElem || obj == mercuryTT; });

                gameObjects.erase(it, gameObjects.end());

                delete mercuryTT;
                mercuryTT = nullptr;
                delete mercuryElem;
                mercuryElem = nullptr;
            }

            TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/gameScreen3.png", "screen3", TheGame::Instance()->getRenderer());
        }
    }
}

void Screen3::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
    Screen3::fourthScreenTransition();
    Screen3::mercuryToolTip();
    Screen3::pickupMercury();
    Screen3::enterHouse();
    player->getPosition().printXAndY();
}

void Screen3::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool Screen3::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/gameScreen3.png", "screen3", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainPlayer/alchemist.png", "hero", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/Elements/mercuryMain.png", "mercury", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *screenThree = new SDLGameObject(new LoaderParams(0, 0, 1381, 790, 1380, 715, "screen3"));
    player = new Player(new LoaderParams(707, 650, 137, 206.1, 60, 89, "hero", 3));
    mercuryElem = new SDLGameObject(new LoaderParams(1050, 350, 168, 151, 140, 120, "mercury"));
    mercuryTT = new SDLGameObject(new LoaderParams(1000, 310, 439, 170, 170, 80, "tpMercury"));

    gameObjects.push_back(screenThree);
    gameObjects.push_back(mercuryElem);
    gameObjects.push_back(player);
    gameObjects.push_back(mercuryTT);

    return true;
}

bool Screen3::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("screen3");
    TheTextureManager::Instance()->clearFromTextureMap("hero");
    TheTextureManager::Instance()->clearFromTextureMap("mercury");
    TheTextureManager::Instance()->clearFromTextureMap("tpMercury");
}