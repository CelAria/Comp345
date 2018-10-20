//
//  mapvisualizer.hpp
//  Risk
//
//  Created by Allan Pichardo on 10/20/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include <string>

using namespace std;

class Box {
public:
    int armies, player, top, left, width, height;
    string name;
    
    Box(string name, int armies, int player) {
        this->name = name;
        this->armies = armies;
        this->player = player;
    };
    
    char** render();
    
};
