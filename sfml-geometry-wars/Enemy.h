#pragma once

#include "Entity.h"

class Entity;

class Enemy :
    public Entity
{
public: 
    enum class EnemyType
    {
        BASIC,
        ADVANCED,
        BOSS
    };

private:
    // Variables
    unsigned pointValue;
    Enemy::EnemyType enemyType;
    unsigned stage;

    // Initializers
    void initVariables(unsigned stage);
    void initSprite();

public:
    // Constructor / Destructor
    Enemy(float x, float y, Enemy::EnemyType et, unsigned stage);
    virtual ~Enemy();

    // Accessors
    unsigned getPointValue();

    // Functions
    void moveTowardsPos(sf::Vector2f pos, sf::Time elapsedTime);
    void update();
};
