#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
#include "dice.h"

int main() {

	Dice dice1;
	Dice dice2;
	


	
	
	char keepGoing ='y';
	while (keepGoing == 'y') 
	{
		cout << "Player "<< dice1.getPlayerNumber() <<" roll " <<" \n";
		dice1.rollDice();
		dice1.storeDice(dice1.getDiceValue());
		cout << "Player " << dice2.getPlayerNumber() << " roll "<< " \n";
		dice2.rollDice();
		dice2.storeDice(dice2.getDiceValue());

		cout << "do you want to roll again? type y to continue or n to exit \n";
		cin >> keepGoing;
		cout << "\n";
		if (keepGoing == 'n') 
		{
			cout << "thanks for rolling! players " << dice1.getPlayerNumber() << " & "  << dice2.getPlayerNumber() << "\n" <<endl;
			break;
		}

	}
	
	


	dice1.diceStats();
	dice1.diceContainerValues();
	dice2.diceStats();
	dice2.diceContainerValues();


	
	
	
	
	








}