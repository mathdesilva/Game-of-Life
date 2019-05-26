#include "game_manager.h"

Game_manager::Game_manager( int argc, char *argv[] )
{
	// Reading command line values
	bool ok = input_validation_cmd( argc, argv );
	if( not ok )
		throw std::runtime_error("Help was called");

	// Creating a life
	life = new Life( inpu_cfg_file );
} // Game_manager

Game_manager::~Game_manager( )
{
	delete life;
} // ~Game_manager

void Game_manager::start( )
{
	std::cout << "starting\n";
	

	// checking if have outfile directory to log
	std::ofstream logOut;
	if( this->outfile != "null" )
	{
		logOut.open(this->outfile);
		if( not logOut.is_open() )
			throw std::invalid_argument("Error to open out file");
	}

	int genCount = 1;
	while( true )
	{
		// image output
		if( this->imgdir != "null" )
			life->print_image( imgdir, bkgcolor, alivecolor, blocksize );

		// text output
		if( this->outfile != "null" )
			logOut << *life << std::endl;
		else
			std::cout << *life << std::endl;

		// next_generation
		life->next_generation( rule );

		// checks maxgen / stable / extinct

		if( maxgen != -1 and genCount++ == maxgen )
			break;
	}
} // start

bool Game_manager::input_validation_cmd( int argc, char *argv[] )
{
	for( int i{1} ; i < argc ; i++ )
	{
		std::string input = argv[i];

		// help option
		if( input == "--help" or input == "-h" )
		{
			print_help();
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
			if( not isInt(value) )
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
			if( not isInt(value) )
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
			if( not isInt(value) )
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

			if( value == "BLACK" )
			{
				this->bkgcolor.channels[0] = life::BLACK.channels[0];
				this->bkgcolor.channels[1] = life::BLACK.channels[1];
				this->bkgcolor.channels[2] = life::BLACK.channels[2];
			}
			if( value == "BLUE" )
			{
				this->bkgcolor.channels[0] = life::BLUE.channels[0];
				this->bkgcolor.channels[1] = life::BLUE.channels[1];
				this->bkgcolor.channels[2] = life::BLUE.channels[2];
			}
			if( value == "CRIMSON" )
			{
				this->bkgcolor.channels[0] = life::CRIMSON.channels[0];
				this->bkgcolor.channels[1] = life::CRIMSON.channels[1];
				this->bkgcolor.channels[2] = life::CRIMSON.channels[2];
			}
			if( value == "DARK_GREEN" )
			{
				this->bkgcolor.channels[0] = life::DARK_GREEN.channels[0];
				this->bkgcolor.channels[1] = life::DARK_GREEN.channels[1];
				this->bkgcolor.channels[2] = life::DARK_GREEN.channels[2];
			}
			if( value == "DEEP_SKY_BLUE" )
			{
				this->bkgcolor.channels[0] = life::DEEP_SKY_BLUE.channels[0];
				this->bkgcolor.channels[1] = life::DEEP_SKY_BLUE.channels[1];
				this->bkgcolor.channels[2] = life::DEEP_SKY_BLUE.channels[2];
			}
			if( value == "DODGER_BLUE" )
			{
				this->bkgcolor.channels[0] = life::DODGER_BLUE.channels[0];
				this->bkgcolor.channels[1] = life::DODGER_BLUE.channels[1];
				this->bkgcolor.channels[2] = life::DODGER_BLUE.channels[2];
			}
			if( value == "GREEN" )
			{
				this->bkgcolor.channels[0] = life::GREEN.channels[0];
				this->bkgcolor.channels[1] = life::GREEN.channels[1];
				this->bkgcolor.channels[2] = life::GREEN.channels[2];
			}
			if( value == "LIGHT_BLUE" )
			{
				this->bkgcolor.channels[0] = life::LIGHT_BLUE.channels[0];
				this->bkgcolor.channels[1] = life::LIGHT_BLUE.channels[1];
				this->bkgcolor.channels[2] = life::LIGHT_BLUE.channels[2];
			}
			if( value == "LIGHT_GREY" )
			{
				this->bkgcolor.channels[0] = life::LIGHT_GREY.channels[0];
				this->bkgcolor.channels[1] = life::LIGHT_GREY.channels[1];
				this->bkgcolor.channels[2] = life::LIGHT_GREY.channels[2];
			}
			if( value == "LIGHT_YELLOW" )
			{
				this->bkgcolor.channels[0] = life::LIGHT_YELLOW.channels[0];
				this->bkgcolor.channels[1] = life::LIGHT_YELLOW.channels[1];
				this->bkgcolor.channels[2] = life::LIGHT_YELLOW.channels[2];
			}
			if( value == "RED" )
			{
				this->bkgcolor.channels[0] = life::RED.channels[0];
				this->bkgcolor.channels[1] = life::RED.channels[1];
				this->bkgcolor.channels[2] = life::RED.channels[2];
			}
			if( value == "STEEL_BLUE" )
			{
				this->bkgcolor.channels[0] = life::STEEL_BLUE.channels[0];
				this->bkgcolor.channels[1] = life::STEEL_BLUE.channels[1];
				this->bkgcolor.channels[2] = life::STEEL_BLUE.channels[2];
			}
			if( value == "WHITE" )
			{
				this->bkgcolor.channels[0] = life::WHITE.channels[0];
				this->bkgcolor.channels[1] = life::WHITE.channels[1];
				this->bkgcolor.channels[2] = life::WHITE.channels[2];
			}
			if( value == "YELLOW" )
			{
				this->bkgcolor.channels[0] = life::YELLOW.channels[0];
				this->bkgcolor.channels[1] = life::YELLOW.channels[1];
				this->bkgcolor.channels[2] = life::YELLOW.channels[2];
			}
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

			if( value == "BLACK" )
			{
				this->alivecolor.channels[0] = life::BLACK.channels[0];
				this->alivecolor.channels[1] = life::BLACK.channels[1];
				this->alivecolor.channels[2] = life::BLACK.channels[2];
			}
			if( value == "BLUE" )
			{
				this->alivecolor.channels[0] = life::BLUE.channels[0];
				this->alivecolor.channels[1] = life::BLUE.channels[1];
				this->alivecolor.channels[2] = life::BLUE.channels[2];
			}
			if( value == "CRIMSON" )
			{
				this->alivecolor.channels[0] = life::CRIMSON.channels[0];
				this->alivecolor.channels[1] = life::CRIMSON.channels[1];
				this->alivecolor.channels[2] = life::CRIMSON.channels[2];
			}
			if( value == "DARK_GREEN" )
			{
				this->alivecolor.channels[0] = life::DARK_GREEN.channels[0];
				this->alivecolor.channels[1] = life::DARK_GREEN.channels[1];
				this->alivecolor.channels[2] = life::DARK_GREEN.channels[2];
			}
			if( value == "DEEP_SKY_BLUE" )
			{
				this->alivecolor.channels[0] = life::DEEP_SKY_BLUE.channels[0];
				this->alivecolor.channels[1] = life::DEEP_SKY_BLUE.channels[1];
				this->alivecolor.channels[2] = life::DEEP_SKY_BLUE.channels[2];
			}
			if( value == "DODGER_BLUE" )
			{
				this->alivecolor.channels[0] = life::DODGER_BLUE.channels[0];
				this->alivecolor.channels[1] = life::DODGER_BLUE.channels[1];
				this->alivecolor.channels[2] = life::DODGER_BLUE.channels[2];
			}
			if( value == "GREEN" )
			{
				this->alivecolor.channels[0] = life::GREEN.channels[0];
				this->alivecolor.channels[1] = life::GREEN.channels[1];
				this->alivecolor.channels[2] = life::GREEN.channels[2];
			}
			if( value == "LIGHT_BLUE" )
			{
				this->alivecolor.channels[0] = life::LIGHT_BLUE.channels[0];
				this->alivecolor.channels[1] = life::LIGHT_BLUE.channels[1];
				this->alivecolor.channels[2] = life::LIGHT_BLUE.channels[2];
			}
			if( value == "LIGHT_GREY" )
			{
				this->alivecolor.channels[0] = life::LIGHT_GREY.channels[0];
				this->alivecolor.channels[1] = life::LIGHT_GREY.channels[1];
				this->alivecolor.channels[2] = life::LIGHT_GREY.channels[2];
			}
			if( value == "LIGHT_YELLOW" )
			{
				this->alivecolor.channels[0] = life::LIGHT_YELLOW.channels[0];
				this->alivecolor.channels[1] = life::LIGHT_YELLOW.channels[1];
				this->alivecolor.channels[2] = life::LIGHT_YELLOW.channels[2];
			}
			if( value == "RED" )
			{
				this->alivecolor.channels[0] = life::RED.channels[0];
				this->alivecolor.channels[1] = life::RED.channels[1];
				this->alivecolor.channels[2] = life::RED.channels[2];
			}
			if( value == "STEEL_BLUE" )
			{
				this->alivecolor.channels[0] = life::STEEL_BLUE.channels[0];
				this->alivecolor.channels[1] = life::STEEL_BLUE.channels[1];
				this->alivecolor.channels[2] = life::STEEL_BLUE.channels[2];
			}
			if( value == "WHITE" )
			{
				this->alivecolor.channels[0] = life::WHITE.channels[0];
				this->alivecolor.channels[1] = life::WHITE.channels[1];
				this->alivecolor.channels[2] = life::WHITE.channels[2];
			}
			if( value == "YELLOW" )
			{
				this->alivecolor.channels[0] = life::YELLOW.channels[0];
				this->alivecolor.channels[1] = life::YELLOW.channels[1];
				this->alivecolor.channels[2] = life::YELLOW.channels[2];
			}
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

			bool beforeBar = true;
			int bc = 0;
			int sc = 0;
			for( int i = 1; i < (int)value.size(); i++ )
			{
				if(beforeBar)
				{
					if(value[i] == '/'){
						beforeBar = false;
						i++;
						continue;
					}
					else{
						this->rule.b[bc] = value[i] - 48;
						bc++;
					}
				}
				else
				{
					this->rule.s[sc] = value[i] - 48;
					sc++;
				}
			}

			for(int i=bc; i<9; i++)
				rule.b[i] = -1;
			for(int i=sc; i<9; i++)
				rule.s[i] = -1;
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
