#include "Enemy.h"

/**
* Initializes variables. Sets health and movementSpeed based on enemyType
*/
void Enemy::initVariables(unsigned stage)
{
    this->stage = stage;
    float speedBonus = 0.03f * stage;
    int healthBonus = 5 * stage;
    switch (this->enemyType)
    {
    case Enemy::EnemyType::BASIC:
        this->setHP(10 + healthBonus);
        this->setMovementSpeed(0.1f + speedBonus);
        this->pointValue = 10;
        break;
    case Enemy::EnemyType::ADVANCED:
        this->setHP(30 + healthBonus);
        this->setMovementSpeed(0.2f + speedBonus);
        this->pointValue = 20;
        break;
    case Enemy::EnemyType::BOSS:
        this->setHP(100 + healthBonus);
        this->setMovementSpeed(0.1f + speedBonus);
        this->pointValue = 100;
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
Enemy::Enemy(float x, float y, Enemy::EnemyType et, unsigned stage)
{
    this->enemyType = et;
    this->initVariables(stage);
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
* @return the enemy's pointValue
*/
unsigned Enemy::getPointValue()
{
    return this->pointValue;
}

/**
* Updates the Enemy object
*/
void Enemy::update()
{
}
