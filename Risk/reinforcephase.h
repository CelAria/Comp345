//
//  reinforcephase.h
//  Risk
//
//  Created by Martin-John Hearty on 2018-11-04.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "gamemap.h"
#include "country.h"

class ReinforceController {
private:
    Player* player;
    GameMap* gameMap;
        
public:
    ReinforceController(Player* player, GameMap* gameMap){
        this->player = player;
        this->gameMap = gameMap;
    };
    void start();
};
