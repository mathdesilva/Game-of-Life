#include "game_manager.h"

bool Game_manager::input_validation_cmd( int argc, char *argv[] )
{
	for( int i{1} ; i < argc ; i++ )
	{
		std::string input = argv[i];
		if( input == "--help" or input == "-h" )
		{
			print_help();
			return false;
		}
		else if( input == "--imgdir" )
		{
			std::cout << "aaaaa\n";
		}
		else if( input == "--maxgen" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--fps" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--blocksize" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--bkgcolor" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--alivecolor" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--outfile" )
		{

			std::cout << "aaaaa\n";
		}
		else if( input == "--rule" )
		{

			std::cout << "aaaaa\n";
		}
		else
		{

			std::cout << "aaaaahehe\n";
		}
	
	} // inputs for

	return true;
} // input_validation_cmd

void Game_manager::input_save_cmd( int argc, char *argv[] )
{
	std::cout << "input_save\n";
}