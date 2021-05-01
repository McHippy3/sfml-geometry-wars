#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

class Entity
{
private:
    void initTexture(std::string textureFilePath);
    void initSprite();

protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor / Destructor
    Entity(std::string textureFilePath);
    virtual ~Entity();

    // Component functions

    // Accessors
    virtual const sf::Vector2f& getPosition() const;

    // Modifiers
    virtual void setPosition(const float x, const float y);

    // Pure virtual functions
    virtual void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};
