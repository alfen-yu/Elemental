#ifndef __PlayState__
#define __PlayState__
#include "GameState.h"

class PlayState : public GameState {
    private:
        static const std::string playID;
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return playID; }
};

#endif //{PlayState}