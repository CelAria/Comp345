//
//  gamestatview.hpp
//  Risk
//
//  Created by Celeste Pimm on 2018-11-11.
//  Copyright © 2018 comp345. All rights reserved.
//
/* if a player WINS a new country, update the "world domination map. ELSE, if phase changes, print the map again
 If there is a STATE change on "moveArmy" then map needs to be updated. */
#pragma once

#include "maingame.h"
#include <string>
#include <map>

class GameStatView{
    
private:
    map<string ,int> worlddominationmap;
    void clearScreen();
    
public:
    void print(MainGame* main);
    void update(State& state);
    map<string ,int> worlddominationview(MainGame* main);
};
