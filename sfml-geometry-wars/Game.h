#pragma once

#include <sstream>
#include <iomanip>

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
    sf::Font font;
    sf::Text timerText;
    sf::Text scoreText;

    // Game logic
    sf::Clock clock; //overall game clock
    sf::Clock deltaClock; //only for framerate
    sf::Time dt;
    sf::Time lastSpawn;
    unsigned spawnTimer;
    unsigned score;
    bool mouseHeld;

    // Game objects
    Player* player;
    std::vector<Enemy*> enemies;

    // Init functions
    void initVariables();
    void initWindow();

    void initFont();
    void initUIText();

    void initPlayer();

    // Update
    void updateSFMLEvents();
    void updateKeyboardInput();
    void updateMousePositions();
    void updateEnemies();
    void updateUIText();
    void update();

    // Render
    void renderEnemies();
    void renderUIText();
    void render();

public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Core
    void run();
};
