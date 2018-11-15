//
//  HumanPlayerStrategy.hpp
//  Risk
//
//  Created by Allan Pichardo on 11/14/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "strategy.h"

class HumanPlayerStrategy: public Strategy {
    void attack(Player* player, GameMap* gameMap);
    void fortify(Player* player, GameMap* gameMap);
    void reinforce(Player* player, GameMap* gameMap);
    int getType();
};
