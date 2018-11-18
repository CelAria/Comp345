//
//  HumanPlayerStrategy.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/14/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "HumanPlayerStrategy.h"
#include "gamemap.h"
#include "reinforcephase.h"
#include "attackphase.h"
#include "fortifycontroller.h"

class Player;

void HumanPlayerStrategy::reinforce(Player *player, GameMap *gameMap) {
        ReinforceController reinforceController = ReinforceController(player, gameMap);
        reinforceController.start();
}

void HumanPlayerStrategy::attack(Player *player, GameMap *gameMap) {
        AttackPhase playerAttack(player,gameMap);
        playerAttack.attackLoop();
}

void HumanPlayerStrategy::fortify(Player *player, GameMap *gameMap) {
        FortifyController fortifyController = FortifyController(player, gameMap);
        fortifyController.start();
}

int HumanPlayerStrategy::getType() {
    return 0;
}
