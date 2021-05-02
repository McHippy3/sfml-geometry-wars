#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

class Entity
{
private:
    void initVariables();
    void initTexture(std::string textureFilePath);
    void initSprite();

    float movementSpeed;

    int hp;

protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor / Destructor
    Entity(std::string textureFilePath);
    virtual ~Entity();

    // Component functions

    // Accessors
    virtual const sf::Vector2f& getPosition() const;
    const float& getMovementSpeed() const;
    const int& getHP() const;

    // Modifiers
    virtual void setPosition(const float x, const float y);
    void setMovementSpeed(const float movementSpeed);
    void setHP(const int hp);
    bool receiveDamage(const int damage);

    // Pure virtual functions
    virtual void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};
