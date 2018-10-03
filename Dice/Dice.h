#pragma once
#include <vector>
class Dice
	
{
	
	
public:
	Dice(); // default constructor

	void rollDice();

	void storeDice(int diceResult);

	void diceStats();

	int getDiceValue();

	void diceContainerValues();

	int getPlayerNumber();
	
	

	

	



	
private:
	
	int playerNumber;
	int numbOfDice;
	int diceValue;
	int amountOfDice;
	int containerValue;
	vector<int> diceContainer;

};