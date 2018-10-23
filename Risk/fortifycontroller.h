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
#include "fortifyview.h"

class FortifyController {
private:
    FortifyView view;
    Player* player;
    GameMap* gameMap;
    
    bool moveArmies(Country* fromCountry, Country* toCountry, int amount);
    
public:
    FortifyController(Player* player, GameMap* gameMap) {
        this->player = player;
        this->gameMap = gameMap;
        view = FortifyView();
    };
    void start();
};
