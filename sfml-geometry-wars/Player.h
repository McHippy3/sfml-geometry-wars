#pragma once

#include "Entity.h"

class Entity;

class Player :
    public Entity
{
private:
    // Variables
    
    // Initializers
    void initVariables();
    void initComponents();

public:
    // Constructor / Destructor
    Player(float x, float y);
    virtual ~Player();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};
