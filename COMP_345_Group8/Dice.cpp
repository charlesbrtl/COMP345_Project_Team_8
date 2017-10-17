//
//  Dice.cpp
//  
//  Group 8
//  Created by Jordan Stern on 2017-09-23.
//

#include "Dice.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int frequency[6]; // Frequency of every value rolled by the dice

Dice:: Dice() {
}
Dice::~ Dice() {
}

//    Verify numberOfDice is either 1, 2, or 3
vector<int> Dice::roll_dice(int numberOfDice) {
    if (numberOfDice < 1) {
        numberOfDice = 1;
    } else if (numberOfDice > 3) {
        numberOfDice = 3;
    }
    
//    Creating vector of dice
    vector<int> dice_attack;
    
//    Assigning a random value to each die (between 1-6)
    int random = 0;
    for (int i = 0; i < numberOfDice; i++) {
        random = (rand() % 6 + 1);
        dice_attack.push_back(random);
        diceHistory(random); // adds value of die to the rolled history
    }
    
//   Sorting the dice (highest to lowest)
    sort(dice_attack.rbegin(), dice_attack.rend());   // note: reverse iterator
    
    return dice_attack; // vector correctly sized, with dice values
}

void Dice::diceHistory(int value) {
    frequency[value-1] = frequency[value-1] + 1; //Add face of die to the frequency array
}

void Dice::printFrequency() {
    double sumOfAllRolls = 0;
    for (int i = 0; i < 6; i++) { // Sums all rolls
        sumOfAllRolls += frequency[i];
    }
    for (int i = 0; i < 6; i++) { // Prints percentage of each value rolled
        cout << "Percentage of " << i+1 << ": " << 100*(frequency[i]/sumOfAllRolls) << "%" << endl;
    }
}
