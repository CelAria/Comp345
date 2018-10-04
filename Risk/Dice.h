#pragma once
#include <vector>
using namespace std;

class Dice
	
{
	
	
public:
	Dice(); // default constructor
    Dice(int playerNumber): playerNumber(playerNumber) {
        
    }

	int rollDice(int amountOfDice);

	void storeDice(int diceResult);

	void diceStats();

	int getDiceValue();

	void diceContainerValues();

	int getPlayerNumber();
	
	

	

	



	
private:
	
	int playerNumber;
	int numbOfDice;
	int diceValue;
//    int amountOfDice;
	int containerValue;
	vector<int> diceContainer;

};
