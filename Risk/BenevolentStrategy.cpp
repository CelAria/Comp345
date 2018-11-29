//
//  BenevolentStrategy.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "BenevolentStrategy.h"
#include "fortifycontroller.h"
#include "country.h"
#include "passiveAttack.h"
#include "gamemap.h"
#include "passiveReinforce.h"


void BenevolentStrategy::attack(Player *player, GameMap *gameMap) {
    PassiveAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
}

void BenevolentStrategy::fortify(Player *player, GameMap *gameMap) {
    FortifyController fortifyController;
    
    vector<Country*> countries = player->getAllCountries();
    
    if(countries.size() > 0) {
        Country* weakestCountry = countries[0];
        for(int i = 0; i < countries.size(); ++i) {
            if(countries[i]->getArmiesCount() < weakestCountry->getArmiesCount()) {
                weakestCountry = countries[i];
            }
        }
        
        cout << "Weakest country is:" << endl;
        cout << "\t" << weakestCountry->toString() << endl << endl;
        
        for(int i = 0; i < countries.size(); ++i) {
            if(countries[i] != weakestCountry && countries[i]->getArmiesCount() > 1) {
                int amount = countries[i]->getArmiesCount() - 1;
                cout << "Moving " << amount << " armies from " << countries[i]->getName() << " to " << weakestCountry->getName() << endl;
                fortifyController.moveArmies(countries[i], weakestCountry, amount);
            }
        }
    }
}

void BenevolentStrategy::reinforce(Player *player, GameMap *gameMap) {
    vector<Country*> countries = player->getAllCountries();
    
    if(countries.size() > 0) {
        Country* weakestCountry = countries[0];
        for(int i = 0; i < countries.size(); ++i) {
            if(countries[i]->getArmiesCount() < weakestCountry->getArmiesCount()) {
                weakestCountry = countries[i];
            }
        }
        PassiveReinforceController reinforceController = PassiveReinforceController(player, gameMap);
        reinforceController.start(weakestCountry);
    }
}

int BenevolentStrategy::getType() {
    return 2;
}

