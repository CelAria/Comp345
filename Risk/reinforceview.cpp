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

void ReinforceView::placeArmiesRandomly(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player){
//    //calculates the number of armies to give per country
//    int numOfArmiesToPlace = (numOfArmiesRecieved/allCountries.size());
//    int numOfArmiesLeft = (numOfArmiesRecieved%allCountries.size());
//
//    cout << endl;
//    cout << "The number of armies to be placed  country: " << numOfArmiesToPlace << endl;
//    cout << "The number of armies left over be placed in a random country: " << numOfArmiesLeft << endl;
//    cout << endl;
    
//    //loops through all the countries the player has and distributes the number of armies evenly among the countries
//    for(int i = 0; i < allCountries.size(); i++)
//    {
//        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + numOfArmiesToPlace));
//    }
//
//    int randNum = (rand() % (allCountries.size()-1) + 0);
//    gameMap->getCountry(allCountries[randNum]->getName())->setArmiesCount((gameMap->getCountry(allCountries[randNum]->getName())->getArmiesCount()+numOfArmiesLeft));
    int numOfArmiesToPlace = numOfArmiesRecieved;
     cout << endl;
     cout << "The number of armies to be placed: " << numOfArmiesToPlace << endl;
    
    do{
        for(int i = 0; i < allCountries.size(); i++)
        {
            int userInput;
            cout << "How many armies do you want to placed in " << allCountries[i]->getName() << "? -> ";
            //do error validation
            cin >> userInput;
            
            if(userInput > numOfArmiesToPlace){
                cout << "Input entered is greater than the number of armies left to place" << endl;
            }else{
                numOfArmiesToPlace -= userInput;
                gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() + userInput));
            }
            if(numOfArmiesToPlace == 0){
                break;
            }
        }
    }while(numOfArmiesToPlace > 0);
     cout << endl;
}



