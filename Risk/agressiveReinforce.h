//
//  agressiveReinforce.hpp
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "reinforceview.h"

//ReinforceController class definition
class AgressiveReinforceController {
private:
    ReinforceView view;
    Player* player;
    GameMap* gameMap;
    
public:
    //ReinforceController constructor including a player and gameMap passed as parameters
    AgressiveReinforceController(Player* player, GameMap* gameMap){
        this->player = player;
        this->gameMap = gameMap;
        view = ReinforceView();
    };
    //start method to indicate the ReinforceController to start the reinforce method of the player
    void start(Country* strongestCountry);
};
