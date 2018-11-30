//
//  cheaterReinforce.cpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-29.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "cheaterReinforce.h"
#include "player.h"
#include "continent.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//implementation of the start method of the ReinforceController
void CheaterReinforceController::start()
{
    if(player->getCountriesCount() == 0){
        cout<<"No more Countries"<<endl;
        return;
    }
    srand((unsigned)time(0));
    
    view.presentReinforce();
    
    vector<Country*> allCountries = player->getAllCountries();

    view.displayContriesPlayerOwns(allCountries, player);
    
    //loops through all the countries the player has and distributes the number of armies evenly among the countries
    for(int i = 0; i < allCountries.size(); i++)
        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount() * 2));
    
    
    view.displayContriesPlayerOwns(allCountries, player);
    
}
