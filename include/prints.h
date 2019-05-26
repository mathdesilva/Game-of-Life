#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>
#include <string>
#include <stdexcept>

/*
#include "life.h"
#include "game_manager.h"

/// Prints beggining of the introduction message
void pre_print_intro(const Game_manager& gm);

/// Prints rest of the introduction message
void print_intro(Life& lf, const Game_manager& gm);
*/

/// Prints help message
void print_help( void );

/// Prints error messages
void print_error( std::string str );

#endif
