// ASSIGNMENT 1#
//  Dice.h
//  This file is the header of Dice
//
//  Created by Matthew Salaciak 29644490
//  Copyright © 2018 comp345. All rights reserved.
//


#pragma once
#include <vector>
#include <array>
using namespace std;

class Dice
	
{
	
	
public:
//    methods to roll, store, save and calculate dice stats
//
    Dice(int playerNumber);

	void rollDice(int amountOfDice);
    
    void defendRollDice(int amountofDice);

	void storeDice(int diceResult);

	void diceStats();

	void diceContainerValues();

	int getPlayerNumber();
    
    void getDiceValuesAttack(int amountOfDice);
    void getDiceValuesDefend(int amountOfDice);
    
    
    inline int getAttackDice1() {return diceRollsAttack[0];}
    inline int getAttackDice2() {return diceRollsAttack[1];}
    inline int getAttackDice3() {return diceRollsAttack[2];}
    
    inline int getDefenseDice1() {return diceRollsDefend[0];}
    inline int getDefenseDice2() {return diceRollsDefend[1];}
    
   
    
    
    
    
	//variables needed for dice class
private:
	
	int playerNumber;
	int numbOfDice;
    int containerValue;
	vector<int> diceContainer;
    array<int,3> diceRollsAttack;
    array<int,2> diceRollsDefend;
   
    

};
