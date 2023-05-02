#include "Player.h"

Player::Player(const LoaderParams* params) : SDLGameObject(params){}

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
    currentFrame = int((SDL_GetTicks() / 100) % 4);
    // acceleration.setY(0.1); // gradually increases the velocity of an object
    velocity.setY(1);
    SDLGameObject::update();
}