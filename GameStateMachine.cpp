#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* state) {
    gameStates.push_back(state);
    gameStates.back()->onEnter(); // calls the referred on Enter function
} 

void GameStateMachine::popState() {
    if(!gameStates.empty()) { // check if there is something even present in the stack
        if(gameStates.back()->onExit()) { // invoke its on Exit function
            delete gameStates.back();
            gameStates.pop_back(); // remove the state
        }
    }
}

void GameStateMachine::changeState(GameState* state) {
    if(!gameStates.empty()) {
        // if the states are same then we do not have to do anything because we cannot implement a state
        // on the same state
        if (gameStates.back()->getStateID() == state->getStateID()) { 
            return; 
        }
        // if they are different then pop the recent one and adds the new one 
        if (gameStates.back()->onExit()) {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
    // push the new state now
    gameStates.push_back(state);

    // initialise the state
    gameStates.back()->onEnter();
}