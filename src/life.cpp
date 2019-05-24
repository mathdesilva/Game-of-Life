#include "life.h"

Life::Life( std::string file )
{
	// read input data file
	// save variables
	try{
		dataFile_validation( file );
	}
	catch ( const std::invalid_argument& e){
		print_error(e.what());
		print_help();
	}

	// alocate matrix
	// put values in matrix
} // Life

Life::~Life( )
{	
	// deleting matrix
	for(int i = 0; i < (int)this-> nLin; i++)
		delete [] this->mtx[i];
	delete [] this->mtx;
} // ~Life

void Life::dataFile_validation( std::string file )
{
	// trying to open file
	std::ifstream inputFile;
	inputFile.open(file);
	if( not inputFile.is_open() )
		throw std::invalid_argument("Error to open input file");

	// reading first two lines, validating and saving it
	std::string val1;
	std::string val2;
	std::string val3;
	inputFile >> val1 >> val2 >> val3;
	if( not( isInt(val1) and isInt(val2) and isChar(val3) ) )
		throw std::invalid_argument("Invalid values in input file");
	this->nLin = stoi(val1);
	this->nCol = stoi(val2);
	this->aliveChar = val3[0];

	// matrix allocation
	this->mtx = new bool* [this->nLin];
	for( int i = 0 ; i < (int)this->nLin ; i++ )
		this->mtx[i] = new bool[this->nCol]{false};

	// reading matrix values from input file;
	std::string line;
	std::getline(inputFile, line);
	for( int i = 0 ; i < (int)this->nLin ; i++ )
	{
		if(inputFile.eof())
			throw std::invalid_argument("Invalid values in input file");
		std::getline(inputFile, line);

		for( int j = 0 ; (j < (int)this->nCol and j < (int)line.size()); j++ )
			if( line[j] == this->aliveChar )
				this->mtx[i][j] = true;
	}

	// closing file
	inputFile.close();
} // dataFile_validation

std::ostream& operator<<(std::ostream& os, const Life& lf)
{
	for(int i=0; i<(int)lf.nLin; i++)
	{
		os << '[';
		for(int j=0; j<(int)lf.nCol; j++)
		{
			if(lf.mtx[i][j] == false)
				os << ' ';
			else
				os << lf.aliveChar;
		}
		os << ']' << std::endl;
	}

	return os;
} // operator<<
