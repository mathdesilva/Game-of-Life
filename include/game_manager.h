#ifndef GAME_MANAGER
#define GAME_MANAGER

#include <iostream>
#include <string>
#include <stdexcept>

#include "prints.h"
#include "life.h"
#include "input_validation.h"

class Game_manager
{
private:
	std::string imgdir="null"; //!< Image directory.
	int maxgen=-1; //!< Max generetion value.
	int fps=-1; //!< FPS of output.
	int blocksize=-1; //!< size of "big pixel" block.
	std::string bkgcolor="null"; //!< Background color.
	std::string alivecolor="null"; //!< Alive cells color.
	std::string outfile="null"; //!< output file name.
	std::string rule="null"; //!< rule code.
	std::string inpu_cfg_file="null"; //!< input file name.
	Life * life; //!< file pointer.

public:
	/// Constructor
	Game_manager( int argc, char *argv[] );

	/// Destructor
	~Game_manager( );

private:
	/// Validate and save command line inputs
	bool input_validation_cmd( int argc, char *argv[] );

}; // class game_manager

#endif