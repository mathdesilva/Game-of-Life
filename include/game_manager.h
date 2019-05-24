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
		try {
			print_alert("Reading arguments");
			input_validation_cmd( argc, argv );
			print_alert("Arguments was successfully read");
		} 
		catch (const std::invalid_argument& ia) {
			print_alert("ERROR");
			print_help();
		}
	}

private:
	bool input_validation_cmd( int argc, char *argv[] );

private:
	std::string imgdir="null";
	int maxgen=-1;
	int fps=-1;
	int blocksize=-1;
	std::string bkgcolor="null";
	std::string alivecolor="null";
	std::string outfile="null";
	std::string rule="null";
	std::string inpu_cfg_file="null";

}; // class game_manager

#endif