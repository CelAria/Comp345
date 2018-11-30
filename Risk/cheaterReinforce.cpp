//
//  cheaterReinforce.cpp
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
    srand((unsigned)time(0));
    
    view.presentReinforce();
    
    vector<Country*> allCountries = player->getAllCountries();

    view.displayContriesPlayerOwns(allCountries, player);
    
    //loops through all the countries the player has and distributes the number of armies evenly among the countries
    for(int I = 0; I < allCountries.size(); I++)
        gameMap->getCountry(allCountries[I]->getName())->setArmiesCount((gameMap->getCountry(allCountries[I]->getName())->getArmiesCount() * 2));
    
    
    view.displayContriesPlayerOwns(allCountries, player);
    
}
