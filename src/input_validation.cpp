#include "input_validation.h"

bool isInt( std::string in )
{
	for(int i = 0; i < (int)in.size(); i++)
	{
		if(in[i] < '0' or in[i] > '9')
			return false;
	}

	return true;
}

bool isChar( std::string in )
{
	if( in.size() == 1 )
		return true;
	else
		return false;
}