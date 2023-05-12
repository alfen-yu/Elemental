#include "BagContents.h"

const std::string BagContents::bagID = "Bag Contents";

void BagContents::contentsToScreen()
{
    TheGame::Instance()->getStateMachine()->popState();
}

void BagContents::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void BagContents::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool BagContents::onEnter()
{
    if (!TheTextureManager::Instance()->load("assests/gameImages/Buttons/back button.png", "backbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject *backButton = new MenuButtons(new LoaderParams(50, 600, 223, 68, 223, 68, "backbutton"), contentsToScreen);

    gameObjects.push_back(backButton);

    std::cout << "entering bag contents state \n";
    return true;
}

bool BagContents::onExit()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("backbutton");

    std::cout << "Exiting bag contents State \n";
    return true;
}