#ifndef __Screen4__
#define __Screen4__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include <iostream>

class Screen4 : public GameState {
    private:
        static const std::string screenID;

        // all the objects presented on the second screen including the background, 
        // textures, animated objects are pushed, rendered, and updated through gameObjects
        std::vector<GameObject*> gameObjects; 

        GameObject* player;
        GameObject* sulfurTT;
        GameObject* sulfurElem;
        
    public:
    Screen4(){}

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {
        return screenID;
    }

    // void lastScreenTransition();
    bool sulfurToolTip();
    void pickupSulfur();

    ~Screen4(){}
};

#endif //{FOURTH SCREEN OF PLAY STATE // SULFUR STATE}