#include "Game.h"

/**
* Initializes variables. Sets window and player to nullptr
*/
void Game::initVariables()
{
    this->window = nullptr;
    this->player = nullptr;
}

/**
* Initializes window to default settings
*/
void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1280;

    this->window = new sf::RenderWindow(this->videoMode, "Geometry Wars", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

/**
* Initializes Player
*/
void Game::initPlayer()
{
    this->player = new Player(100, 100);
}

/**
* Initializes Enemies
*/
void Game::initEnemies()
{
}

/**
* Constructs a Game object
*/
Game::Game()
{
    this->initVariables();
    this->initWindow();

    this->initPlayer();
    this->initEnemies();
}

/**
* Destroys a Game object
*/
Game::~Game()
{
    delete this->window;
    delete this->player;
}

/**
* Updates game based on SFML specific events
*/
void Game::updateSFMLEvents()
{    
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            break;
        }
    }
}

/**
* Updates game based on user input such as key strokes and mouse clicks
*/
void Game::updateInput()
{
    // Player movement
    float x = 0;
    float y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        --y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ++y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        --x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ++x;
    }
    this->player->move(x, y);
}

/**
* Primary update function
* - updates SFML events
* - updates input
* - updates player
* - updates enemies
*/
void Game::update()
{
    this->updateSFMLEvents();
    this->updateInput();
    this->player->update();
}

/**
* Primary render function
* - clear old frame
* - renders objects
* - display frame in window
*/
void Game::render()
{
    this->window->clear();

    // Draw player
    this->player->render(*this->window);

    this->window->display();
}

/**
* Runs the game. Continuously updates and renders the window until it is 
* closed
*/
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
