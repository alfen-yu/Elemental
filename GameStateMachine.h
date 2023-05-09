#ifndef __GameStateMachine__
#define __GameStateMachine__

#include "GameState.h"

// Actual Handler of the States

// Implementing Finite State Machine to handle states 
// 1. Removing one state and adding another: We will use this way to completely 
// change states without leaving the option to return
// 2. Adding one state without removing the previous state: This way is useful 
// for pause menus and so on
// 3. Removing one state without adding another: This way will be used to remove 
// pause states or any other state that had been pushed on top of another one

// using a stack to handle states

class GameStateMachine {
    private:
        std::vector<GameState*> gameStates; // handles the states, acts as a stack
    public:
        void pushState(GameState* state); // pushes the state on the top of the stack, doesnt remove previous state
        void popState(); // pops the state from the top of the stack, doesnt add another state
        void changeState(GameState* state); // changes the state, removes previous state before adding another
};

#endif