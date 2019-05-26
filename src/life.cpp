#include "life.h"

Life::Life( std::string file )
{
	// read input data file
	// save variables
	dataFile_validation( file );
} // Life

Life::~Life( )
{	
	// deleting matrix
	for(int i = 0; i < (int)this-> nLin; i++)
		delete [] this->mtx[i];
	delete [] this->mtx;

	// deleting all matrix saved in vector
	for(int j = 0; j < (int)this->allmtx.size(); j++)
	{
		for(int i = 0; i < (int)this-> nLin; i++)
			delete [] this->allmtx[j][i];
		delete [] this->allmtx[j];
	}
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

void Life::print_image( std::string imgdir, const life::Color& bkgcolor, const life::Color& alivecolor, int blocksize )
{	
	std::string numbname = std::to_string(imageCount);
	if(imgdir[imgdir.size()-1] != '/')
		imgdir.append("/");
	imgdir.append(numbname);
	imgdir.append(".png");

	// const char* filename = (const char*)imgdir;
	Canvas image( this->nCol, this->nLin, blocksize );

	for(int y=0; y<(int)this->nLin; y++)
	{
		for(int x=0; x<(int)this->nCol; x++)
		{
			if(this->mtx[y][x] == false)
				image.pixel( life::Point2(x,y) , bkgcolor );
			else
				image.pixel( life::Point2(x,y) , alivecolor );
		}
	}

	//Encode the image
	unsigned error = lodepng::encode(imgdir, image.pixels(), image.width(), image.height());
    //if there's an error, display it
    if(error) throw std::invalid_argument("error in png generation");

  	imageCount++;
} // print_image

void Life::next_generation( const Rule& rule )
{
	this->allmtx.push_back(mtx); // stores the current generation.

	// temp matrix allocation
	bool ** temp = new bool* [this->nLin];
	for( int i = 0 ; i < (int)this->nLin ; i++ )
		temp[i] = new bool[this->nCol]{false};

	// generating new generation
	int neighbors;
	for( int i = 0 ; i < (int)this->nLin ; i++ )
	{
		for( int j = 0 ; j < (int)this->nCol ; j++ )
		{
			// counting neighbors
			neighbors = neighborsNumber( i, j );

			// new generation
			if( mtx[i][j] == false ) // if is dead
			{
				int ii = 0;
				while( rule.b[ii] != -1 )
				{
					if( rule.b[ii] == neighbors )
					{
						temp[i][j] = true;
						break;
					}
					ii++;
				}
			}
			else // if is alive
			{
				int ii = 0;
				while( rule.s[ii] != -1 )
				{
					if( rule.s[ii] == neighbors )
					{
						temp[i][j] = true;
						break;
					}
					ii++;
				}
			}
		} // for to j
	} // for to i

	mtx = temp;
} // next_generation

int Life::neighborsNumber( int i, int j )
{
	int ibeg, iend, jbeg, jend;
	int neighbors;
	ibeg = i - 1;
	iend = i + 1;
	jbeg = j - 1;
	jend = j + 1;
	if(i == 0){ ibeg = 0; iend = 1; }
	if(i == (int)nLin-1){ ibeg = nLin-2; iend = nLin-1; }
	if(j == 0){ jbeg = 0; jend = 1; }
	if(j == (int)nCol-1){ jbeg = nCol-2; jend = nCol-1; }
	neighbors = 0;
	for( int ii = ibeg ; ii <= iend ; ii++ )
		for( int jj = jbeg ; jj <= jend ; jj++ )
		{
			if(ii == i and jj == j)
				continue;
			if(mtx[ii][jj] == true)
				neighbors++;
		}

	return neighbors;
} // neighborsNumber
