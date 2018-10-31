//
//  attackphase.h
//  Risk
//
//  Created by Matthew Salaciak on 2018-10-24.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once
#include "player.h"
#include "gamemap.h"
#include "country.h"
#include <iostream>
using namespace std;

class AttackPhase
{

    
public:
    AttackPhase(Player* player,GameMap *gameMap);
    void attackLoop();
    void moveArmy();
    void compare(int attackDice, int defendDice);

    
private:
  
    int armies;
    int playerID;
    int attackArmySize;
    int defendArmySize;
    int diceAmountAttack;
    int diceAmountDefend;
    Player* player;
    GameMap* gameMap;
    Country* country;
    char attacking;
    bool attackDiceLoop;
    bool defendDiceLoop;
    
    
    
    
};
