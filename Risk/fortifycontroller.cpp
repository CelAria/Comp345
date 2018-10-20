//
//  fortifycontroller.cpp
//  Risk
//
//  Created by Allan Pichardo on 10/19/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "fortifycontroller.h"

void FortifyController::doFortify(Player *player, GameMap *gameMap) {
    
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
