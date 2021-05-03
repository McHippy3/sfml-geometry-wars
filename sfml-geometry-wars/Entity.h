#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

class Entity
{
private:
    void initVariables();

    float movementSpeed;

    int hp;

protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor / Destructor
    Entity();
    virtual ~Entity();

    // Component functions
    void setTexture(std::string textureFilePath);
    void setSprite();

    // Accessors
    virtual const sf::Vector2f& getPosition() const;
    const float& getMovementSpeed() const;
    const int& getHP() const;

    // Modifiers
    virtual void setPosition(const float x, const float y);
    void setMovementSpeed(const float movementSpeed);
    void setHP(const int hp);

    // Functions
    bool receiveDamage(const int damage);
    void move(const float x, const float y, sf::Time elapsedTime);

    // Pure virtual functions
    virtual void update() = 0;
    void render(sf::RenderTarget& target);
};
