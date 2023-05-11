#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include "Player.h"
#include "Screen2.h"

class PlayState : public GameState {
    private:
        static const std::string playID;

        std::vector<GameObject*> gameObjects;

        GameObject* player;

    public:
        virtual void update();
        virtual void render();

        void secondScreenTransition();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return playID; }
};

#endif //{PlayState}