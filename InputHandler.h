#ifndef __InputHandler__
#define __InputHandler__
#include "SDL.h"
#include "Game.h"
#include <iostream>
#include "Vector2D.h"
#include <vector>

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
private:
    // private functions to handle different event type 

    // handle keyboard events 
    void onKeyDown(SDL_Event &event);
    // void onKeyUp(SDL_Event &event);

    // handle mouse events 
    void onMouseMove(SDL_Event &event);
    void onMouseButtonDown(SDL_Event &event);
    void onMouseButtonUp(SDL_Event &event);

    

    Vector2D *mousePosition;
    InputHandler();

    static InputHandler *inputInstance;

    const Uint8* keystates; // returns the state of the keys 0/1 

    std::vector<bool> mouseButtonStates; // for controlling mouse button actions

public:
    static InputHandler *Instance()
    {
        if (inputInstance == 0)
        {
            inputInstance = new InputHandler();
            return inputInstance;
        }
        return inputInstance;
    }
    void update();

    // handles the state of the mouse buttons
    bool getMouseButtonStates(int buttonNumber)
    {
        return mouseButtonStates[buttonNumber];
    }

    // for keyboard key checking 
    bool isKeyDown(SDL_Scancode key);

    Vector2D* getMousePosition() { return mousePosition; }

    void clean();
    ~InputHandler();

};

typedef InputHandler TheInputHandler;

#endif