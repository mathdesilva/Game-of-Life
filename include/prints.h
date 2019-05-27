#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>
#include <string>
#include <stdexcept>

/// Prints welcome message
void print_welcome( void );

/// Prints runtime messages
void print_message( std::string str );

/// Prints help message
void print_help( void );

/// Prints error messages
void print_error( std::string str );

#endif
