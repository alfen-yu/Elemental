#include "MenuState.h"

const std::string MenuState::menuID = "MENU";

void MenuState::update() {
    // doesnt do anything as of now 
}

void MenuState::render() {
    // doesnt do anything as of now 
}

bool MenuState::onEnter() {
    std::cout << "Entering Menu State \n";
    return true;
}

bool MenuState::onExit() {
    std::cout << "Exiting Menu State \n";
    return true;
}