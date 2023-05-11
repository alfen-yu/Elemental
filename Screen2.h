#ifndef __Screen2__
#define __Screen2__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include <iostream>

class Screen2 : public GameState {
    private:
        static const std::string playID;

        // all the objects presented on the second screen including the background, 
        // textures, animated objects are pushed, rendered, and updated through gameObjects
        std::vector<GameObject*> gameObjects; 
        
    public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {
        return playID;
    }

};

#endif //{SECOND SCREEN OF PLAY STATE}