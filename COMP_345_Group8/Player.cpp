// Implementation file Player.cpp of the class Player.

#include "Player.h"

// Default Player constructor
Player::Player( )
{
    playerName = "No Name Assigned";
    armies = 3; // minimum number of armies
    // Instantiate continents
    continent1 = "North Ammerica";
    continents.push_back( continent1 );
    continent2 = "Europe";
    continents.push_back( continent2 );
    continent3 = "Asia";
    continents.push_back( continent3 );
    continent4 = "Africa";
    continents.push_back( continent4 );
    // Instantiate countries
    country1 = "Canada";
    countries.push_back( country1 );
    countriesOwned.push_back( country1 );
    country2 = "US";
    countries.push_back( country2 );
    countriesOwned.push_back( country2 );
    country3 = "France";
    countries.push_back( country3 );
    country4 = "India";
    countries.push_back( country4 );
    country5 = "China";
    countries.push_back( country5 );
    country6 = "Japan";
    countries.push_back( country6 );
    country7 = "Egypt";
    countries.push_back( country7 );

    cards.addToHand( card );
}

Hand::Hand( ) { }
Hand::~Hand( ) { }
void Hand::addToHand( Card c ) { }
Card::Card( ) { }
Card::~Card( ) { }
Dice::Dice( ) { }
Dice::~Dice( ) { }

// Query for and set the player name
void Player::SetPlayerName( )
{
    cout << "Please Enter A Player Name: ";
    cin >> playerName;
    cout << "Welcome, " << playerName << "!" << endl;
}

// Get player name
string Player::GetPlayerName( )
{
    return playerName;
}

// Set newly captured country by adding to player's owned countries list
void Player::SetPlayerCountry( string newcountry )
{
    countriesOwned.push_back( newcountry );
}

// Get countries player owns
vector<string> Player::GetPlayerCountries( )
{
    return countries;
}

// Set newly added player card
void Player::SetPlayerCard( Card newcard )
{
    cards.addToHand( newcard );
}

// Get cards player owns
Hand Player::GetPlayerCards( )
{
    return cards;
}

// Increment number of armies using pass by value
void Player::SetPlayerArmy( int newarmies )
{
    parmies = &armies; // parmies points to memory address of armies
    *parmies = armies + newarmies; // add result to particular memory address pointed to by parmies
}

// Get number of armies (and associated country, value pair in future) of player
int Player::GetPlayerArmies( )
{
    return armies;
}

// Set dice rolls data from dice objects
void Player::SetDice( Dice newdice )
{
    diceFacility.push_back( newdice );
}

// Get dice rolls of player
vector<Dice> Player::GetDice( )
{
    return diceFacility;
}

// Display the attributes of the player object
void Player::DisplayAttributes( )
{
    cout << "Player Name: " << playerName << endl;
    // Display countries
    cout << playerName << " currently owns these countries: ";
    // print out a list of countries (object addresses) owned by player
    for ( unsigned int index = 0; index < countriesOwned.size(); index++)
    {
        cout << countriesOwned[index] << ", ";
    }
    cout << endl;
    // Display cards
    cout << playerName << " currentlty owns these cards: " << endl;
    // Display hand of cards of player (object address)
    cout << &cards << endl;
    // Display player's most recent dice roll
    cout << playerName << " rolled these dice results: ";
    // Display a list of player cards on hand
    for (unsigned int index = 0; index < diceFacility.size(); index++)
    {
        cout << &diceFacility[index] << ", ";
    }
    cout << endl;
    // Display player's armies
    cout << playerName << " currently has " << GetPlayerArmies( ) << " armies." << endl;
}

// Reinforce function runs the features of Reinforce mode
void Player::Reinforce( )
{
    cout << "Reinforce mode is active " << endl;
    system("PAUSE");
    cout << "Reinforce mode is complete " << endl;
}

// Attack function runs the features of Attack mode
void Player::Attack( )
{
    cout << "Attack mode is active " << endl;
    system("PAUSE");
    cout << "Attack mode is complete " << endl;
}

// Function to run the features of Fortify mode
void Player::Fortify( )
{
    cout << "Fortify mode is active " << endl;
    system("PAUSE");
    cout << "Fortify mode is complete " << endl;
}
