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
        this->setMovementSpeed(0.1f);
        break;
    case Enemy::EnemyType::ADVANCED:
        this->setHP(30);
        this->setMovementSpeed(0.2f);
        break;
    case Enemy::EnemyType::BOSS:
        this->setHP(100);
        this->setMovementSpeed(0.1f);
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
        this->setTexture("Textures/basic_enemy.png");
        break;
    case Enemy::EnemyType::ADVANCED:
        this->setTexture("Textures/advanced_enemy.png");
        break;
    case Enemy::EnemyType::BOSS:
        this->setTexture("Textures/boss_enemy.png");
        break;
    default:
        std::cout << "ERROR::ENEMY::INITSPRITE::Invalid enemyType." << "\n";
    }
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
* Move the entity towards the given position
* @param pos the position that the enemy will move towards
* @param elapsedTime the amount of time elapsed since the last frame
*/
void Enemy::moveTowardsPos(sf::Vector2f pos, sf::Time elapsedTime)
{
    float x = 0;
    float y = 0;
    sf::Vector2f currentPos = this->getPosition();
    if (currentPos.x < pos.x)
    {
        x++;
    }
    else if (currentPos.x > pos.x)
    {
        x--;
    }
    if (currentPos.y < pos.y)
    {
        y++;
    }
    else if (currentPos.y > pos.y)
    {
        y--;
    }
    this->move(x, y, elapsedTime);
}

/**
* Updates the Enemy object
*/
void Enemy::update()
{
}
