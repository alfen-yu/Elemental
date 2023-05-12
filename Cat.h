#ifndef __Cat__
#define __Cat__
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

class Cat : public SDLGameObject
{
public:
    Cat(const LoaderParams *params);

    virtual void draw();
    virtual void update();
    virtual void clean();

    ~Cat();
};

#endif