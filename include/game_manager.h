#ifndef GAME_MANAGER
#define GAME_MANAGER

#include <iostream>
#include <string>
#include <stdexcept>

#include "prints.h"

class Game_manager
{
public:
	Game_manager( int argc, char *argv[] )
	{
		if( input_validation_cmd( argc, argv ) )
			input_save_cmd( argc, argv );
	}

private:
	bool input_validation_cmd( int argc, char *argv[] );
	void input_save_cmd( int argc, char *argv[] );

private:
	std::string imgdir;
	std::string maxgen;
	int fps;
	int blocksize;
	std::string bkgcolor;
	std::string alivecolor;
	std::string outfile;
	std::string rule;

}; // class game_manager

#endif