#include "Player.h"

/**
* Initializes variables. Sets health and movementSpeed
*/
void Player::initVariables()
{
    this->setHP(5);
    this->setMovementSpeed(1);
}

/**
* Initializes components
*/
void Player::initComponents()
{
}

/**
* Constructs a Player object
* @param x initial x coordinate
* @param y initial y coordinate
*/
Player::Player(float x, float y) : Entity("textures/ship.jpg")
{
    this->initVariables();
    this->setPosition(x, y);
}

/**
* Destroys a Player object
*/
Player::~Player()
{
}

/**
* Primary update function
*/
void Player::update()
{
}

/**
* Renders player on the window
* @param target window to render player on
*/
void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
