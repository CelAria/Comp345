// Team project assignment #3
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
//
// ------------------------------------------------------

#include "agressiveReinforce.h"
#include "player.h"
#include "continent.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//implementation of the start method of the ReinforceController
void AgressiveReinforceController::start(Country* strongestCountry)
{
    if(player->getCountriesCount() == 0){
        cout<<"No more Countries"<<endl;
        return;
    }
    srand((unsigned)time(0));
    
    view.presentReinforce();
    
    vector<Country*> allCountries = player->getAllCountries();
    int numOfArmiesRecieved = view.getNumOfArmiesToPlace(gameMap, player);
    
    view.displayStats(numOfArmiesRecieved, player);
    
    while(player->getCardsCount() > 5)
    {
        string computerInput;
        int randNum = (0 + (rand() % (int)(3 - 0 + 1)));
        if(randNum == 0){
            computerInput = "0";
        }else if(randNum == 1){
            computerInput = "1";
        }else if(randNum == 2){
            computerInput = "2";
        }else if(randNum == 3){
            computerInput = "3";
        }
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(computerInput);
    }
    cout << endl;
    
    view.displayStats(numOfArmiesRecieved, player);
    
    view.displayContriesPlayerOwns(allCountries, player);
    
    gameMap->getCountry(strongestCountry->getName())->setArmiesCount((gameMap->getCountry(strongestCountry->getName())->getArmiesCount() + numOfArmiesRecieved));
    
    view.displayContriesPlayerOwns(allCountries, player);
    
}



