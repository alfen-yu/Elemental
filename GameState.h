#ifndef __GameState__
#define __GameState__

#include <string>
#include <iostream>

// Implementing Finite State Machine to handle states 
// 1. Removing one state and adding another: We will use this way to completely 
// change states without leaving the option to return
// 2. Adding one state without removing the previous state: This way is useful 
// for pause menus and so on
// 3. Removing one state without adding another: This way will be used to remove 
// pause states or any other state that had been pushed on top of another one

class GameState {
    public:
        virtual void update() = 0;
        virtual void render() = 0;

        virtual bool onEnter() = 0; // similar to the load function, called as soon as a state is created
        virtual bool onExit() = 0; // similar to the clean function, called once the state is removed 

        virtual std::string getStateID() const = 0; // getter for the state id
};

#endif