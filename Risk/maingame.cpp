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

int MainGame::printWinner(){
    for(int i = 0; i < players.size(); ++i) {
        if(players[i]->getAllCountries().size() == gameMap->getCount()) {
            return players[i]->getPlayerId();
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

/**
 Will go through each phase of the game
 updating the observer each time
 */
void MainGame::executeTurn() {
    Player* currentPlayer = getNextPlayer();
    
    phase = REINFORCE;
    notifyObservers();
    currentPlayer->reinforce(gameMap);
    
    phase = ATTACK;
    notifyObservers();
    currentPlayer->attack(gameMap);
    
    phase = FORTIFY;
    notifyObservers();
    currentPlayer->fortify(gameMap);
    
    currentPlayer->drawCard(deck);
    
    updateTurn();
}

/**
 The main loop of the game
 */
void MainGame::playGame(int turns) {
    
    if(turns > 0) {
        int i = 0;
        while(!isGameOver() && i < turns) {
            executeTurn();
            i++;
        }
    } else {
        while(!isGameOver()) {
            executeTurn();
        }
    }
    
    phase = GAME_OVER;
    notifyGameOver();
}

/**
 Make a state object and put the relevant
 info in it. Then iterate through each
 observer, calling update()
 */
void MainGame::notifyObservers() {
    State newState = State(phase, getNextPlayer(), gameMap);
    for(auto observer : observers) {
        observer->update(newState);
    }
}

void MainGame::notifyGameOver() {
    State newState = State(phase, getWinner(), gameMap);
    for(auto observer : observers) {
        observer->update(newState);
    }
}
