#ifndef __MenuState__
#define __MenuState__
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include "MenuButtons.h"

class MenuState: public GameState {
    private:
        static const std::string menuID;
        std::vector<GameObject*> gameObjects;
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return menuID; }
};

#endif