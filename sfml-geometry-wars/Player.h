#pragma once

#include "Entity.h"

class Entity;

class Player :
    public Entity
{
private:
    // Variables
    unsigned firingRate; // milliseconds

    // Initializers
    void initVariables();
    void initSprite();

public:
    // Constructor / Destructor
    Player(float x, float y);
    virtual ~Player();

    // Accessors
    unsigned getFiringRate();

    // Modifiers
    void setFiringRate(unsigned firingRate);

    // Functions
    void update();
};
