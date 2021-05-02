#include "Entity.h"

/**
* Initializes variables. Sets default hp value
*/
void Entity::initVariables()
{
    this->hp = 1;
}

/**
* Initializes texture. Loads in texture from file
*/
void Entity::initTexture(std::string textureFilePath)
{
    // Load a texture from file
    if (!this->texture.loadFromFile(textureFilePath))
    {
        std::cout << "ERROR::ENTITY::INITTEXTURE::Could not load texture file." << "\n";
    }
}

/**
* Initializes sprite. Sets the texture of the sprite
*/
void Entity::initSprite()
{
    this->sprite.setTexture(this->texture);
}

/**
* Constructor
* @param textureFilePath path to image file for entity texture
*/
Entity::Entity(std::string textureFilePath)
{
    initTexture(textureFilePath);
    initSprite();
}

/**
* Destructor
*/
Entity::~Entity()
{
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
