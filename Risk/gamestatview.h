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

class GameStatView: public Observer{
    
private:
    State state;
    MainGame* maingame;
    map<string ,int> worlddominationmap;
    void clearScreen();
    bool testWinner(Player* player);
    vector<Player*> players;
public:
    GameStatView(vector<Player*> playerlist){players=playerlist;};
    void print();
    void update(State& state);
    map<string ,int> worlddominationview();
};

