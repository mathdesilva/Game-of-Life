#include "prints.h"

void print_help( void )
{
	std::cout << "Usage: glife [<options>] <input_cfg_file>\n"
			  << "Simulation options:\n"
			  << "--help               Prints this help text.\n"
			  << "--imgdir <path>      Specify directory where output images are written to.\n"
			  << "--maxgen <num>       Maximum number of generations to simulate.\n"
			  << "--fps <num>          Number of generations presented per second.\n"
			  << "--blocksize <num>    Pixel size of a cell. Default = 5.\n"
			  << "--bkgcolor <color>   Color name for the background. Default GREEN.\n"
			  << "--alivecolor <color> Color name for representing alive cells. Default RED.\n"
			  << "--outfile <filename> Write the text representation of the simulation to the given filename.\n"
			  << std::endl << std::endl
			  << "Available colors are:\n    BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n    GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n    WHITE YELLOW" << std::endl;

}
