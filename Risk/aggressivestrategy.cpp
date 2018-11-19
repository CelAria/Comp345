//
//  aggressivestrategy.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/15/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "aggressivestrategy.h"
#include "agressiveAttack.h"
#include "gamemap.h"
#include "fortifycontroller.h"
#include <vector>
#include "country.h"
#include "agressiveReinforce.h"

void AggressiveStrategy::attack(Player *player, GameMap *gameMap) {
    AgressiveAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
}

void AggressiveStrategy::fortify(Player *player, GameMap *gameMap) {
    FortifyController fortifyController;
    
    vector<Country*> countries = player->getAllCountries();
    
    Country* strongestCountry = countries[0];
    for(int i = 0; i < countries.size(); ++i) {
        if(countries[i]->getArmiesCount() > strongestCountry->getArmiesCount()) {
            strongestCountry = countries[i];
        }
    }
    
    cout << "Strongest country is:" << endl;
    cout << "\t" << strongestCountry->toString() << endl << endl;
    
    for(int i = 0; i < countries.size(); ++i) {
        if(countries[i] != strongestCountry && countries[i]->getArmiesCount() > 1) {
            int amount = countries[i]->getArmiesCount() - 1;
            cout << "Moving " << amount << " armies from " << countries[i]->getName() << " to " << strongestCountry->getName() << endl;
            fortifyController.moveArmies(countries[i], strongestCountry, amount);
        }
    }
}

void AggressiveStrategy::reinforce(Player *player, GameMap *gameMap) {
    vector<Country*> countries = player->getAllCountries();
    
    Country* strongestCountry = countries[0];
    for(int i = 0; i < countries.size(); ++i) {
        if(countries[i]->getArmiesCount() > strongestCountry->getArmiesCount()) {
            strongestCountry = countries[i];
        }
    }
    AgressiveReinforceController reinforceController = AgressiveReinforceController(player, gameMap);
    reinforceController.start(strongestCountry);
}

int AggressiveStrategy::getType() {
    return 1;
}
