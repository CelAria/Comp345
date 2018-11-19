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

int ReinforceView::getNumOfArmiesToPlace(GameMap* gameMap, Player *player){
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
    return numOfArmiesRecieved;
}

void ReinforceView::displayStats(int numOfArmiesRecieved, Player *player){
    cout << "Number of armies: " << numOfArmiesRecieved << endl;
    cout << "Player" << player->getPlayerId() << " currently controls " << player->getCountriesCount() << " countries and holds "
    << player->getCardsCount() << " cards" << endl;
    cout << "Type of cards the player holds:" << endl;
    cout << "Infantry: " << player->getHand()->getNumOfInfantryCards()
    << ", Artillery: " << player->getHand()->getNumOfArtilleryCards()
    << ", Cavalry: " << player->getHand()->getNumOfCavalryCards() << endl;
}

void ReinforceView::userInputCardExchange(int numOfArmiesRecieved, Player *player){
    while(player->getCardsCount() > 5)
    {
        string userInput;
        cout << endl;
        cout << "Card exchange (Enter either 0, 1, 2 or 3) " <<endl;
        cout << "\t• 0 = Exchange 3 cards of the same type" << endl;
        cout << "\t• 1 = Exchange 3 Infantry cards" << endl;
        cout << "\t• 2 = Exchange 3 Artillery cards" << endl;
        cout << "\t• 3 = Exchange 3 Cavalry cards" << endl;
        cout <<"Type of card exchange -> ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput);
    }
    if((player->getCardsCount() > 2)){
        string userInput;
        cout << "Do you want to do a card exchange? y/n -> ";
        getline (cin, userInput);
        if(userInput == "y"){
            string userInput2;
            cout << endl;
            cout << "Card exchange (Enter either 0, 1, 2 or 3) " <<endl;
            cout << "\t• 0 = Exchange 3 cards of the same type" << endl;
            cout << "\t• 1 = Exchange 3 Infantry cards" << endl;
            cout << "\t• 2 = Exchange 3 Artillery cards" << endl;
            cout << "\t• 3 = Exchange 3 Cavalry cards" << endl;
            cout <<"Type of card exchange -> ";
            getline (cin, userInput2);
            numOfArmiesRecieved = numOfArmiesRecieved + player->getHand()->exchange(userInput2);
        }
    }
    cout << endl;
}

void ReinforceView::displayContriesPlayerOwns(vector<Country*> allCountries, Player *player){
    cout << "The number of armies placed in each country that player " << player->getPlayerId() << " controls: " << endl;
    //displays the number of armies in each country the player controls
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getArmiesCount() << " armies placed in " << allCountries[i]->getName() <<endl;
    }
}

bool ReinforceView::placeArmiesHuman(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player){
    int numOfArmiesToPlace = numOfArmiesRecieved;
     cout << endl;
     cout << "The number of armies to be placed: " << numOfArmiesToPlace << endl;
    
    do{
        for(int i = 0; i < allCountries.size(); i++)
        {
            int userInput2;
            cout << "How many armies do you want to placed in " << allCountries[i]->getName() << "? -> ";
            cin >> userInput2;
            
            if(!cin.good()){
                continue;
            }
                if(userInput2 > numOfArmiesToPlace){
                    cout << "Input entered is greater than the number of armies left to place" << endl;
                }else{
                    numOfArmiesToPlace -= userInput2;
                    gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + userInput2));
                }
                if(numOfArmiesToPlace == 0){
                    break;
                }
        }
    }while(numOfArmiesToPlace > 0);
     cout << endl;
     return true;
}



