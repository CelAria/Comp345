//
//  passiveAttack.hpp
//  Risk
//
//  Created by Matthew Salaciak 29644490
//  ASSIGNMENT #3
//  Copyright © 2018 comp345. All rights reserved.
// passive strategy

#pragma once
#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "attackview.h"
#include <iostream>
using namespace std;

class PassiveAttack
{
    
    //AttackPhase class definition
public:
    PassiveAttack(Player* player, GameMap *gameMap);
    PassiveAttack(Player* player);
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
    
    
    
};
