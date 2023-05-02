#ifndef __InputHandler__
#define __InputHandler__
#include "SDL.h"
#include "Game.h"
#include <iostream>

class InputHandler {
    private:
        InputHandler() {}

        static InputHandler* inputInstance;

        ~InputHandler() { std::cout << "Input Handler Destroyed \n";}
    public:
        static InputHandler* Instance() {
            if (inputInstance == 0) {
                inputInstance = new InputHandler();
                return inputInstance;
            }
            return inputInstance;
        }
        void update();
        void clean();
};

typedef InputHandler TheInputHandler;

#endif 