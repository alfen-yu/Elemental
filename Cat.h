#ifndef __Cat__
#define __Cat__
#include "SDLGameObject.h"

class Cat : public SDLGameObject
{
    // private:
    // int catFrame;
public:
    Cat(const LoaderParams *params);

    virtual void draw();
    virtual void update();
    // virtual void clean();
};

#endif