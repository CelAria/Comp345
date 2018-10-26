//
//  viewgamestart.h
//  Risk
//
//  Created by Celeste Pimm on 2018-10-23.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include <vector>
#include <string>
#include "cardsdeck.h"
#include "maploader.h"
#include "gamemap.h"
#include "controllergamestart.h"

using namespace std;

class viewGameStart{
  
public:
    
private:
    
};

// declared outside of class definition
void printMapDirectory(const string& name);
void printDeck(Deck* deck);
