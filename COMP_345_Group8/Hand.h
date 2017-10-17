/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include "Card.h"
#include <vector>

class Hand {
private:
	std::vector<Card> playerHand;

public:
	Hand();
	~Hand();
	int exchange();
	void addToHand(Card c);
};

#endif // HAND_H_INCLUDED
