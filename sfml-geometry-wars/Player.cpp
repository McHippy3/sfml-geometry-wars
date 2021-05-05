#include "Player.h"

/**
* Initializes variables. Sets health and movementSpeed
*/
void Player::initVariables()
{
    this->setHP(5);
    this->setMovementSpeed(0.5);
}

/**
* Initializes the sprite with the texture of a ship
*/
void Player::initSprite()
{
    this->setTexture("Textures/ship.png");
}

/**
* Constructs a Player object
* @param x initial x coordinate
* @param y initial y coordinate
*/
Player::Player(float x, float y)
{
    this->initVariables();
    this->initSprite();
    this->setPosition(x, y);
}

/**
* Destroys a Player object
*/
Player::~Player()
{
}

/**
* Updates the Player object
*/
void Player::update()
{
}

