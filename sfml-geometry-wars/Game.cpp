#include "Game.h"

// Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1280;

    this->window = new sf::RenderWindow(this->videoMode, "[PLACEHOLDER]", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

// Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
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
    this->window->display();
}

// Core
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateSFMLEvents();
        this->render();
    }
}
