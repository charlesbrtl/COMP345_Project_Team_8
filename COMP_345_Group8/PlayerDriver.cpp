/*
 * COMP345 Advanced Programming with C++
 * Section D
 * Assignment 1
 * Part 4: by Daniel Strychowsky (27364024)
 * Team 8
 */
 #include "Player.h"

// Driver for Player class
int main(int argc, char* argv[])
{
    Card player1card1;
    Dice player1dice1;
    Dice player1dice2;

    Player player1;

    player1.SetPlayerName( );
    player1.DisplayAttributes( );
    player1.SetPlayerArmy( 5 );
    player1.DisplayAttributes( );
    player1.SetPlayerCountry( "Japan" );
    player1.DisplayAttributes( );
    player1.SetPlayerCard( player1card1 );
    player1.DisplayAttributes( );
    player1.SetDice( player1dice1 );
    player1.SetDice( player1dice2 );
    player1.DisplayAttributes( );

    Player player2;

    player2.SetPlayerName( );
    player2.DisplayAttributes( );
    player2.SetPlayerArmy( 4 );
    player2.DisplayAttributes( );
    player2.SetPlayerCountry( "Poland" );
    player2.DisplayAttributes( );

    player1.DisplayAttributes( ); // Displays saved player data
    player2.DisplayAttributes( ); // Displays saved player data

    player1.Reinforce( );
    player1.Attack( );
    player1.Fortify( );

    system("PAUSE");

    return 0;
};
