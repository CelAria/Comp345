//
//  main.cpp
//  GameStart
//
//  Created by Celeste Pimm on 2018-10-31.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include <vector>
#include "maploader.h"
#include "controllergamestart.h"
#include "viewgamestart.h"
#include "gamemap.h"
#include "player.h"
#include "cardsdeck.h"
#include "maingame.h"
#include "gamestatview.h"

using namespace std;

int main(int argc, const char * argv[]) {

    /*Provide a group of C++ classes that implement a user interaction mechanism to start the game by allowing the
     player to 1) select a map from a list of map files as stored in a directory 2) select the number of players in the
     game (2-6 players). The code should then use the map loader to load the selected map, create all the players,
     assign dice rolling facilities to the players, create a deck of cards, and assign an empty hand of cards to each
     player. You must deliver a driver that demonstrates that 1) different valid maps can be loaded and their validity is
     verified (i.e. it is a connected graph, etc), and invalid maps are gracefully rejected; 2) the right number of players
     is created, a deck with the right number of cards is created. */
    
    //directory where maps are stored
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    //printMapDirectory(directory);
    
    //open map and test if valid, if valid, create map object  
    
    Maploader mymaploader;
    mymaploader.printDirectory(directory);
   // mymaploader.selectMap(directory);
    
    GameMap* gameMap = mymaploader.readmapfile(mymaploader.selectMap(directory), directory);
    GameStart game;
    
    //create game deck of cards
    Deck* deck =game.createDeck(gameMap);
    
    //player input
    int numberOfPlayers = game.selectPlayers();
    
    //create player objects with hand of empty cards and dice facilities
    vector<Player*> players = game.createPlayers(numberOfPlayers, gameMap);
    
        MainGame* main= new MainGame(gameMap, players, deck);
        GameStatView gamestatview;
        gamestatview.print(main);
        delete main;

}
