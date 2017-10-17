/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#ifndef HAND_H_
#define HAND_H_

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

#endif
