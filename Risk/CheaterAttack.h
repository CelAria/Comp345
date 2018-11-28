//
//  CheaterAttack.hpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-27.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once
#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "attackview.h"
#include <iostream>

using namespace std;

class CheaterAttack
{
    
    //AttackPhase class definition
public:
    CheaterAttack(Player* player, GameMap *gameMap);
    CheaterAttack(Player* player);
    void attackLoop();
    void moveArmy();
    void compare(int attackDice, int defendDice);
    void countrySelect(vector<Country*> countries);
    void enemyNeighbour(Country* attackingCountry);
    
    
private:
    //AttackPhase variables
    int armies;
    int playerID;
    int attackArmySize;
    int defendArmySize;
    Player* player;
    GameMap* gameMap;
    Country* country;
    AttackView attackView;
    char attacking;
    bool attackDiceLoop;
    bool defendDiceLoop;
    int winAttackCounter =0;
    int winDefenseCounter =0;
    int diceAmountAttack =0;
    int diceAmountDefend =0;
    int moveArmies =0;
    bool start;
    bool continueAttack;
    
    
    
};
