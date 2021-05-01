#include "Entity.h"

void Entity::initTexture(std::string textureFilePath)
{
    // Load a texture from file
    if (!this->texture.loadFromFile(textureFilePath))
    {
        std::cout << "ERROR::ENTITY::INITTEXTURE::Could not load texture file." << "\n";
    }
}

void Entity::initSprite()
{
    this->sprite.setTexture(this->texture);
}

Entity::Entity(std::string textureFilePath)
{
    initTexture(textureFilePath);
    initSprite();
}

Entity::~Entity()
{
}

const sf::Vector2f& Entity::getPosition() const
{
    return this->sprite.getPosition();
}

void Entity::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}
