#pragma once

#include "Entity.h"

class Entity;

class Player :
    public Entity
{
private:
    // Initializers
    void initVariables();
    void initSprite();

public:
    // Constructor / Destructor
    Player(float x, float y);
    virtual ~Player();

    // Functions
    void update();
};
