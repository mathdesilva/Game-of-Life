#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <string>
#include <fstream>

#include "input_validation.h"
#include "prints.h"

class Life
{
private:
	bool ** mtx; //!< matrix of cells.
	size_t nLin; //!< line number of the matrix.
	size_t nCol; //!< column number of the matrix.
	char aliveChar; //!< alive cells char representation.

public:
	/// Constructor
	Life( std::string file );

	/// Destructor
	~Life( );

private:
	void dataFile_validation( std::string file );

}; // class Life

#endif