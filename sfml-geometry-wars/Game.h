#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources

    // Text

    // Game logic

    // Game objects

    // Init functions
    void initVariables();
    void initWindow();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Accessors

    // Update
    void updateSFMLEvents();

    // Render
    void render();

    // Core
    void run();
};
