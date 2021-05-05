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
    Enemy::EnemyType enemyType;

    // Initializers
    void initVariables();
    void initSprite();

public:
    // Constructor / Destructor
    Enemy(float x, float y, Enemy::EnemyType et);
    virtual ~Enemy();

    // Functions
    void moveTowardsPos(sf::Vector2f pos, sf::Time elapsedTime);
    void update();
};
