// ASSIGNMENT 1#
//  Dice.h
//  This file is the header of Dice
//
//  Created by Matthew Salaciak 29644490
//  Copyright © 2018 comp345. All rights reserved.
//


#pragma once
#include <vector>
using namespace std;

class Dice
	
{
	
	
public:
//    methods to roll, store, save and calculate dice stats
//
    Dice(int playerNumber);

	int rollDice(int amountOfDice);

	void storeDice(int diceResult);

	void diceStats();

	int getDiceValue();

	void diceContainerValues();

	int getPlayerNumber();
	
	

	

	



	//variables needed for dice class
private:
	
	int playerNumber;
	int numbOfDice;
	int diceValue;
	int containerValue;
	vector<int> diceContainer;

};
