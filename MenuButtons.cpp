#include "MenuButtons.h"

MenuButtons::MenuButtons(const LoaderParams *params, void (*cb)()) : SDLGameObject(params), callback(cb)
{
    currentFrame = MOUSE_OUT; // states are frame 0
}

void MenuButtons::draw()
{
    SDLGameObject::draw(); // uses the base class to draw
}

void MenuButtons::update()
{
    // we get the coordinates of the mouse pointer and store them in the vector pointer
    Vector2D *mousePos = TheInputHandler::Instance()->getMousePosition();

    if ((mousePos->getX() < (position.getX() + destWidth)) &&
        ((mousePos->getX()) > position.getX()) && ((mousePos->getY()) < (position.getY() + destHeight)) &&
        (mousePos->getY() > position.getY()))
    {
        currentFrame = MOUSE_OVER;

        if (TheInputHandler::Instance()->getMouseButtonStates(LEFT))
        {
            currentFrame = CLICKED; // indicates that the mouse have clicked here 
            callback(); // call our callback function 
            released = false;
        }
        else if (!TheInputHandler::Instance()->getMouseButtonStates(LEFT)){
            currentFrame = MOUSE_OUT;
            released = true; // ensures that we have released the mouse button to utilise callback again
        }
    }
    else {
        currentFrame = MOUSE_OUT;
    }
}

void MenuButtons::clean() {
    SDLGameObject::clean();
}