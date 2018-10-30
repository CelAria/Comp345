// ASSIGNMENT 1#
//  Dice.cpp
//  This file contains all the implementation of the Dice Class
//
//  Created by Matthew Salaciak 29644490
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<random>
#include <map>
#include <array>
#include <algorithm>
using namespace std;
#include "Dice.h"



//Constructor that takes the player's id
//creates a vector called diceContainer to store dice rolls
//seeds the random generator with the computers system's time.
Dice::Dice(int player)
{
    playerNumber = player;
	vector<int> diceContainer1;
   
   

    srand((unsigned)time(0));
}

// roll dice function, takes the amount of dice you want to roll
// diceValue is calcuated by random number % 6 +1 to make sure values stay between 1-6

void Dice ::rollDice(int amountOfDice)
{
    
	if (amountOfDice == 1) 
	{
        diceRollsAttack[0] = (rand() % 6 + 1);
        
        storeDice(diceRollsAttack[0]);
        
	}
	else if (amountOfDice == 2) 
	{
        diceRollsAttack[0]=  (rand() % 6 + 1);
        diceRollsAttack[1]=  (rand() % 6 + 1);
        
       
        
        storeDice(diceRollsAttack[0]);
        storeDice(diceRollsAttack[1]);
	}
	else if (amountOfDice == 3) 
	{
        diceRollsAttack[0]=  (rand() % 6 + 1);
        diceRollsAttack[1]=  (rand() % 6 + 1);
        diceRollsAttack[2]=  (rand() % 6 + 1);
   
       
		storeDice(diceRollsAttack[0]);
        storeDice(diceRollsAttack[1]);
        storeDice(diceRollsAttack[2]);
	}
    
    sort(diceRollsAttack.rbegin(), diceRollsAttack.rend());
  
	
}


void Dice ::defendRollDice(int amountOfDice)
{
    
    if (amountOfDice == 1)
    {
        diceRollsDefend[0] = (rand() % 6 + 1);
        
        storeDice(diceRollsDefend[0]);
        
    }
    else if (amountOfDice == 2)
    {
        diceRollsDefend[0]=  (rand() % 6 + 1);
        diceRollsDefend[1]=  (rand() % 6 + 1);
        
        
        
        storeDice(diceRollsDefend[0]);
        storeDice(diceRollsDefend[1]);
    }
    
    
    sort(diceRollsDefend.rbegin(), diceRollsDefend.rend());
    
    
}

// Getter method - returns the diceValue

void Dice:: getDiceValuesAttack(int amountOfDice)
{
    if(amountOfDice == 1)
    {
        cout << diceRollsAttack[0] <<" " << endl;
        
    }
    else if(amountOfDice == 2)
    {
        cout << diceRollsAttack[0] << " " << diceRollsAttack[1] << endl;
    }
   else  if(amountOfDice == 3)
    {
      cout << diceRollsAttack[0] << " " << diceRollsAttack[1] << " " << diceRollsAttack[2] << endl;
    }
    
    
    
}

void Dice:: getDiceValuesDefend(int amountOfDice)
{
    if(amountOfDice == 1)
    {
        cout << diceRollsDefend[0] <<" " << endl;
        
    }
    else if(amountOfDice == 2)
    {
        cout << diceRollsDefend[0] << " " << diceRollsDefend[1] << endl;
    }
   

    
}


//Stores dice value in a vector
void Dice::storeDice(int diceValue)
{
	diceContainer.push_back(diceValue);
}

//calculates the roll percentage and number of rolls for the given player
// number of rolls is vector size
// to calculate the percentage, a map is created called diceCount that takes the vector diceContainer
// and calculates the percentage based on how many times that key has appeared divided by the vector size.

void Dice::diceStats()
{
	cout << "Dice roll percentages for player " << playerNumber  << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "total number of rolls " << diceContainer.size() << "\n" << endl;

	map<int, int> diceCount;

	for (int i = 0; i < diceContainer.size(); i++)
	{
		diceCount[diceContainer[i]]++;
	}

	for (auto const &x : diceCount)
	{
		double first = x.first;
		double repeat = x.second;
		cout << "The number " << first << " appears " << (repeat/ diceContainer.size())*100 << " % \n" << endl;

	}
	
}

// prints all the dice roll values that the player has rolled during the game
void Dice::diceContainerValues()
{
	cout << "Dice container values for player "<<playerNumber  << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (int i = 0; i < diceContainer.size(); i++) 
	{
		cout << diceContainer[i] << "\n" <<endl;
	}


}
// returns playerNumber
int Dice::getPlayerNumber() 
{
	return playerNumber;
}







