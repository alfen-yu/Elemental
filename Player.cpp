#include "Player.h"

// doesnt override instead uses the game object draw function 
void Player::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x, y, width, height, textureID);
}

// doesnt override instead uses the game object draw function 
void Player::draw(SDL_Renderer* renderer) {
    GameObject::draw(renderer);
}

// overriding the game object update function, any previous implementation in the game object of update isnt 
//applicable here
void Player::update() {
    x += 2;
}