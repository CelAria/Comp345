//
//  main.cpp
//  GameLoopDriver
//
//  Created by Allan Pichardo on 11/3/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "maingame.h"
#include "maploader.h"
#include "viewgamestart.h"
#include "controllergamestart.h"
#include "phaseview.h"

int main(int argc, const char * argv[]) {
    
    const string directory = "/Users/allanpichardo/Documents/Dev/Comp345/MapLoaderDriver";
    
    GameStart gameStart;
    GameMap* gameMap = gameStart.createGameMap(directory);
    Deck* deck = gameStart.createDeck(gameMap);
    vector<Player*> players = gameStart.createPlayers(gameStart.selectPlayers(), gameMap);
    
    
    MainGame mainGame = MainGame(gameMap, players, deck);
    PhaseView phaseView;
    
    mainGame.addObserver(&phaseView);
    mainGame.playGame();
}
