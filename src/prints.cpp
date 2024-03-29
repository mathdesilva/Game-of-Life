#include "prints.h"


void print_welcome( void )
{
	std::cout << std::endl << std::endl
			  << "****************************************************************\n"
			  << "  Welcome to Conway’s game of Life.\n"
			  << "  each cell can either be occupied by an organism or not.\n"
			  << "  The occupied cells change from generation to generation\n"
			  << "  according to the number of neighboring cells which are alive.\n"
			  << "****************************************************************\n"
			  << std::endl << std::endl;
} // print_welcome

void print_message( std::string str )
{
	std::cout << str << std::endl;
} // print_message

void print_help( void )
{
	std::cout << ">>> HELP <<<\n"
			  << "Usage: glife [<options>] <input_cfg_file>\n\n"
			  << "Simulation options:\n"
			  << "  --help               Prints this help text.\n\n"
			  << "  --imgdir <path>      Specify directory where output images are written to.\n\n"
			  << "  --maxgen <num>       Maximum number of generations to simulate.\n\n"
			  << "  --fps <num>          Number of generations presented per second. Default = 2\n\n"
			  << "  --blocksize <num>    Pixel size of a cell. Default = 10.\n\n"
			  << "  --bkgcolor <color>   Color name for the background. Default = GREEN.\n\n"
			  << "  --alivecolor <color> Color name for representing alive cells. Default = BLUE.\n\n"
			  << "  --outfile <filename> Write the text representation of the simulation to the given filename.\n\n"
			  << "  --rule <code>        Specify evolution rule using B-/S- code, B for born and S for survives. Default = B3/S23\n\n"
			  << std::endl << std::endl
			  << "Available colors are:\n    BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n    GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n    WHITE YELLOW" << std::endl;

}

void print_error( std::string str )
{
	std::cout << "ERROR: " << str << std::endl;
}
