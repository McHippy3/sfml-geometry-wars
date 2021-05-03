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
    sf::Clock clock; //overall game clock
    sf::Clock deltaClock; //only for framerate
    sf::Time dt;
    int spawnTimer;
    bool mouseHeld;

    // Game objects
    Player* player;
    std::vector<Enemy*> enemies;

    // Init functions
    void initVariables();
    void initWindow();

    void initPlayer();

    // Update
    void updateSFMLEvents();
    void updateKeyboardInput();
    void updateMousePositions();
    void updateEnemies();
    void update();

    // Render
    void render();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Core
    void run();
};
