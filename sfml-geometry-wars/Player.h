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
    void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);
    void render(sf::RenderTarget& target);
};
