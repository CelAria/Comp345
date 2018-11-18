//
//  reinforceview.cpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-15.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "reinforceview.h"

#include <iostream>

using namespace std;

void ReinforceView::presentReinforce(){
     cout << "Reinforce phase:" << endl << endl;
}

void ReinforceView::displayStats(int numOfArmiesRecieved, Player *player){
    cout << "Number of armies: " << numOfArmiesRecieved << endl;
    cout << "Player" << player->getPlayerId() << " currently controls " << player->getCountriesCount() << " countries and holds "
    << player->getCardsCount() << " cards" << endl;
    cout << "Type of cards the player holds:" << endl;
    cout << "Infantry: " << player->getHand()->getNumOfInfantryCards()
    << ", Artillery: " << player->getHand()->getNumOfArtilleryCards()
    << ", Cavalry: " << player->getHand()->getNumOfCavalryCards() << endl;
    cout<<endl;
}

void ReinforceView::userInputCardExchange(int numOfArmiesRecieved, Player *player){
    while(player->getCardsCount() > 5)
    {
        string userInput;
        cout <<"Type of card exchange -> (Enter either 0, 1, 2 or 3): ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput);
    }
}

void ReinforceView::displayContriesPlayerOwns(vector<Country*> allCountries, Player *player){
    cout << "The number of armies placed in each country that player " << player->getPlayerId() << " controls: " << endl;
    //displays the number of armies in each country the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getArmiesCount() << " armies placed in " << allCountries[i]->getName() <<endl;
    }
}

void ReinforceView::placeArmiesRandomly(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player){
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
}



