// Team project assignment #3
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
//
// ------------------------------------------------------

#pragma once

#include "player.h"
#include "country.h"
#include "gamemap.h"
#include <vector>

using namespace std;

class ReinforceView {
    
private:
    
public:
    //displays info about the reinforce phase
    void presentReinforce();
    void displayStats(int numOfArmiesRecieved, Player *player);
    void userInputCardExchange(int numOfArmiesRecieved, Player *player);
    void displayContriesPlayerOwns(vector<Country*> allCountries, Player *player);
    //user places armies in their countries
    bool placeArmiesHuman(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player);
    //returns the number of armies to be placed
    int getNumOfArmiesToPlace(GameMap* gameMap, Player *player);
};


