#ifndef __Screen3__
#define __Screen3__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include <iostream>

class Screen3 : public GameState {
    private:
        static const std::string screenID;

        // all the objects presented on the second screen including the background, 
        // textures, animated objects are pushed, rendered, and updated through gameObjects
        std::vector<GameObject*> gameObjects; 

        GameObject* player;
        
    public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {
        return screenID;
    }

    // void fourthScreenTransition();
};

#endif //{THIRD SCREEN OF PLAY STATE}