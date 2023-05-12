#include "Screen3.h"

const std::string Screen3::screenID = "Screen3";

// y position: 690
// x position lower quartile : 654
// x position upper quartile : 760

// fourth screen x: -56
// fourth screen y top: 469
// fourth screen y bottom: 538


// void Screen3::fourthScreenTransition() {
//     if ((player->getPosition().getX() >= 450 && player->getPosition().getX() <= 724) &&
//         player->getPosition().getY() >= 680)
//     {
//         TheGame::Instance()->getStateMachine()->changeState( new Screen2() ); 
//     }
// }

void Screen3::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
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

    GameObject *screenThree = new SDLGameObject(new LoaderParams(0, 0, 1034, 690, 1380, 705, "screen3"));
    player = new Player(new LoaderParams(707, 690, 137, 206.1, 60, 89, "hero", 3));

    gameObjects.push_back(screenThree);
    gameObjects.push_back(player);

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
}