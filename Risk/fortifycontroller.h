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
    
public:
    FortifyController() {
        view = FortifyView();
    };
    
    FortifyController(Player* player, GameMap* gameMap) {
        this->player = player;
        this->gameMap = gameMap;
        view = FortifyView();
    };
    
    /**
     Executes the Fortify phase
     */
    void start();
    /**
     Transfer armies from one country to another
     */
    bool moveArmies(Country* fromCountry, Country* toCountry, int amount);
};

