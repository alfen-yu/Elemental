#ifndef __Player__
#define __Player__
#include "SDLGameObject.h"

// Inherited from Game Object
class Player : public SDLGameObject {
public:
    Player(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    // virtual void clean();
};

#endif