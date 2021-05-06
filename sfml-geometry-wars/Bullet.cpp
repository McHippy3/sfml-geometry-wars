#include "Bullet.h"

/**
* Initializes variables (excl. moveX, moveY)
*/
void Bullet::initVariables()
{
    //this->movementSpeed = 3;
}

/**
* Initializes moveX and moveY such that the bullet moves towards target
*/
void Bullet::initMoveXY(float x, float y, sf::Vector2f target)
{
    //float deltaX = target.x - x;
    //float deltaY = target.y - y;
    //float slope = deltaY / deltaX;
    //this->moveX = 
}

/**
* Initializes the circle that represents the bullet
*/
void Bullet::initCircle()
{
}

/**
* Constructs a Bullet object
* @param x initial x coordinate
* @param y initial y coordinate
* @param target the point that the bullet will move towards
*/
Bullet::Bullet(float x, float y, sf::Vector2f target)
{
    this->initVariables();
    this->initMoveXY(x, y, target);
    this->initCircle();
}

/**
* Destroys a Bullet object
*/
Bullet::~Bullet()
{
}

/**
* @return the coordinates of the center of the bullet
*/
sf::Vector2f Bullet::getCenter()
{
    return sf::Vector2f();
}

/**
* Updates the bullet object. Move one step towards the original target. 
*/
void Bullet::update()
{
}
