#include "game_manager.h"

bool Game_manager::input_validation_cmd( int argc, char *argv[] )
{
	for( int i{0} ; i < argc ; i++ )
	{
		std::cout << i << " - " << argv[i] << std::endl;
	}

	return true;
}

void Game_manager::input_save_cmd( int argc, char *argv[] )
{
	std::cout << "input_save\n";
}