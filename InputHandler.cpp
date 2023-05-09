#include "InputHandler.h"

InputHandler *InputHandler::inputInstance = 0;

InputHandler::InputHandler()
{
    for (int i = 0; i < 3; i++)
    {
        mouseButtonStates.push_back(false);
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (keystates != 0)
    {
        if (keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = true;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = false;
    }
    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    mousePosition->setX((float)event.motion.x);
    mousePosition->setY((float)event.motion.y);
}

void InputHandler::onKeyDown(SDL_Event &event) {
    keystates = SDL_GetKeyboardState(0);
}

// void InputHandler::onKeyUp(SDL_Event &event) {
//     keystates = SDL_GetKeyboardState(1);
// }

void InputHandler::update()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        keystates = SDL_GetKeyboardState(0);
        switch (event.type)
        {
        case SDL_QUIT:
            TheGame::Instance()->setRunningState(false);
            break;
        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;
        case SDL_KEYDOWN:
            onKeyDown(event);
            break;
        // case SDL_KEYUP:
        //     onKeyUp();
        //     break;
        default:
            break;
        }
    }
}

void InputHandler::clean()
{
    delete mousePosition;
    mousePosition = nullptr;
    std::cout << "Input Handler Cleaned \n";
    delete TheInputHandler::Instance();
    delete TheInputHandler::inputInstance;
    std::cout << "Input Handler Cleaned 2 \n";
}

InputHandler::~InputHandler()
{
    std::cout << "Input Handler Destructor Called \n";
}
