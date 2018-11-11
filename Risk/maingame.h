//
//  maingame.hpp
//  Risk
//
//  Created by Allan Pichardo on 11/3/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include <vector>
#include "player.h"
#include "gamemap.h"
#include "cardsdeck.h"
#include "observable.h"
#include "observer.h"

using namespace std;

class MainGame : public Observable {
private:
    Phase phase;
    GameMap* gameMap;
    vector<Player*> players;
    Deck* deck;
    int turn = 0;
    
    void updateTurn();
    
public:
    MainGame(GameMap* gameMap, vector<Player*> &players, Deck* deck) {
        this->gameMap = gameMap;
        this->players = players;
        this->deck = deck;
    };
    void executeTurn();
    Player* getNextPlayer(){return players[turn];};
    Player* getWinner();
    bool isGameOver();
    void playGame();
    void notifyObservers();
};
