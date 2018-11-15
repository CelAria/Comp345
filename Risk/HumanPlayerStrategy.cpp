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

void HumanPlayerStrategy::Strategy::reinforce(Player *player, GameMap *gameMap) {
        ReinforceController reinforceController = ReinforceController(player, gameMap);
        reinforceController.start();
}

void HumanPlayerStrategy::Strategy::attack(Player *player, GameMap *gameMap) {
        AttackPhase playerAttack(player,gameMap);
        playerAttack.attackLoop();
}

void HumanPlayerStrategy::Strategy::fortify(Player *player, GameMap *gameMap) {
        FortifyController fortifyController = FortifyController(player, gameMap);
        fortifyController.start();
}

int HumanPlayerStrategy::Strategy::getType() {
    return 0;
}
