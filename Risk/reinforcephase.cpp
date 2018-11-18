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
    
    view.presentReinforce();
    
    //number of countries owend by the player
    int numOfCountriesOwned = player->getCountriesCount();
    //number of armies the player recived based on the number of countries owend by the player /3
    //if this number is less then 3 give the player 3 armies
    int numOfArmiesRecieved = (numOfCountriesOwned/3);
    if(numOfArmiesRecieved <= 3)
        numOfArmiesRecieved = 3;

    vector<Country*> allCountries = player->getAllCountries();
    vector<string> continentControlValue;
    int myCounter = 0;
    //loops through all the countries the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        //if the player controls all contries in the continent
        if(player->controlsContinent(allCountries[i]->getContinentName(), gameMap))
        {
            //add continent to vector continentControlValue to then check if it is only add once
            continentControlValue.push_back(allCountries[i]->getContinentName());
            for(int j = 0; j < continentControlValue.size(); j++)
            {
                if(continentControlValue[j] == allCountries[i]->getContinentName())
                {
                    myCounter++;
                }
            }
            //if a continent appears only once in the continentControlValue vector, then adjust the numOfArmiesRecieved
            if(myCounter == 1)
            {
                vector<Country*> allCountries2 = player->getCountriesByContinent(allCountries[i]->getContinentName());
                //if the player controls all the countries in a continent, then add the number of countries in that continent to the numOfArmiesRecieved
                numOfArmiesRecieved += allCountries2.size();
            }
            myCounter = 0;
        }
    }
    
    view.displayStats(numOfArmiesRecieved, player);
    
    view.userInputCardExchange(numOfArmiesRecieved, player);
    
    view.displayStats(numOfArmiesRecieved, player);
    
    view.displayContriesPlayerOwns(allCountries, player);
    

    //randomly places the player's armies evenly in each of his or her countries
    view.placeArmiesRandomly(gameMap, allCountries, numOfArmiesRecieved , player);

}
    
    
