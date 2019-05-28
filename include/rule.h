/*
RULE.H

This file contains only a struct that is responsible to store
all informations about the --rule flag in command line
*/


#ifndef RULE_H
#define RULE_H

/*! \struct Rule
    \brief Stores the rule used in the game
*/
struct Rule
{
	int b[9]{ 3, -1, -1, -1, -1, -1, -1, -1, -1 };
	int s[9]{ 2, 3, -1, -1, -1, -1, -1, -1, -1 };
};

#endif