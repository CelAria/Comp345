//
//  RandomStrategy.hpp
//  Risk
//
//  Created by Matthew Salaciak on 2018-11-27.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "strategy.h"

class RandomStrategy: public Strategy {
    void attack(Player* player, GameMap* gameMap);
    void fortify(Player* player, GameMap* gameMap);
    void reinforce(Player* player, GameMap* gameMap);
    int getType();
};
