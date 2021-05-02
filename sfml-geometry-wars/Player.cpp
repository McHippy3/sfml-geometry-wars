#include "Player.h"

// Initializers
void Player::initVariables()
{
    this->setHP(5);
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
void Player::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
