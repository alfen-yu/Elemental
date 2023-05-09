#ifndef __GameState__
#define __GameState__

#include "TextureManager.h"

#include <string>
#include <iostream>
#include <vector>

// Abstract class for the States

class GameState {
    public:
        virtual void update() = 0;
        virtual void render() = 0;

        virtual bool onEnter() = 0; // similar to the load function, called as soon as a state is created
        virtual bool onExit() = 0; // similar to the clean function, called once the state is removed 

        virtual std::string getStateID() const = 0; // getter for the state id
};

#endif