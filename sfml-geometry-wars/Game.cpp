#include "Game.h"

/**
* Initializes variables. Sets window and player to nullptr
*/
void Game::initVariables()
{
    this->dt = sf::microseconds(0);
    this->lastSpawn = sf::microseconds(0);
    this->lastEnemyUpgrade = sf::microseconds(0);
    this->lastBullet = sf::microseconds(0);
    this->spawnTimer = 1;
    this->score = 0;
    this->enemyStage = 0;
    this->enemyUpgradeTime = 3;
    this->mouseHeld = false;
}

/**
* Initializes window to default settings
*/
void Game::initWindow()
{
    this->videoMode.width = Game::screenWidth;
    this->videoMode.height = Game::screenHeight;

    this->window.reset(new sf::RenderWindow(this->videoMode, "Geometry Wars",
        sf::Style::Titlebar | sf::Style::Close));

    this->window->setFramerateLimit(60);
}

/**
* Loads in font from file
*/
void Game::initFont()
{
    if (!this->font.loadFromFile("Fonts/PixelFont.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONT::Failed to load font." << "\n";
    }
}

/**
* Initializes on screen text, i.e., HUD elements
*/
void Game::initUIText()
{
    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(36);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setPosition(10, 10);
    this->scoreText.setString("Score: 00000000");

    this->timerText.setFont(this->font);
    this->timerText.setCharacterSize(36);
    this->timerText.setFillColor(sf::Color::White);
    this->timerText.setPosition(10, 10 + 10 +
        this->scoreText.getLocalBounds().height);
    this->timerText.setString("0:00");
}

/**
* Initializes Player in the center of the screen
*/
void Game::initPlayer()
{
    this->player.reset(new Player(0, 0));
    sf::Vector2f centerPos = player->getCenterLocal();
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

    this->initFont();
    this->initUIText();

    this->initPlayer();
}

/**
* Destroys a Game object
*/
Game::~Game()
{
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
                this->end();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
        this->player->getPosition().y > 0)
    {
        --y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        this->player->getPosition().y + this->player->getTexture().getSize().y
        < Game::screenHeight)
    {
        ++y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        this->player->getPosition().x > 0)
    {
        --x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        this->player->getPosition().x + this->player->getTexture().getSize().x
        < Game::screenWidth)
    {
        ++x;
    }
    this->player->move(x, y, dt);
}

/**
* Updates mousePosWindow and mousePosView. Spawns bullets when mouse is clicked.
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
        }
        if ((this->clock.getElapsedTime() - this->lastBullet).asMilliseconds()
            >= static_cast<sf::Int32> (this->player->getFiringRate()))
        {
            this->bullets.push_back(std::unique_ptr<Bullet> (new Bullet(this->player->getCenterWindow(),
                sf::Vector2f(this->mousePosView.x, this->mousePosView.y),
                this->player->getDamage())));
            this->lastBullet = this->clock.getElapsedTime();
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}

/**
* Updates enemies
* - Spawns enemies
* - Removes dead enemies
* - Checks for player contact with enemies
* - Upgrade enemies
*/
void Game::updateEnemies()
{
    // Spawn in enemies from directly offscreen
    if ((this->clock.getElapsedTime() - this->lastSpawn).asSeconds()
        >= spawnTimer)
    {
        Enemy::EnemyType et = static_cast<Enemy::EnemyType> (rand() % 3);
        std::unique_ptr<Enemy> e (new Enemy(0, 0, et, this->enemyStage));
        float x = static_cast<float> (rand() % static_cast<int>
            (this->window->getSize().x));
        float y = static_cast<float> (rand() % static_cast<int>
            (this->window->getSize().y));

        // Change enemy position to be offscreen
        int spawnType = rand() % 4;
        switch (spawnType)
        {
        case 0:
            // North
            y = static_cast<float>
                (-1 * static_cast<int> (e->getTexture().getSize().y));
            break;
        case 1:
            // East
            x = static_cast<float> (this->window->getSize().x);
            break;
        case 2:
            // South
            y = static_cast<float> (this->window->getSize().y);
            break;
        case 3:
            // West
            x = static_cast<float>
                (-1 * static_cast<int> (e->getTexture().getSize().x));
            break;
        default:
            std::cout << "ERROR::GAME::UPDATEENEMIES::Invalid spawnType."
                << "\n";
        }
        e->setPosition(x, y);
        this->enemies.push_back(std::move(e));
        this->lastSpawn = this->clock.getElapsedTime();
    }

    // Remove enemies that contacted player, receive damage
    for (size_t i = 0; i < this->enemies.size(); ++i)
    {
        if (this->enemies[i]->getSprite().getGlobalBounds().intersects(
            this->player->getSprite().getGlobalBounds()))
        {
            this->enemies.erase(this->enemies.begin() + i);
            if (!this->player->receiveDamage(1))
            {
                // End game if player is dead
                this->end();
            }
        }
    }

    // Move enemies towards player position
    for (size_t i = 0; i < this->enemies.size(); ++i)
    {
        this->enemies[i]->moveTowardsPos(this->player->getPosition(), this->dt);
    }

    if ((this->clock.getElapsedTime() - this->lastEnemyUpgrade).asSeconds()
        >= this->enemyUpgradeTime)
    {
        ++this->enemyStage;
        this->lastEnemyUpgrade = this->clock.getElapsedTime();
    }
}

/**
* Updates all the bullets. Moves all bullets towards target and checks for
* collision with enemy. Removes offscreen bullets.
*/
void Game::updateBullets()
{
    std::vector<int> removeList;
    for (int i = 0; i < bullets.size(); ++i)
    {
        bool deleted = false;
        bullets[i]->move(this->dt);
        for (int j = 0; j < enemies.size(); ++j)
        {
            // Check for collision
            if (enemies[j]->getSprite().getGlobalBounds().intersects(
                bullets[i]->getCircle().getGlobalBounds()))
            {
                deleted = true;
                if (!enemies[j]->receiveDamage(bullets[i]->getDamage()))
                {
                    updateScore(enemies[j]->getPointValue());
                    enemies.erase(enemies.begin() + j);
                    break;
                }
            }
        }
        // Check for out of bounds
        if (bullets[i]->offBounds(*this->window))
        {
            deleted = true;
        }
        // Add to remove list
        if (deleted)
        {
            removeList.push_back(i);
        }
    }

    // Remove deleted bullets
    int removedCount = 0;
    for (int i = 0; i < removeList.size(); ++i)
    {
        int actualIndex = i - removedCount;
        bullets.erase(bullets.begin() + actualIndex);
        ++removedCount;
    }
}

/**
* Updates the score
* @param points number of points to be added to the score
*/
void Game::updateScore(unsigned points)
{
    this->score += points;
}

/**
* Updates the UI text elements, namely the timer and score counter
*/
void Game::updateUIText()
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0')
        << static_cast<int>(this->clock.getElapsedTime().asSeconds() / 60)
        << ":" << std::setw(2) << std::setfill('0')
        << static_cast<int> (this->clock.getElapsedTime().asSeconds()) % 60;

    this->timerText.setString(ss.str());

    ss.str("");
    ss << "Score: " << std::setw(8) << std::setfill('0') << this->score;
    this->scoreText.setString(ss.str());
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
    this->updateKeyboardInput();
    this->updateMousePositions();
    this->player->update();
    this->updateEnemies();
    this->updateBullets();
    this->updateUIText();
}

/**
* Renders all enemies onto the window
*/
void Game::renderEnemies()
{
    for (int i = 0; i < enemies.size(); ++i)
    {
        enemies[i]->render(*this->window);
    }
}

/**
* Renders the bullets onto the window
*/
void Game::renderBullets()
{
    for (int i = 0; i < bullets.size(); ++i)
    {
        bullets[i]->render(*this->window);
    }
}

/**
* Renders the text elements of the game onto the window
*/
void Game::renderUIText()
{
    this->window->draw(this->scoreText);
    this->window->draw(this->timerText);
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

    this->player->render(*this->window);
    this->renderEnemies();
    this->renderBullets();
    this->renderUIText();

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

/**
* Ends the game. Closes the window.
*/
void Game::end()
{
    this->window->close();
}
