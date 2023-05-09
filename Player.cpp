#include "Player.h"

Player::Player(const LoaderParams *params) : SDLGameObject(params) {}

// doesnt override instead uses the game object draw function
void Player::draw()
{
    SDLGameObject::draw();
}

// overriding the game object update function, any previous implementation in the game object of update isnt
// applicable here
void Player::update()
{
    // position.setY(position.getY() + 1);
    // acceleration.setY(0.1); // gradually increases the velocity of an object
    // velocity.setY(1);
    // if (TheInputHandler::Instance()->getMouseButtonStates(LEFT))
    // {
        // velocity.setY(1);
        // currentFrame = int((SDL_GetTicks() / 100) % 4);
    // }
    // Player follows the mouse position 
    // Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    // velocity = (*vec - position) / 100;
    // velocity = (*vec - position) / 100; // Remove the division to make the player follow the exact mouse position

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { // for right arrow key
        position.setX(position.getX() + 1);
        currentFrame = int((SDL_GetTicks() / 100) % 4);
        currentRow = 3;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { // for left arrow key
        position.setX(position.getX() - 1);
        currentFrame = int((SDL_GetTicks() / 100) % 4);
        currentRow = 2;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) { // for up arrow key
        position.setY(position.getY() - 1);
        currentFrame = int((SDL_GetTicks() / 100) % 4);
        currentRow = 4;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) { // for down arrow key
        position.setY(position.getY() + 1);
        currentFrame = int((SDL_GetTicks() / 100) % 4);
        currentRow = 1;
    }

    SDLGameObject::update();
}

void Player::clean() {
    std::cout << "Player Cleaned \n";
}

Player::~Player() {
    std::cout << "Player Destructor Called \n";
}