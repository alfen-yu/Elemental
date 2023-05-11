#include "MenuState.h"

const std::string MenuState::menuID = "MENU";

void MenuState::menuToPlay() {
    TheGame::Instance()->getStateMachine()->changeState( new PlayState() );
}

void MenuState::exitFromMenu() {
    std::cout << "exit button clicked \n";
    TheGame::Instance()->setRunningState(false);
}

void MenuState::update()
{
    for (int i = 0; i < 3; i++)
    {
        gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/main.jpg", "background", TheGame::Instance()->getRenderer())) {
        return false;
    }
    
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/playbutton.png", "playbutton",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/exitbutton.png", "exitbutton",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* background = new SDLGameObject(new LoaderParams(0, 0, 1920, 1080, 1366, 768, "background"));
    GameObject* button1 = new MenuButtons(new LoaderParams(100, 100, 225, 225, 300, 225, "playbutton"), menuToPlay);
    GameObject* button2 = new MenuButtons(new LoaderParams(100, 400, 310, 163, 310, 163, "exitbutton"), exitFromMenu);

    gameObjects.push_back(background);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);

    std::cout << "entering menu state \n";
    return true;
}

bool MenuState::onExit()
{   
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
    TheTextureManager::Instance()->clearFromTextureMap("background");

    std::cout << "Exiting Menu State \n";
    return true;
}