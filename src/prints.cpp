#include "prints.h"

void print_help( void )
{
	std::cout << ">>> HELP <<<\n"
			  << "Usage: glife [<options>] <input_cfg_file>\n\n"
			  << "Simulation options:\n"
			  << "  --help               Prints this help text.\n\n"
			  << "  --imgdir <path>      Specify directory where output images are written to.\n\n"
			  << "  --maxgen <num>       Maximum number of generations to simulate.\n\n"
			  << "  --fps <num>          Number of generations presented per second.\n\n"
			  << "  --blocksize <num>    Pixel size of a cell. Default = 5.\n\n"
			  << "  --bkgcolor <color>   Color name for the background. Default GREEN.\n\n"
			  << "  --alivecolor <color> Color name for representing alive cells. Default RED.\n\n"
			  << "  --outfile <filename> Write the text representation of the simulation to the given filename.\n\n"
			  << "  --rule <code>        Specify evolution rule using Bx/Sx code, B for born and S for survives.\n\n"
			  << std::endl << std::endl
			  << "Available colors are:\n    BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n    GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n    WHITE YELLOW" << std::endl;

}

void print_error( std::string str )
{
	std::cout << "ERROR: " << str << std::endl;
}