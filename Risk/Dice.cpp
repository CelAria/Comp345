#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<random>
#include <map>
using namespace std;
#include "Dice.h"



Dice::Dice() 
{
	
	vector<int> diceContainer;


}

int Dice ::rollDice(int amountOfDice)
{
	srand(time(0));
	
	
	if (amountOfDice == 1) 
	{

		diceValue = (rand() % 6 + 1);

	}
	else if (amountOfDice == 2) 
	{
		diceValue = (rand() % 6 + 1) + (rand() % 6 + 1);
	
	}

	else if (amountOfDice == 3) 
	{
		diceValue = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
		
	}


	
    return diceValue;
	
}

int Dice::getDiceValue() 
{

	return diceValue;
}



void Dice::storeDice(int diceValue)
{
	

	diceContainer.push_back(diceValue);

}

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

void Dice::diceContainerValues()
{
	cout << "Dice container values for player "<<playerNumber  << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (int i = 0; i < diceContainer.size(); i++) 
	{
		cout << diceContainer[i] << "\n" <<endl;
	}


}

int Dice::getPlayerNumber() 
{
	return playerNumber;
}







