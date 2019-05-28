/*
GAME_MANAGER.H

This file contains only the Game_manager class that reads
all input values and starts the game.
*/


#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <thread>

#include "prints.h"
#include "life.h"
#include "input_validation.h"
#include "rule.h"

/*! \class Game_manager
    \brief controls the game
	
    This class reads all input values and starts the game.
*/
class Game_manager
{
private:
	std::string imgdir="null"; //!< Image directory.
	int maxgen=-1; //!< Max generetion value.
	int fps=1000000000 / 2; //!< FPS of output.
	int blocksize=10; //!< size of "big pixel" block.
	life::Color bkgcolor = Color{0,250,0}; //!< green.
	life::Color alivecolor = Color{70,130,180}; //!< blue.
	std::string outfile="null"; //!< output file name.
	Rule rule; //!< rule code.
	std::string inpu_cfg_file="null"; //!< input file name.
	Life * life = nullptr; //!< file pointer.

public:
	/// Constructor
	Game_manager( int argc, char *argv[] );

	/// Destructor
	~Game_manager( );

	/// Start the game
	void start( );

private:
	/// Validate and save command line inputs
	bool input_validation_cmd( int argc, char *argv[] );

}; // class game_manager

#endif
