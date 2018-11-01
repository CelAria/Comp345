//
//  main.cpp
//  GameStart
//
//  Created by Celeste Pimm on 2018-10-31.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "maploader.h"
#include "controllergamestart.h"
#include "viewgamestart.h"
#include "gamemap.h"

using namespace std;

int main(int argc, const char * argv[]) {

    
    //directory where maps are stored
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    const string map= "/Users/celestepimm/Documents/Comp345-(second)/MapLoaderDriver/Africa.map";
    printMapDirectory(directory);
    Maploader mymaploader;
    //open map and test if valid, if valid, create map object
    mymaploader.readmapfile(map);
    
    GameStart game;
    //player input
    game.selectPlayers();
    //create player objects with hand of empty cards and dice facilities
    game.createPlayers();
    //create deck object
    game.createDeck(mymaploader.ptrgamemap);
  
    
}
