#include "PlayState.h"

const std::string PlayState::playID = "PLAY";

void PlayState::secondScreenTransition()
{
    if ((player->getPosition().getX() >= 558 && player->getPosition().getX() <= 723) &&
        player->getPosition().getY() >= 680)
    {
        TheGame::Instance()->getStateMachine()->changeState( new Screen2() ); 
    }
}

void PlayState::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }

    PlayState::secondScreenTransition();
    player->getPosition().printXAndY();

}

void PlayState::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainPlayer/alchemist.png", "hero", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/mainImage1.png", "background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Run.png", "cat", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject *background = new SDLGameObject(new LoaderParams(0, 0, 1020, 682, 1366, 786, "background"));
    player = new Player(new LoaderParams(0, 235, 137, 206.1, 60, 89, "hero", 2));
    GameObject *cat = new Cat(new LoaderParams(0, 470, 50, 50, 120, 120, "cat"));

    gameObjects.push_back(background);
    gameObjects.push_back(player);
    gameObjects.push_back(cat);

    return true;
}

bool PlayState::onExit()
{

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->clean();
    }

    gameObjects.clear();
    
    TheTextureManager::Instance()->clearFromTextureMap("hero");
    TheTextureManager::Instance()->clearFromTextureMap("cat");
    TheTextureManager::Instance()->clearFromTextureMap("background");

    return true;
}