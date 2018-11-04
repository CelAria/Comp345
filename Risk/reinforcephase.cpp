// Team project assignment #2 - Part 4
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
// Description: header file for the deck and hand
// ------------------------------------------------------

#include "reinforcephase.h"
#include "player.h"
#include "continent.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//implementation of the start method of the ReinforceController
void ReinforceController::start()
{
    srand((unsigned)time(0));
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    //number of countries owend by the player
    int numOfCountriesOwned = player->getCountriesCount();
    //number of armies the player recived based on the number of countries owend by the player /3
    //if this number is less then 3 give the player 3 armies
    int numOfArmiesRecieved = (numOfCountriesOwned/3);
    if(numOfArmiesRecieved <= 3)
        numOfArmiesRecieved = 3;

    vector<Country*> allCountries = player->getAllCountries();
    vector<string> continentContorlValue;
    //loops through all the countries the player has
    for(int i = 0; i < allCountries.size(); i++)
    {
        //if the player controls all contries in the continent
        if(player->controlsContinent(allCountries[i]->getContinentName(), gameMap))
        {
            //loop through the vector and determines if there has been any duplications
            for(int j = 0; j < continentContorlValue.size(); j++)
            {
                if(continentContorlValue[j] == allCountries[i]->getContinentName())
                {
                    vector<Country*> allCountries2 = player->getCountriesByContinent(allCountries[i]->getContinentName());
                    //adds the number of countries in the continent controled by the player to the number of armies to distribute
                    numOfArmiesRecieved += allCountries2.size();
                }
            }
            //adds to continentContorlValue vector to avoid duplications
            continentContorlValue.push_back(allCountries[i]->getContinentName());
        }
    }
    
    cout << "Number of armies (before exchange): " << numOfArmiesRecieved << endl;
    cout << "Player" << player->getPlayerId() << " currently has " << player->getCountriesCount() << " countries and holds "
         << player->getCardsCount() << " cards" << endl;
    cout << "Type of cards the player holds:" << endl;
    cout << "Infantry: " << player->getHand()->getNumOfInfantryCards()
    << ", Artillery: " << player->getHand()->getNumOfArtilleryCards()
    << ", Cavalry: " << player->getHand()->getNumOfCavalryCards() << endl;
    cout<<endl;
    
    while(player->getCardsCount() > 5)
    {
        string userInput;
        cout <<"Type of card exchange -> (Enter either 0, 1, 2 or 3): ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput);
    }
    
    cout<<endl;
    cout << "Number of armies (after exchange): " << numOfArmiesRecieved << endl;
    cout << "Player" << player->getPlayerId() << " currently holds " << player->getCardsCount() << " cards" << endl;
    cout<<endl;
    
    cout << "The number of armies placed in each country that player " << player->getPlayerId() << " controls: " << endl;
    //displays the number of armies in each country the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getArmiesCount() << " armies placed in " << allCountries[i]->getName() <<endl;
    }
    
    //calculates the number of armies to give per country
    int numOfArmiesToPlace = (numOfArmiesRecieved/allCountries.size());
    int numOfArmiesLeft = (numOfArmiesRecieved%allCountries.size());
    
    cout << endl;
    cout << "The number of armies to be placed in each country: " << numOfArmiesToPlace << endl;
    cout << "The number of armies left over be placed in a random country: " << numOfArmiesLeft << endl;
    cout << endl;
    
    //loops through all the countries the player has and distributes the number of armies evenly among the countries
    for(int i = 0; i < allCountries.size(); i++)
    {
        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + numOfArmiesToPlace));
    }
    
    int randNum = (rand() % (allCountries.size()-1) + 0);
    gameMap->getCountry(allCountries[randNum]->getName())->setArmiesCount((gameMap->getCountry(allCountries[randNum]->getName())->getArmiesCount()+numOfArmiesLeft));
    
    cout << "The number of armies placed in each country that player " << player->getPlayerId() << " controls: " << endl;
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getArmiesCount() << " armies placed in " << allCountries[i]->getName() <<endl;
    }
    cout << endl;
    cout << "End of reinforce" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    
}
    
    
