#ifndef __Screen2__
#define __Screen2__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include <iostream>
#include "InputHandler.h"
#include "SDLGameObject.h"
#include "Screen3.h"
#include <algorithm>

class Screen2 : public GameState {
    private:
        static const std::string screenID;

        // all the objects presented on the second screen including the background, 
        // textures, animated objects are pushed, rendered, and updated through gameObjects
        std::vector<GameObject*> gameObjects; 

        GameObject* player;
        GameObject *chlorineTT;
        
    public:
    Screen2(){}
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {
        return screenID;
    }

    void thirdScreenTransition();
    bool chlorineToolTip();
    void pickupChlorine();
    ~Screen2(){}
};

#endif //{SECOND SCREEN OF PLAY STATE}