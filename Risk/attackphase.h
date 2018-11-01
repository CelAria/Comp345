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
    AttackPhase(Player* player, GameMap *gameMap);
    AttackPhase(Player* player);
    void attackLoop();
    void moveArmy();
    void compare(int attackDice, int defendDice);
    void countrySelect(vector<Country*> countries);
    void enemyNeighbour(Country* attackingCountry);

    
private:
  
    int armies;
    int playerID;
    int attackArmySize;
    int defendArmySize;
    Player* player;
    GameMap* gameMap;
    Country* country;
    char attacking;
    bool attackDiceLoop;
    bool defendDiceLoop;
    int winAttackCounter =0;
    int winDefenseCounter =0;
    int diceAmountAttack =0;
    int diceAmountDefend =0;
    int moveArmies =0;
    
    
    
};
