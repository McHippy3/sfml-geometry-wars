#pragma once

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

    // Initializers
    void initVariables();
    void initMoveXY(float x, float y, sf::Vector2f target);
    void initCircle();

public:
    Bullet(float x, float y, sf::Vector2f target);
    virtual ~Bullet();

    // Functions
    sf::Vector2f getCenter();
    void update();
};
