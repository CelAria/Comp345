//
//  randomReinforce.cpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-29.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "randomReinforce.h"
#include "player.h"
#include "continent.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//implementation of the start method of the ReinforceController
void RandomReinforceController::start()
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
    int numOfArmiesToPlace = (numOfArmiesRecieved/allCountries.size());
    int numOfArmiesLeft = (numOfArmiesRecieved%allCountries.size());
    
    //loops through all the countries the player has and distributes the number of armies evenly among the countries
    for(int i = 0; i < allCountries.size(); i++)
        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + numOfArmiesToPlace));
    
    
    if(numOfArmiesLeft != 0){
        int randNum = (rand() % (allCountries.size()) + 0);
        cout << "testing------------------------- " << endl;
        gameMap->getCountry(allCountries[randNum]->getName())->setArmiesCount((gameMap->getCountry(allCountries[randNum]->getName())->getArmiesCount()+numOfArmiesLeft));
    }
    view.displayContriesPlayerOwns(allCountries, player);
    
}
