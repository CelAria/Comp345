//
//  BenevolentStrategy.cpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "BenevolentStrategy.h"
#include "passiveAttack.h"
#include "gamemap.h"

void BenevolentStrategy::attack(Player *player, GameMap *gameMap) {
    PassiveAttack playerAttack(player,gameMap);
    playerAttack.attackLoop();
}

void BenevolentStrategy::fortify(Player *player, GameMap *gameMap) {
    
}

void BenevolentStrategy::reinforce(Player *player, GameMap *gameMap) {
    
}

int BenevolentStrategy::getType() {
    return 2;
}

