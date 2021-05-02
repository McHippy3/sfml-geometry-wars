#include "Enemy.h"

/**
* Initializes variables. Sets health and movementSpeed based on enemyType
*/
void Enemy::initVariables()
{
    switch (this->enemyType)
    {
    case Enemy::EnemyType::BASIC:
        this->setHP(10);
        this->setMovementSpeed(3);
        break;
    case Enemy::EnemyType::ADVANCED:
        this->setHP(30);
        this->setMovementSpeed(1);
        break;
    case Enemy::EnemyType::BOSS:
        this->setHP(100);
        this->setMovementSpeed(2);
        break;
    default:
        std::cout << "ERROR::ENEMY::INITVARIABLES::Invalid enemyType." << "\n";
    }
}

/**
* Initializes the sprite with a texture depending upon the enemytype
*/
void Enemy::initSprite()
{
    switch (this->enemyType)
    {
    case Enemy::EnemyType::BASIC:
        this->setTexture("textures/basic_enemy.png");
        break;
    case Enemy::EnemyType::ADVANCED:
        this->setTexture("textures/advanced_enemy.png");
        break;
    case Enemy::EnemyType::BOSS:
        this->setTexture("textures/boss_enemy.png");
        break;
    default:
        std::cout << "ERROR::ENEMY::INITSPRITE::Invalid enemyType." << "\n";
    }
    this->setSprite();
}


/**
* Constructs an Enemy object
*/
Enemy::Enemy(float x, float y, Enemy::EnemyType et)
{
    this->enemyType = et;
    this->initVariables();
    this->initSprite();
    this->setPosition(x, y);
}

/**
* Destroys an Enemy object
*/
Enemy::~Enemy()
{
}

/**
* Updates the Enemy object
*/
void Enemy::update()
{
}
