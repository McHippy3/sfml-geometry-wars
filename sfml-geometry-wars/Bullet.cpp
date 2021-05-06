#include "Bullet.h"

/**
* Initializes variables (excl. moveX, moveY)
*/
void Bullet::initVariables()
{
    this->movementSpeed = 1.5;
    this->radius = 5;
}

/**
* Initializes moveX and moveY such that the bullet moves towards target
* @param startPos the initial position of bullet
* @param target the target position of bullet
*/
void Bullet::initMoveXY(sf::Vector2f startPos, sf::Vector2f target)
{
    float deltaX = target.x - startPos.x;
    float deltaY = target.y - startPos.y;
    deltaX = deltaX < 0 ? deltaX * -1 : deltaX;
    deltaY = deltaY < 0 ? deltaY * -1 : deltaY;
    if (deltaX == 0)
    {
        moveY = 1;
    }
    else if (deltaY == 0)
    {
        moveX = 1;
    }
    else
    {
        float slope = deltaY / deltaX;
        this->moveX = 1 / (slope + 1);
        this->moveY = 1 - moveX;
    }
    if (startPos.x > target.x)
    {
        this->moveX *= -1;
    }
    if (startPos.y > target.y)
    {
        this->moveY *= -1;
    }
}

/**
* Initializes the circle that represents the bullet
* @param startPos the initial coordinates of the circle
*/
void Bullet::initCircle(sf::Vector2f startPos)
{
    this->circle.setFillColor(sf::Color::Blue);
    this->circle.setRadius(this->radius);
    this->circle.setPosition(sf::Vector2f(
        startPos.x - this->radius, startPos.y - this->radius));
}

/**
* Constructs a Bullet object
* @param startPos the starting point of the bullet
* @param target the point that the bullet will move towards
*/
Bullet::Bullet(sf::Vector2f startPos, sf::Vector2f target)
{
    this->initVariables();
    this->initMoveXY(startPos, target);
    this->initCircle(startPos);
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
    float x = this->circle.getPosition().x + this->radius / 2;
    float y = this->circle.getPosition().y + this->radius / 2;
    return sf::Vector2f(x, y);
}

/**
* Determines whether the bullet is offscreen
* @return returns true if bullet is offscreen
*/
bool Bullet::offBounds(sf::RenderTarget& window)
{
    sf::Vector2f center = this->getCenter();
    if (center.x > window.getSize().x || center.x < 0)
    {
        return true;
    }
    if (center.y > window.getSize().y || center.y < 0)
    {
        return true;
    }
    return false;
}

/**
* Moves the bullet one step towards the original target. 
*/
void Bullet::move(sf::Time elapsedTime)
{
    this->circle.move(
        this->movementSpeed * this->moveX * elapsedTime.asMilliseconds(),
        this->movementSpeed * this->moveY * elapsedTime.asMilliseconds());
}

/**
* Renders the bullet onto target
*/
void Bullet::render(sf::RenderTarget& target)
{
    target.draw(this->circle);
}
