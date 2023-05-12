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
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/mainImage1.png", "screen1", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/NPCS/Pet Cats Pack/Cat-1/Cat-1-Run.png", "cat", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/Bag/bag.png", "bag", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject *screenOne = new SDLGameObject(new LoaderParams(0, 0, 1020, 682, 1366, 786, "screen1"));
    player = new Player(new LoaderParams(0, 235, 137, 206.1, 60, 89, "hero", 2));
    GameObject* bag = new Bag(new LoaderParams(50, 540, 284, 305, 90, 100, "bag"));
    GameObject *cat = new Cat(new LoaderParams(0, 470, 50, 50, 120, 120, "cat"));

    gameObjects.push_back(screenOne);
    gameObjects.push_back(player);
    gameObjects.push_back(cat);
    gameObjects.push_back(bag);

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
    TheTextureManager::Instance()->clearFromTextureMap("screen1");
    TheTextureManager::Instance()->clearFromTextureMap("bag");

    return true;
}