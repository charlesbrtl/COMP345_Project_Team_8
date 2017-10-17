/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#include "Hand.h"

static std::string cardName[] = {
	"infantry",
	"artillery",
	"cavalry",
	"null"
};

Hand::Hand() {

}
Hand::~Hand() {

}
void Hand::addToHand(Card c) {
	playerHand.push_back(c);
}
int Hand::exchange() {

	int callCounter = 1;
	int armyNum = 5;
	std::vector<int> inf;
	std::vector<int> art;
	std::vector<int> cav;

	std::cout << "\n\nHere is the player's hand:" << std::endl;
	//prints the cards in the player's hand to console
	for(unsigned int i = 0 ; i < playerHand.size(); i++) {
			std::cout<< cardName[playerHand.at(i).cardType] << std::endl;
	}
	//refuses the exchange if calling player cannot perform one
	if(playerHand.size() < 3) {
		std::cout << "Not enough cards in hand to exchange." << std::endl;
	}
	//saves the index of each type of card to a respective vector
	for(unsigned int i = 0 ; i < playerHand.size() ; i++) {
		if(playerHand.at(i).cardType == infantry) {
			inf.push_back(i);
		}
		else if(playerHand.at(i).cardType == artillery) {
			art.push_back(i);
		}
		else if(playerHand.at(i).cardType == cavalry) {
			cav.push_back(i);
		}

	}

	//exchanges 3 of each type
	if(inf.size() >=1 && art.size() >= 1 && cav.size() >= 1) {
		std::cout << "Exchanging one infantry, one artillery, and one cavalry card for "
			 << armyNum << " soldiers." << std::endl;

		//sets the cards to null
		playerHand.at(inf.at(0)) = null;
		playerHand.at(art.at(0)) = null;
		playerHand.at(cav.at(0)) = null;

	}
	//exchanges 3 infantry cards
	else if(inf.size() >= 3) {
		std::cout << "Exchanging three infantry cards for " << armyNum << " soldiers."
				<< std::endl;

		//sets the cards to null
		playerHand.at(inf.at(0)) = null;
		playerHand.at(inf.at(1)) = null;
		playerHand.at(inf.at(2)) = null;

	}
	//exchanges 3 artillery cards
	else if(art.size() >= 3) {
		std::cout << "Exchanging three artillery cards for " << armyNum << " soldiers."
						<< std::endl;

		//sets the cards to null
		playerHand.at(art.at(0)) = null;
		playerHand.at(art.at(1)) = null;
		playerHand.at(art.at(2)) = null;

	}
	//exchanges cavalry cards
	else if(cav.size() >= 3) {
		std::cout << "Exchanging three cavalry cards for " << armyNum << " soldiers."
						<< std::endl;

		//sets the cards to null
		playerHand.at(cav.at(0)) = null;
		playerHand.at(cav.at(1)) = null;
		playerHand.at(cav.at(2)) = null;

	}
	//deletes the cards that were set to null from the player's hand
	for(int i = playerHand.size() - 1 ; i >= 0 ; i--) {
		if(playerHand.at(i).cardType == null) {
			playerHand.erase(playerHand.begin() + i);
		}
	}

	std::cout << "\nHere is the player's hand after the exchange:" << std::endl;
	//prints the cards in the player's hand to console
	for(unsigned int i = 0 ; i < playerHand.size(); i++) {
		std::cout<< cardName[playerHand.at(i).cardType] << std::endl;
	}

	//increments by one each time the exchange method is called
	callCounter++;

	return armyNum*callCounter;
}


