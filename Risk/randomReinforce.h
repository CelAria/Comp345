//
//  randomReinforce.hpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-29.
//  Copyright © 2018 comp345. All rights reserved.
//

// Team project assignment #3
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
//
// ------------------------------------------------------
#pragma once

#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "reinforceview.h"

//ReinforceController class definition
class RandomReinforceController {
private:
    ReinforceView view;
    Player* player;
    GameMap* gameMap;
    
public:
    //ReinforceController constructor including a player and gameMap passed as parameters
    RandomReinforceController(Player* player, GameMap* gameMap){
        this->player = player;
        this->gameMap = gameMap;
        view = ReinforceView();
    };
    //start method to indicate the ReinforceController to start the reinforce method of the player
    void start();
};
