#include "Bag.h"

Bag::Bag(const LoaderParams *params) : SDLGameObject(params) {
    currentFrame = MOUSE_OUT; // states are frame 0
}

void Bag::bagToContents() {
    TheGame::Instance()->getStateMachine()->pushState( new BagContents() );
}

// doesnt override instead uses the game object draw function
void Bag::draw()
{
    SDLGameObject::draw();
}

Vector2D Bag::getPosition() {
    SDLGameObject::getPosition();
}

// overriding the game object update function, any previous implementation in the game object of update isnt
// applicable here
void Bag::update()
{
    Vector2D *mousePos = TheInputHandler::Instance()->getMousePosition();

    if ((mousePos->getX() < (position.getX() + destWidth)) &&
        ((mousePos->getX()) > position.getX()) && ((mousePos->getY()) < (position.getY() + destHeight)) &&
        (mousePos->getY() > position.getY()))
    {
        currentFrame = MOUSE_OVER;

        if (TheInputHandler::Instance()->getMouseButtonStates(LEFT))
        {
            currentFrame = CLICKED; // indicates that the mouse have clicked here 
            bagToContents();
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
    
    SDLGameObject::update();
}

void Bag::clean() {
    std::cout << "Bag Cleaned \n";
}

Bag::~Bag() {
    std::cout << "Bag Destructor Called \n";
}