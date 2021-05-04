#include "Game.h"

/**
* Initializes variables. Sets window and player to nullptr
*/
void Game::initVariables()
{
    this->window = nullptr;
    this->player = nullptr;
    this->dt = sf::microseconds(0);
    this->spawnTimer = 5;
    this->mouseHeld = false;
}

/**
* Initializes window to default settings
*/
void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1280;

    this->window = new sf::RenderWindow(this->videoMode, "Geometry Wars", 
        sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

/**
* Initializes Player in the center of the screen
*/
void Game::initPlayer()
{
    this->player = new Player(0, 0);
    sf::Vector2f centerPos = player->getCenter();
    float x = static_cast<float> (this->window->getSize().x / 2.f
        - centerPos.x);
    float y = static_cast<float> (this->window->getSize().y / 2.f
        - centerPos.y);
    this->player->setPosition(x, y);
}

/**
* Constructs a Game object
*/
Game::Game()
{
    this->initVariables();
    this->initWindow();

    this->initPlayer();
}

/**
* Destroys a Game object
*/
Game::~Game()
{
    delete this->window;
    delete this->player;
    for (auto* e : enemies)
    {
        delete e;
    }
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
* Updates game based on user input from keyboard
*/
void Game::updateKeyboardInput()
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
    this->player->move(x, y, dt);
}

/**
* Updates mousePosWindow and mousePosView. Outputs current mouse position to
* console.
*/
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!this->mouseHeld)
        {
            this->mouseHeld = true;
            std::cout << "MOUSE_POSITION: " << this->mousePosView.x << " "
                << this->mousePosView.y << std::endl;
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}

/**
* Updates enemies. Spawns enemies according to timer. Removes enemies with no
* hp.
*/
void Game::updateEnemies()
{
    // Generate 
    if (this->clock.getElapsedTime().asSeconds() >= this->spawnTimer * enemies.size() + 1)
    {
        float x = static_cast<float> (rand() % static_cast<int>
            (this->window->getSize().x));
        float y = static_cast<float> (rand() % static_cast<int>
            (this->window->getSize().y));
        Enemy::EnemyType et = static_cast<Enemy::EnemyType> (rand() % 3);
        this->enemies.push_back(new Enemy(x, y, et));
    }
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
    this->updateMousePositions();
    this->updateKeyboardInput();
    this->player->update();
    this->updateEnemies();
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
    for (auto* e : enemies)
    {
        e->render(*this->window);
    }

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
        this->dt = this->deltaClock.restart();
    }
}
