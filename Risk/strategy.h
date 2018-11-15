//
//  strategy.h
//  Risk
//
//  Created by Allan Pichardo on 11/10/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "gamemap.h"

class Player;

class Strategy {
public:
    virtual ~Strategy() {};
    virtual void attack(Player* player, GameMap* gameMap) = 0;
    virtual void fortify(Player* player, GameMap* gameMap) = 0;
    virtual void reinforce(Player* player, GameMap* gameMap) = 0;
    virtual int getType() = 0;
};
