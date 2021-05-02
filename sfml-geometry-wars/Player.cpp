#include "Player.h"

// Initializers
void Player::initVariables()
{
    this->setHP(5);
    this->setMovementSpeed(1);
}

void Player::initComponents()
{
}

// Constructor / Destructor
Player::Player(float x, float y) : Entity("textures/ship.jpg")
{
    this->initVariables();
    this->setPosition(x, y);
}

Player::~Player()
{
}

// Functions
void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
