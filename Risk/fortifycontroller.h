//
//  fortifycontroller.hpp
//  Risk
//
//  Created by Allan Pichardo on 10/19/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "gamemap.h"
#include "country.h"

class FortifyController {
    
public:
    void doFortify(Player* player, GameMap* gameMap);
    bool moveArmies(Country* fromCountry, Country* toCountry, int amount);
};

