//
//  Dice.hpp
//  
//  Group 8
//  Created by Jordan Stern on 2017-09-23.
//
#ifndef Dice_H
#define Dice_H
#include <vector>
using namespace std;

class Dice {
public:
    int frequency[6] = {}; // frequency of each value rolled by the dice object
    Dice();
    ~Dice();
    vector<int> roll_dice(int numberOfDice);  //function to generate dice roll
    void diceHistory(int value); // Adds value to frequency array
    void printFrequency();
private:
    vector<int> dice_attack;
    double sumOfAllRolls;
};
#endif
