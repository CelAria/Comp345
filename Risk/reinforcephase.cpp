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
    
    //display cout for reinforce
    view.presentReinforce();
    
    vector<Country*> allCountries = player->getAllCountries();
    int numOfArmiesRecieved = view.getNumOfArmiesToPlace(gameMap, player);
    
    //display some stats of the player and the cards he or she holds
    view.displayStats(numOfArmiesRecieved, player);
    
    //exchange method to exchange cards the player holds
    view.userInputCardExchange(numOfArmiesRecieved, player);
    
    //display some stats of the player and the cards he or she holds after the card exchange
    view.displayStats(numOfArmiesRecieved, player);
    
    //displays the countries the player owns
    view.displayContriesPlayerOwns(allCountries, player);
    
    //asks the user to place which countries get reinforcements 
    view.placeArmiesHuman(gameMap, allCountries, numOfArmiesRecieved , player);

}
    
    
