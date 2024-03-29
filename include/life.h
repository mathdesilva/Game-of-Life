/*
LIFE.H

This file constains only the Life class
*/


#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "input_validation.h"
#include "prints.h"
#include "lodepng.h"
#include "canvas.h"
#include "common.h"
#include "rule.h"

/*! \class Life
    \brief Controls all generations

    Contains all tools to generate new generations and get some informations about it.
*/
class Life
{
private:
	bool ** mtx; //!< matrix of cells.
	size_t nLin; //!< line number of the matrix.
	size_t nCol; //!< column number of the matrix.
	char aliveChar; //!< alive cells char representation.
	int imageCount = 1; //!< count the number of images.
	int streamCount = 1; //!< count the number of output generations.
	std::vector< bool** > allmtx; //!< Stores all generations matrix.

public:
	/// Constructor
	Life( std::string file );

	/// Destructor
	~Life( );

	/// operator<< overload to print all matrix
	friend std::ostream& operator<<(std::ostream& os, const Life& lf);

	// generate cell image png
	void print_image( std::string imgdir, const life::Color& bkgcolor, const life::Color& alivecolor, int blocksize );

	/// get number of lines
	size_t lines( )
	{ return nLin; }

	/// get number of columns
	size_t columns( )
	{ return nCol; }

	/// get char that representates alive cells
	char charAlive( )
	{ return aliveChar; }

	/// sum one to this->streamCount
	void streamCountpp( void )
	{ this->streamCount++; }

	/// generates the next generation
	void next_generation( const Rule& rule );

	/// checks if the generation is extinct
	bool extinct( );

	/// checks if the generation is stable
	bool stable( );

private:
	/// checks and save input file values
	void dataFile_validation( std::string file );

	/// count number of neighbors
	int neighborsNumber( int i, int j );

}; // class Life

#endif