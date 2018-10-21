//
//  fortifycontroller.cpp
//  Risk
//
//  Created by Allan Pichardo on 10/19/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "fortifycontroller.h"
#include <vector>

using namespace std;

void FortifyController::start() {
    view.presentFortify();
    
    Country* fromCountry = view.promptUserForOrigin(player->getAllCountries());
    
    vector<Country*> neighbors = fromCountry->getAllNeighbors();
    vector<Country*> eligibleNeighbors;
    for(int i = 0; i < neighbors.size(); ++i) {
        if(neighbors[i]->getOwner() == player->getPlayerId()) {
            eligibleNeighbors.push_back(neighbors[i]);
        }
    }
    
    Country* toCountry = view.promptUserForDestination(eligibleNeighbors);
    
    int amount = view.promptUserForAmountOfArmies(fromCountry);
    
    moveArmies(fromCountry, toCountry, amount);
}

bool FortifyController::moveArmies(Country *fromCountry, Country *toCountry, int amount) {
    if(amount > 0 && amount < fromCountry->getArmiesCount()) {
        fromCountry->setArmiesCount(fromCountry->getArmiesCount() - amount);
        toCountry->setArmiesCount(toCountry->getArmiesCount() + amount);
        return true;
    } else {
        return false;
    }
}
