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
#include "maploader.h"
#include "controllergamestart.h"
#include "viewgamestart.h"
#include "gamemap.h"
#include "player.h"
#include "cardsdeck.h"

int main(int argc, const char * argv[]) {
    
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    
    printMapDirectory(directory);
    Maploader mymaploader;
    
    GameMap* gameMap = mymaploader.readmapfile();
    
    GameStart game;
    
    //create game deck of cards
    game.createDeck(gameMap);
    
    //player input
    int numberOfPlayers = game.selectPlayers();
    
    //create player objects with hand of empty cards and dice facilities
    vector<Player*> players = game.createPlayers(numberOfPlayers, gameMap);
}
