// Header file (interface) for Player.h.

#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
//#include "Continent.h"
//#include "Country.h"

using namespace std;

#include "Hand.h"
#include "Dice.h"

// Player class creates player objects, initialized with player attributes
class Player
{
    private:
        string playerName;
        int armies; // number of armies owned by player
        int* parmies; // pointer to number of armies location
        // Declare continents
        string continent1; // will be of type Continent
        string continent2;
        string continent3;
        string continent4;
        // Declare countries
        string country1; // will be of type country
        string country2;
        string country3;
        string country4;
        string country5;
        string country6;
        string country7;

        vector<string> continents; // collection of Continent objects
        vector<string> countries; // collection of Country objects
        vector<string> countriesOwned; // collection of player owned Country objects
        Card card;
        Hand cards; // Hand of cards
        vector<Dice> diceFacility; // facility with Dice objects

    public:
        Player( ); // Default constructor
        void SetPlayerName( );
        string GetPlayerName( );
        void SetPlayerCountry( string );
        vector<string> GetPlayerCountries( );
        void SetPlayerCard( Card );
        Hand GetPlayerCards( );
        void SetPlayerArmy( int );
        int GetPlayerArmies( );
        void SetDice( Dice );
        vector<Dice> GetDice( );
        void DisplayAttributes( );

        virtual void Reinforce( ); // Reinforce interface
        virtual void Attack( ); // Attack interface
        virtual void Fortify( ); // Fortify interface
};

#endif // PLAYER_H
