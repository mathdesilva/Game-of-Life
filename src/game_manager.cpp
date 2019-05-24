#include "game_manager.h"

Game_manager::Game_manager( int argc, char *argv[] )
{
	try {
		// Reading command line values
		input_validation_cmd( argc, argv );
		
		// Creating a life
		life = new Life( inpu_cfg_file );

		// test
		std::cout << *life << std::endl;
	} 
	catch (const std::invalid_argument& e) {
		print_error(e.what());
		print_help();
	}

} // Game_manager

Game_manager::~Game_manager( )
{
	delete life;
} // ~Game_manager

bool Game_manager::input_validation_cmd( int argc, char *argv[] )
{
	for( int i{1} ; i < argc ; i++ )
	{
		std::string input = argv[i];

		// help option
		if( input == "--help" or input == "-h" )
		{
			return false;
		}

		// image directory argument
		else if( input == "--imgdir" )
		{
			std::string value = argv[++i];
			if( value[0] == '-' or value[1] == '-' )
			{
				throw std::invalid_argument("Invalid value to --imgdir");
				return false;
			}

			this->imgdir = value;
		}

		// max generation number argument
		else if( input == "--maxgen" )
		{
			std::string value = argv[++i];
			for(int i = 0; i < (int)value.size(); i++)
				if(value[i] < '0' or value[i] > '9')
				{
					throw std::invalid_argument("invalid value to --maxgen");
					return false;
				}

			this->maxgen = stoi(value);
		}

		// fps number argument
		else if( input == "--fps" )
		{
			std::string value = argv[++i];
			for(int i = 0; i < (int)value.size(); i++)
				if(value[i] < '0' or value[i] > '9')
				{
					throw std::invalid_argument("invalid value to --fps");
					return false;
				}

			this->fps = stoi(value);
		}

		// blocksize value argument
		else if( input == "--blocksize" )
		{
			std::string value = argv[++i];
			for(int i = 0; i < (int)value.size(); i++)
				if(value[i] < '0' or value[i] > '9')
				{
					throw std::invalid_argument("invalid value to --blocksize");
					return false;
				}

			this->blocksize = stoi(value);
		}

		// background color argument
		else if( input == "--bkgcolor" )
		{
			std::string value = argv[++i];
			if( not( value == "BLACK" or value == "BLUE" or value == "CRIMSON" or value == "DARK_GREEN"
				or value == "DEEP_SKY_BLUE" or value == "DODGER_BLUE" or value == "GREEN" 
				or value == "LIGHT_BLUE" or value == "LIGHT_GREY" or value == "LIGHT_YELLOW" 
				or value == "RED" or value == "STEEL_BLUE" or value == "WHITE" or value == "YELLOW" ) )
			{
				throw std::invalid_argument("invalid value to --bkgcolor");
				return false;
			}

			this->bkgcolor = value;
		}

		// alive color argument
		else if( input == "--alivecolor" )
		{
			std::string value = argv[++i];
			if( not( value == "BLACK" or value == "BLUE" or value == "CRIMSON" or value == "DARK_GREEN"
				or value == "DEEP_SKY_BLUE" or value == "DODGER_BLUE" or value == "GREEN" 
				or value == "LIGHT_BLUE" or value == "LIGHT_GREY" or value == "LIGHT_YELLOW" 
				or value == "RED" or value == "STEEL_BLUE" or value == "WHITE" or value == "YELLOW" ) )
			{
				throw std::invalid_argument("invalid value to --alivecolor");
				return false;
			}

			this->alivecolor = value;
		}

		// outfile directory argument
		else if( input == "--outfile" )
		{
			std::string value = argv[++i];
			if( value[0] == '-' or value[1] == '-' )
			{
				throw std::invalid_argument("Invalid value to --outfile");
				return false;
			}

			this->outfile = value;
		}

		// rule argument
		else if( input == "--rule" )
		{
			std::string value = argv[++i];
			bool posB = false;
			bool posBar = false;
			bool posS = false;
			for( int i = 0; i < (int)value.size(); i++)
			{
				switch( value[i] )
				{
					case 'B':
						if( not posB ){
							posB = true;
							if( value[i+1] < '0' or value[i+1] > '8' )
							{
								throw std::invalid_argument("Invalid value to --rule");
								return false;
							}	
						} else {
							throw std::invalid_argument("Invalid value to --rule");
							return false;
						}
						break;
					case '/':
						if( not posBar ){
							posBar = true;
							if( value[i+1] != 'S' )
							{
								throw std::invalid_argument("Invalid value to --rule");
								return false;
							}	
						} else {
							throw std::invalid_argument("Invalid value to --rule");
							return false;
						}
						break;
					case 'S':
						if( not posS ){
							posS = true;
							if( value[i+1] < '0' or value[i+1] > '8' )
							{
								throw std::invalid_argument("Invalid value to --rule");
								return false;
							}	
						} else {
							throw std::invalid_argument("Invalid value to --rule");
							return false;
						}
						break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
						break;
					default:
						throw std::invalid_argument("Invalid value to --rule");
						return false;
				} // switch
			} // for

			if( not (posB or posBar or posS) )
			{
				throw std::invalid_argument("Invalid value to --rule");
				return false;
			}

			this->rule = value;
		} // else if --rule

		// default argument
		else
		{
			if(this->inpu_cfg_file == "null")
			{
				this->inpu_cfg_file = input;
			}
			else
			{
				throw std::invalid_argument("invalid value to input file");
				return false;
			}
		}
		
	} // inputs for

	if( this->inpu_cfg_file == "null" )
	{
		throw std::invalid_argument("no input file");
		return false;
	}

	return true;
} // input_validation_cmd
