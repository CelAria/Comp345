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
    
    if(fromCountry != NULL) {
        if(fromCountry->getArmiesCount() > 1) {
            vector<Country*> neighbors = fromCountry->getAllNeighbors();
            vector<Country*> eligibleNeighbors;
            for(int i = 0; i < neighbors.size(); ++i) {
                if(neighbors[i]->getOwner() == player->getPlayerId()) {
                    eligibleNeighbors.push_back(neighbors[i]);
                }
            }
            
            if(eligibleNeighbors.size() > 0) {
                Country* toCountry = view.promptUserForDestination(eligibleNeighbors);
                
                if(toCountry != NULL) {
                    int amount = view.promptUserForAmountOfArmies(fromCountry);
                    
                    if(amount > 0) {
                        moveArmies(fromCountry, toCountry, amount);
                    } else {
                        //invalid amount. go back?
                    }
                } else {
                    //bad destination. go back?
                }
            } else {
                string prompt = fromCountry->getName() + " doesn't have any adjacent countries to move armies to. Try again? (y/n)";
                if(view.promptUserYesNo(prompt)) {
                    start();
                }
            }
        } else {
            string prompt = fromCountry->getName() + " doesn't have enough armies. Try again? (y/n)";
            if(view.promptUserYesNo(prompt)) {
                start();
            }
        }
    } else {
        if(!view.promptUserYesNo("Skip the fortify phase? (y/n)")) {
            start();
        }
    }
    
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
