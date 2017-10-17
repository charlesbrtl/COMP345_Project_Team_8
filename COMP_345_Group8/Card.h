/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>

enum Type
	{
		infantry,
		artillery,
		cavalry
	};

class Card {

public:
	Type cardType;

	Card();
	~Card();
	Card(Type t);

};
std::ostream& operator<<(std::ostream& os, const Card& c);

#endif // CARD_H_INCLUDED

