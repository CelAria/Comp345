//
//  RandomStrategy.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-27.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "RandomStrategy.h"
#include "gamemap.h"
#include <vector>
#include "country.h"
#include "RandomAttack.h"
#include "fortifycontroller.h"

using namespace std;

void RandomStrategy :: attack(Player* player, GameMap* gameMap){
    RandomAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
}

void RandomStrategy ::fortify(Player* player, GameMap* gameMap){
    vector<Country*> countries = player->getAllCountries();
    if(countries.size() > 1) {
        FortifyController fortifyController = FortifyController(player, gameMap);
        
        int idx1 = rand() % countries.size();
        int idx2 = rand() % countries.size();
        while(idx2 == idx1) {
            idx2 = rand() % countries.size();
        }
        
        Country* fromCountry = countries[idx1];
        Country* toCountry = countries[idx2];
        
        int amount = rand() % fromCountry->getArmiesCount() + 1;
        
        fortifyController.moveArmies(fromCountry, toCountry, amount);
    }
}

void RandomStrategy :: reinforce(Player* player, GameMap* gameMap) {
    
}

int RandomStrategy :: getType() {
    return 3;
}

