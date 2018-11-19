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
#include "gamestatview.h"

int main(int argc, const char * argv[]) {
    
    const string directory = "/Users/allanpichardo/Documents/Dev/Comp345/StatsWinnerDriver";
    
    //initialize a game
    GameStart gameStart;
    GameMap* gameMap = gameStart.createGameMap(directory);
    Deck* deck = gameStart.createDeck(gameMap);
    vector<Player*> players = gameStart.createPlayers(gameStart.selectPlayers(), gameMap);
    
    //initialize views
    MainGame mainGame = MainGame(gameMap, players, deck);
    PhaseView phaseView;
    GameStatView gameStatView(gameMap, players);
    
    //set observers
    mainGame.addObserver(&phaseView);
    for(int i = 0; i < players.size(); ++i) {
        players[i]->addObserver(&gameStatView);
    }
    
    mainGame.playGame();
}
