#ifndef __BagContents__
#define __BagContents__

#include "GameState.h"
#include "Game.h"
#include "GameObject.h"

class BagContents : public GameState {
    private:
        static const std::string bagID;
        std::vector<GameObject*> gameObjects;

        // callback functions for menu items 
        // we have made them static because callback functions handle static much better
        static void contentsToScreen();
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return bagID; }
};

#endif 