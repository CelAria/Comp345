//
//  attackview.hpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-08.
//  Copyright © 2018 comp345. All rights reserved.
//
#pragma once


#include "player.h"
#include "gamemap.h"
#include "country.h"
#include <iostream>
using namespace std;

class AttackView
{

    
public:
    AttackView();
    bool startAttackPhase();
    bool keepAttacking();
    void playerCountryList(vector<Country*> allCountries);
    int pickAttackingCountry();
    int pickDice();
    int moveArmies();
    void enemyCountryList(vector<Country*> enemies, Player* player);
    
    
    
    
private:
    bool attackPhaseInput;
    string attacking;
    char input;
    bool start;
    Country* countryList;
    
    
};
