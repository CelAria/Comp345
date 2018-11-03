//
//  maingame.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/3/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "maingame.h"

Player* MainGame::getWinner() {
    for(int i = 0; i < players.size(); ++i) {
        if(players[i]->getAllCountries().size() == gameMap->getCount()) {
            return players[i];
        }
    }
    return NULL;
}

bool MainGame::isGameOver() {
    return getWinner() != NULL;
}

void MainGame::updateTurn() {
    turn = (turn + 1) % players.size();
}

void MainGame::executeTurn() {
    Player* currentPlayer = getNextPlayer();
    
    currentPlayer->reinforce(gameMap);
    currentPlayer->attack(gameMap);
    currentPlayer->fortify(gameMap);
    
    updateTurn();
}
