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

void AggressiveStrategy::attack(Player *player, GameMap *gameMap) {
    AgressiveAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
}

void AggressiveStrategy::fortify(Player *player, GameMap *gameMap) {
    
}

void AggressiveStrategy::reinforce(Player *player, GameMap *gameMap) {
    
}

int AggressiveStrategy::getType() {
    return 1;
}
