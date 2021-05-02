#include "Game.h"

// Private functions
void Game::initVariables()
{
    this->window = nullptr;
    this->player = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1280;

    this->window = new sf::RenderWindow(this->videoMode, "Geometry Wars", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
    this->player = new Player(100, 100);
}

void Game::initEnemies()
{
}

// Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();

    this->initPlayer();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
}

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

void Game::update()
{
    this->updateSFMLEvents();
    this->updateInput();
    this->player->update();
}

void Game::render()
{
    /*
        @return void
        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects
    */
    this->window->clear();

    // Draw player
    this->player->render(*this->window);

    this->window->display();
}

// Core
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
