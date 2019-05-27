#include <iostream>
#include <vector>
#include <fstream>

#include "game_manager.h"

/// Main
int main(int argc, char *argv[])
{
    Game_manager game( argc, argv );
    game.start();

    return 0;
}
