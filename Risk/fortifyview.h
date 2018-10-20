//
//  fortifyview.hpp
//  Risk
//
//  Created by Allan Pichardo on 10/20/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "country.h"
#include <vector>

using namespace std;

class FortifyView {
    
private:
    Player* player;
    
public:
    FortifyView(Player* player) {this->player = player;};
    Country* showCountrySelectList(vector<Country*> countries);
    void presentFortify();
};

