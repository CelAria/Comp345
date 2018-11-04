//
//  reinforcephase.cpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-04.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "reinforcephase.h"
#include "player.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void ReinforceController::start()
{
    int numOfCountriesOwned = this->player->getCountriesCount();
    int numOfArmiesRecieved = (numOfCountriesOwned/3);
    if(numOfArmiesRecieved <= 3)
        numOfArmiesRecieved = 3;
    
    cout << "Num of Armies (before exchange): " << numOfArmiesRecieved << endl;
    cout << "Player currently has " << player->getCountriesCount() << " countries" << endl;
    cout << "Player currently has " << player->getCardsCount() << " cards" << endl;
    cout << "Artillery: " << player->getHand().getNumOfArtilleryCards()
    << " Cavalry: " << player->getHand().getNumOfCavalryCards()
    << " Infantry: " << player->getHand().getNumOfInfantryCards() << endl;
    
    while(player->getCardsCount() > 5){
        string userInput;
        cout <<"Type of card exchange: ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand().exchange(userInput);
        cout << player->getHand().getTotalCardsInHand() << endl;
    }
    cout << "Num of Armies (after exchange): " << numOfArmiesRecieved << endl;
    
    cout <<""<< endl;
    
    cout << "New card count is: " << player->getCardsCount() << endl;
    cout << "Artillery: " << player->getHand().getNumOfArtilleryCards()
    << " Cavalry: " << player->getHand().getNumOfCavalryCards()
    << " Infantry: " << player->getHand().getNumOfInfantryCards() << endl << endl;
    
    vector<Country*> allCountries = player->getAllCountries();
    int numOfArmiesToPlace = (numOfArmiesRecieved/allCountries.size());
    int numOfArmiesLeft = (numOfArmiesRecieved%allCountries.size());
    
    for(int i = 0; i < allCountries.size(); i++) {
        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount()+numOfArmiesToPlace));
    }
    gameMap->getCountry("Costa Rica")->setArmiesCount((gameMap->getCountry("Costa Rica")->getArmiesCount()+numOfArmiesLeft));
    
    for(int i = 0; i < allCountries.size(); i++) {
        cout << allCountries[i]->getName() << ", " << allCountries[i]->getArmiesCount() << endl;
    }
    
}
    
    
