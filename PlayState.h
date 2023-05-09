#ifndef __PlayState__
#define __PlayState__
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"

class PlayState : public GameState {
    private:
        static const std::string playID;

        std::vector<GameObject*> gameObjects;
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return playID; }
};

#endif //{PlayState}