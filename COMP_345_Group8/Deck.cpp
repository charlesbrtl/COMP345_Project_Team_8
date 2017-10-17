/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 5
 * Team 8
 */

#include "Deck.h"

/*string array containing the names of the three cards for identifying the type by
its number*/
static std::string cardName[] = {
	"infantry",
	"artillery",
	"cavalry",
	"null"
};

Deck::Deck() {

}
Deck::~Deck() {

}

//Creating the deck. The parameter is the number of cards/number of countries on the map
Deck::Deck(int size) {

	//initializing counters for each type of Card to 0
	int infCounter = 0;
	int artCounter = 0;
	int cavCounter = 0;

	//Assigning every third card as either artillery, cavalry or infantry
	for(int i = 0; i < size ; i++) {

		if(i%3 == 0) {
			Card c = infantry;
			//adds card to deck
			gameDeck.push_back(c);
			//keeps track of the number of infantry cards in the deck
			infCounter++;
		}
		else if (i%3 == 1) {
			Card c = artillery;
			//adds card to deck
			gameDeck.push_back(c);
			//keeps track of the number of artillery cards in the deck
			artCounter++;
		}
		else if (i%3 == 2) {
			Card c = cavalry;
			gameDeck.push_back(c);
			//keeps track of the number of cavalry cards in the deck
			cavCounter++;
		}

	}

	//randomizing the order of the cards using the Shuffle method
	shuffle(&gameDeck);

	std::cout << "Here is the shuffled deck of " << size << " cards:" << std::endl;
	//printing to console the contents of the shuffled deck
	for(unsigned int i = 0 ; i < gameDeck.size(); i++) {
			std::cout<< cardName[gameDeck.at(i).cardType] << std::endl;
	}

	std::cout << "This deck has " << infCounter << " Infantry cards, " << artCounter <<
			" Artillery cards, and " << cavCounter << " Cavalry cards.";

}
/*Shuffle method: iterates through the deck vector in decreasing order, switching the
cards with a card at a randomly generated index number*/
void Deck::shuffle(std::vector<Card>* c) {

	srand(time(0));
	rand();
	//initializing the size of the deck
	int size = c->size();
	//initializing the first randomly generated number
	int newPosition = rand() % size;

	for(int i = size-1; i > 0; i--) {

		//switching cards
		std::iter_swap(gameDeck.begin() + i, gameDeck.begin() + newPosition);
		//generates a new random number for next iteration
		newPosition = rand() % i;
	}

}
//Draw method: saves the card from end of the deck, and deletes it before returning it
Card Deck::draw() {

	Card drawnCard = gameDeck.back();
	gameDeck.pop_back();

	return drawnCard;

}




