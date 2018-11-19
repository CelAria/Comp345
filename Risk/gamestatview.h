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

#include "gamemap.h"
#include "observer.h"
#include <string>
#include <map>

class GameStatView: public Observer{
    
private:
    State state;
    GameMap* gameMap;
    map<string ,int> worlddominationmap;
    void clearScreen();
    bool testWinner(Player* player);
    vector<Player*> players;
public:
    GameStatView(GameMap* gameMap, vector<Player*> playerlist){this->gameMap = gameMap; players=playerlist;};
    void print();
    void update(State& state);
    map<string ,int> worlddominationview();
};

