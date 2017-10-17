//
//  Driver3.cpp
//  Dice
//  Group 8
//
//  Created by Jordan Stern on 2017-09-25.
//

#include <iostream>
#include "Dice.h"
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(0)); // for random number generation
    
    //    Creating 2 dice objects
    Dice* dice1 = new Dice();
    Dice* dice2 = new Dice();

    //    Showing container returns the right number of values:
    cout << "For Dice #1:" << endl;
    int numberOfDice = 3;
    vector<int> roll_1 = dice1->roll_dice(numberOfDice); // returns vector of dice
    cout << "Number of Dice: "<< roll_1.size() << endl; // prints number of dice
    for (int i = 0; i < roll_1.size(); i++) { // prints each die value
        cout << "Die " << i+1 << ": " << roll_1[i] << endl;
    }
    
    //    Simulation of many rolls.
    cout << "\nFor Dice #2:" << endl;
    for (int i=0; i<1000; i++) {
        vector<int> roll_2 = dice2->roll_dice(3);
        int count = 0; // reset increment to 0 after every roll
        while (count < roll_2.size()) { // iterates over each die in the roll
            if (roll_2[count] > 6 || roll_2[count] < 1) { //  ensures there are no rolls outside of 1-6 range
                cout << "ERROR die value outside of 1-6 range." << endl;
            }
            count++;
        }
    }
    
    // Prints out percentages of each value rolled by the player's dice
    dice2->printFrequency();
    delete dice1;
    delete dice2;
    return 0;
}
