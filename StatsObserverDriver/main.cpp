//
//  main.cpp
//  StatsObserverDriver
//
//  Created by Celeste Pimm on 2018-11-11.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "gamestatview.h"
#include "maingame.h"
#include "maploader.h"
#include "controllergamestart.h"
#include "viewgamestart.h"
#include "gamemap.h"
#include "player.h"
#include "cardsdeck.h"

int main(int argc, const char * argv[]) {
    
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    
    Maploader mymaploader;
    mymaploader.printDirectory(directory);
    GameMap* gameMap = mymaploader.readmapfile(mymaploader.selectMap(directory), directory);
    GameStart game;
    //create game deck of cards
    Deck* deck =game.createDeck(gameMap);
    //player input
    int numberOfPlayers = game.selectPlayers();
    //create player objects with hand of empty cards and dice facilities
    vector<Player*> players = game.createPlayers(numberOfPlayers, gameMap);
//
//    MainGame* main= new MainGame(gameMap, players, deck);
//    GameStatView gamestatview;
//    gamestatview.print(main);
//    delete main;
}
