#ifndef __GameObject__
#define __GameObject__
#include <iostream>
#include "LoaderParams.h"
#include "SDL.h"

// Game Object is like the parent class that handles the creation of every object in the game to avoid redundancy
class GameObject {
    protected:
        virtual ~GameObject() {}
    public:
        GameObject(const LoaderParams* params){}
        // virtual keywords ensures overridden behaviour
        virtual void draw() = 0;
        virtual void update() = 0;
        // virtual clean() = 0;
};

#endif 