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

int main(int argc, const char * argv[]) {
    
    GameMap* gameMap;
    vector<Player*> players;
    Deck* deck;
    
    const string directory = "/Users/allanpichardo/Documents/Dev/Comp345/MapLoaderDriver/";
    printMapDirectory(directory);
    Maploader mapLoader;
    gameMap = mapLoader.readmapfile();
    
    GameStart gameStart;
    deck = gameStart.createDeck(gameMap);
    players = gameStart.createPlayers(gameStart.selectPlayers(), gameMap);
    
    /*
     Game loop beings.
     For each turn, all of the player's countries will be given to
     the next player.
     The final player should end up with all the countries
     */
    
    MainGame mainGame = MainGame(gameMap, players, deck);
    
    int turn = 1;
    
    cout << "There are " << players.size() << " players." << endl;
    cout << "Expecting game to last " << players.size() - 1 << " turns" << endl;
    
    while(!mainGame.isGameOver()) {
        Player* player = mainGame.getNextPlayer();
        
        cout << "Starting turn " << turn << " with player " << player->getPlayerId() << endl;
        mainGame.executeTurn();
        
        cout << "Moving all countries from this player to the next" << endl;
        Player* nextPlayer = mainGame.getNextPlayer();
        for(int i = 0; i < player->getAllCountries().size(); ++i) {
            player->getAllCountries()[i]->setOwner(nextPlayer->getPlayerId());
        }
    }
    
    cout << endl;
    cout << "Expecting winner to be player " << players[players.size() - 1]->getPlayerId() << endl;
    cout << "The actual winner is player " << mainGame.getWinner()->getPlayerId() << endl;
}
