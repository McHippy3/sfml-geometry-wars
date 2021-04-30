#include "Game.h"

int main()
{
    // Set seed for RNG
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init game engine
    Game game;

    game.run();

    return 0;
}
