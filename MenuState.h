#ifndef __MenuState__
#define __MenuState__
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include "MenuButtons.h"
#include <vector>
#include "Screen4.h"

class MenuState: public GameState {
    private:
        static const std::string menuID;
        std::vector<GameObject*> gameObjects;

        // callback functions for menu items 
        // we have made them static because callback functions handle static much better
        static void menuToPlay();
        static void exitFromMenu();
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return menuID; }
};

#endif