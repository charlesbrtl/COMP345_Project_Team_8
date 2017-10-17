/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "Card.h"
#include "Hand.h"

using namespace std;

class Deck {

public:
	std::vector<Card> gameDeck;

	Deck();
	~Deck();
	Deck(int size);
	void shuffle(std::vector<Card>* c);
	Card draw();


};

#endif

