#include "PlayState.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
    // doesnt do anything as of now 
}

void PlayState::render() {
    // doesnt do anything as of now 
}

bool PlayState::onEnter() {
    std::cout << "Entering Play State \n";
    return true;
}

bool PlayState::onExit() {
    std::cout << "Exiting Play State \n";
    return true;
}