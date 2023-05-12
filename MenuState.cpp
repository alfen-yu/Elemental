#include "MenuState.h"

const std::string MenuState::menuID = "MENU";

void MenuState::menuToPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new Screen2());
}

void MenuState::exitFromMenu()
{
    std::cout << "exit button clicked \n";
    TheGame::Instance()->setRunningState(false);
}

void MenuState::update()
{
    for (int i = 0; i < 6; i++)
    {
        gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for (int i = 0; i < 6; i++)
    {
        gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/Start Game picture.png", "background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assests/gameImages/MainGame Images/Elemental logo.png", "logo", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assests/gameImages/Buttons/play button.png", "playbutton",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/Buttons/credits button.png", "credits",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assests/gameImages/Buttons/exit button.png", "exitbutton",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assests/gameImages/Buttons/manual button.png", "manual",
                                             TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *background = new SDLGameObject(new LoaderParams(0, 0, 1380, 780, 1366, 768, "background"));
    GameObject *logo = new SDLGameObject(new LoaderParams(0, 0, 1380, 780, 1366, 768, "logo"));
    GameObject *playButton = new MenuButtons(new LoaderParams(100, 250, 223, 68, 223, 68, "playbutton"), menuToPlay);
    GameObject *creditsButton = new MenuButtons(new LoaderParams(100, 350, 223, 68, 223, 68, "credits"), menuToPlay);
    GameObject *manualButton = new MenuButtons(new LoaderParams(100, 450, 223, 68, 223, 68, "manual"), menuToPlay);
    GameObject *exitButton = new MenuButtons(new LoaderParams(100, 550, 223, 68, 223, 68, "exitbutton"), exitFromMenu);

    gameObjects.push_back(background);
    gameObjects.push_back(logo);
    gameObjects.push_back(playButton);
    gameObjects.push_back(creditsButton);
    gameObjects.push_back(manualButton);
    gameObjects.push_back(exitButton);

    std::cout << "entering menu state \n";
    return true;
}

bool MenuState::onExit()
{
    for (int i = 0; i < 6; i++)
    {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
    TheTextureManager::Instance()->clearFromTextureMap("logo");
    TheTextureManager::Instance()->clearFromTextureMap("manual");
    TheTextureManager::Instance()->clearFromTextureMap("credits");
    TheTextureManager::Instance()->clearFromTextureMap("background");

    std::cout << "Exiting Menu State \n";
    return true;
}