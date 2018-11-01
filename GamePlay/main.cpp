//
//  main.cpp
//  GamePlay
//
//  Created by Celeste Pimm on 2018-10-31.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "maploader.h"
#include "controllergamestart.h"
#include "viewgamestart.h"
#include "gamemap.h"

int main(int argc, const char * argv[]) {
    
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    printMapDirectory(directory);
    Maploader mymaploader;
    //open map and test if valid, if valid, create map object
    mymaploader.readmapfile();
    GameStart game;
    //player input
    game.selectPlayers();
    //create player objects with hand of empty cards and dice facilities
    game.createPlayers();
    game.playerOrder();
    game.createDeck(mymaploader.ptrgamemap);
    game.assignCountries(mymaploader.ptrgamemap);
}
