#ifndef __Bag__
#define __Bag__

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "BagContents.h"

class Bag : public SDLGameObject
{
private:
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
        bool released;

public:
    Bag(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual Vector2D getPosition();
    void bagToContents();

    ~Bag();
};

#endif