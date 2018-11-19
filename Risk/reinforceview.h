//
//  reinforceview.hpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-15.
//  Copyright © 2018 comp345. All rights reserved.
//
#pragma once

#include "player.h"
#include "country.h"
#include "gamemap.h"

#include <vector>


using namespace std;

class ReinforceView {
    
private:
    
public:
    void presentReinforce();
    void displayStats(int numOfArmiesRecieved, Player *player);
    void userInputCardExchange(int numOfArmiesRecieved, Player *player);
    void displayContriesPlayerOwns(vector<Country*> allCountries, Player *player);
    bool placeArmiesHuman(GameMap* gameMap, vector<Country*> allCountries, int numOfArmiesRecieved, Player *player);
    int getNumOfArmiesToPlace(GameMap* gameMap, Player *player);
};


