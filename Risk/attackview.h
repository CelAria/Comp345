//
//  attackview.hpp
//  Risk
//
//  Created by Matthew Salaciak 29644490
//  ASSIGNMENT #3
//  Copyright © 2018 comp345. All rights reserved.
// attackView is a view for the attackphase for human strategy
//

#pragma once


#include "player.h"
#include "gamemap.h"
#include "country.h"
#include <iostream>
using namespace std;

class AttackView
{

    //functions
public:
    AttackView();
    bool startAttackPhase();
    bool keepAttacking();
    void playerCountryList(vector<Country*> allCountries);
    int pickAttackingCountry();
    int pickDice();
    int moveArmies();
    void enemyCountryList(vector<Country*> enemies, Player* player);
    
    
    
    //variables
private:
    bool attackPhaseInput;
    string attacking;
    char input;
    bool start;
    Country* countryList;
    
    
};
