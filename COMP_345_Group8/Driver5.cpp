/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#include "Deck.h"

int main(int argc, char* argv[]) {

	//creates a deck testing
	Deck *riskDeck = new Deck(46);
	//creates a hand
	Hand riskHand;
	//draw method + adding the drawn card to hand
	riskHand.addToHand(riskDeck->draw());
	riskHand.addToHand(riskDeck->draw());
	riskHand.addToHand(riskDeck->draw());
	riskHand.addToHand(riskDeck->draw());
	riskHand.addToHand(riskDeck->draw());
	//exchange method
	riskHand.exchange();


}

