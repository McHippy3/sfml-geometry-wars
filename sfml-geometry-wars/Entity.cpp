#include "Entity.h"

/**
* Initializes variables. Sets default hp value
*/
void Entity::initVariables()
{
    this->hp = 1;
    this->movementSpeed = 1;
}

/**
* Constructs an Entity object
*/
Entity::Entity()
{
    initVariables();
}

/**
* Destroys an Entity object
*/
Entity::~Entity()
{
}

/**
* Sets the texture of sprite
*/
void Entity::setSprite()
{
    this->sprite.setTexture(this->texture);
}

/**
* Sets texture. Loads in texture from file
*/
void Entity::setTexture(std::string textureFilePath)
{
    // Load a texture from file
    if (!this->texture.loadFromFile(textureFilePath))
    {
        std::cout << "ERROR::ENTITY::INITTEXTURE::Could not load texture file." << "\n";
    }
}
/**
* @return sprite position
*/
const sf::Vector2f& Entity::getPosition() const
{
    return this->sprite.getPosition();
}

/**
* @return movementSpeed
*/
const float& Entity::getMovementSpeed() const
{
    return this->movementSpeed;
}

/**
* @return hp
*/
const int& Entity::getHP() const
{
    return this->hp;
}

/**
* @param x value representing x coordinate
* @param y value representing y coordinate
*/
void Entity::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

/**
* @param hp positive integer representing the new hp of the entity
*/
void Entity::setMovementSpeed(const float movementSpeed)
{
    this->movementSpeed = movementSpeed;
}

/**
* @param hp positive integer representing the new hp of the entity
*/
void Entity::setHP(const int hp)
{
    this->hp = hp;
}

/**
* Decreases the health of the entity based on damage
* @param damage the amount of damaged received by the entity
* @return true if entity is still alive, false otherwise
*/
bool Entity::receiveDamage(const int damage)
{
    this->hp -= damage;
    if (this->hp <= 0)
    {
        return false;
    }
    return true;
}

/**
* Moves the entity
* @param x the amount to move in the x direction
* @param y the amount to move in the y direction
* @param elapsedTime the amount of time elapsed since the last frame
*/
void Entity::move(const float x, const float y, sf::Time elapsedTime)
{
    std::cout << elapsedTime.asMilliseconds() << std::endl;
    this->sprite.move(this->movementSpeed * x * elapsedTime.asMilliseconds(), 
        this->movementSpeed * y * elapsedTime.asMilliseconds());
}

/**
* Renders the entity on the window
* @param target window to render entity on
*/
void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
