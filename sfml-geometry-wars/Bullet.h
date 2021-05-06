#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    // Components
    sf::CircleShape circle;

    // Variables
    float moveX;
    float moveY;
    float movementSpeed;
    unsigned damage;
    float radius;

    // Initializers
    void initVariables(unsigned damage);
    void initMoveXY(sf::Vector2f startPos, sf::Vector2f target);
    void initCircle(sf::Vector2f startPos);

public:
    Bullet(sf::Vector2f startPos, sf::Vector2f target, unsigned damage);
    virtual ~Bullet();

    // Accessors
    sf::CircleShape getCircle();
    unsigned getDamage();

    // Functions
    sf::Vector2f getCenter();
    bool offBounds(sf::RenderTarget& window);
    void move(sf::Time elapsedTime);
    void render(sf::RenderTarget& target);
};
