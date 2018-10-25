//  ASSIGNMENT 1#
//  main.cpp
//  Dice
//  this main tests all the required functions for the dice class
//  Created by Matthew Salaciak 29644490
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // create two dice objects for player 1 and player 2
    Dice dice1(1);
    Dice dice2(2);
   
    // while loop to ask players how many dice they want to roll
    //if they want to keep rolling
    // and stores each dice value
    char keepGoing ='y';
    while (keepGoing == 'y')
    {
        int amountOfDice = 0;
        cout << "Player "<< dice1.getPlayerNumber() <<" roll " <<" \n";
        cout << "Choose between 1-3 dice, please enter amount of dice: ";
        cin >> amountOfDice;
        dice1.rollDice(amountOfDice);
        
        dice1.getDiceValuesAttack(amountOfDice);
        cout << "\n" << endl;
        cout << "Player " << dice2.getPlayerNumber() << " roll "<< " \n";
        cout << "Choose between 1-3 dice, please enter amount of dice: ";
        cin >> amountOfDice;
        dice2.rollDice(amountOfDice);

        dice2.getDiceValuesAttack(amountOfDice);
        cout << "\n" << endl;

        cout << "do you want to roll again? type y to continue or n to exit \n";
        cin >> keepGoing;
        cout << "\n";
        if (keepGoing == 'n')
        {
            cout << "thanks for rolling! players " << dice1.getPlayerNumber() << " & "  << dice2.getPlayerNumber() << "\n" <<endl;
            break;
        }

    }



    //when done rolling, diceStats and containerValue will print out for both players
    //the percentage of each value rolled, how many rolls occured and all the values rolled.
    
    dice1.diceStats();
    dice1.diceContainerValues();
    dice2.diceStats();
    dice2.diceContainerValues();

    return 0;
}
