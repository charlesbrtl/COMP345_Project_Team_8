/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>

enum Type
	{
		infantry,
		artillery,
		cavalry,
		null
	};

class Card {

public:
	Type cardType;

	Card();
	~Card();
	Card(Type t);

};
std::ostream& operator<<(std::ostream& os, const Card& c);

#endif

