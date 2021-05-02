#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Enemy.h"
#include "Player.h"

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
    Player* player;

    // Init functions
    void initVariables();
    void initWindow();

    void initPlayer();
    void initEnemies();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Accessors

    // Update
    void updateSFMLEvents();
    void update();

    // Render
    void render();

    // Core
    void run();
};
