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
    float radius;

    // Initializers
    void initVariables();
    void initMoveXY(sf::Vector2f startPos, sf::Vector2f target);
    void initCircle(sf::Vector2f startPos);

public:
    Bullet(sf::Vector2f startPos, sf::Vector2f target);
    virtual ~Bullet();

    // Accessors
    sf::CircleShape getCircle();

    // Functions
    sf::Vector2f getCenter();
    bool offBounds(sf::RenderTarget& window);
    void move(sf::Time elapsedTime);
    void render(sf::RenderTarget& target);
};
