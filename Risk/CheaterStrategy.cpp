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
#include "cheaterReinforce.h"
#include <iostream>

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
                if(neighbors[j]->getOwner()->getPlayerId() != player->getPlayerId()) {
                    cout << "Doubling armies on " << countries[i]->getName() << "\n";
                    countries[i]->setArmiesCount(countries[i]->getArmiesCount() * 2);
                    break;
                }
            }
        }
    } else {
        cout << "Can't fortify\n";
    }
}

void CheaterStrategy :: reinforce(Player* player, GameMap* gameMap) {
    CheaterReinforceController reinforceController = CheaterReinforceController(player, gameMap);
    reinforceController.start();
}

int CheaterStrategy :: getType() {
    return 4;
}
