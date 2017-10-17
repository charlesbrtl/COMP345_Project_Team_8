/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#include "Card.h"


Card::Card() {
	cardType = artillery;
}

Card::~Card() {

}

Card::Card(Type t) {
	cardType = t;
}
std::ostream& operator<<(std::ostream& os, const Card& c) {
	os << c.cardType;
	return os;
}

