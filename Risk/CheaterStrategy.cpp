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

void CheaterStrategy :: attack(Player* player, GameMap* gameMap){
    CheaterAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
    
}

void CheaterStrategy ::fortify(Player* player, GameMap* gameMap){
    
}
void CheaterStrategy :: reinforce(Player* player, GameMap* gameMap) {
    
}

int CheaterStrategy :: getType() {
    return 4;
}
