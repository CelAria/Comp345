//
//  CheaterStrategy.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-27.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "CheaterStrategy.h"
#include "gamemap.h"
#include <vector>
#include "country.h"
#include "CheaterAttack.h"
#include "fortifycontroller.h"

using namespace std;

void CheaterStrategy :: attack(Player* player, GameMap* gameMap){
    CheaterAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
    
}

void CheaterStrategy ::fortify(Player* player, GameMap* gameMap){
    vector<Country*> countries = player->getAllCountries();
    if(countries.size() > 0) {
        for(int i = 0; i < countries.size(); ++i) {
            vector<Country*> neighbors = countries[i]->getAllNeighbors();
            for(int j = 0; j < neighbors.size(); j++) {
                if(neighbors[i]->getOwner()->getPlayerId() != player->getPlayerId()) {
                    countries[i]->setArmiesCount(countries[i]->getArmiesCount() * 2);
                    break;
                }
            }
        }
    }
}

void CheaterStrategy :: reinforce(Player* player, GameMap* gameMap) {
    
}

int CheaterStrategy :: getType() {
    return 4;
}
