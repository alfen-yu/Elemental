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
    x += 1;
    // currentFrame = int((SDL_GetTicks() / 100) % 4);
}