//
//  observer.h
//  Risk
//
//  Created by Allan Pichardo on 11/10/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "gamemap.h"

typedef enum : int {
    ATTACK,
    REINFORCE,
    FORTIFY,
    GAME_OVER,
    MOVE_COUNTRY
} Phase;

class State {
public:
    Phase phase;
    Player* currentPlayer;
    GameMap* gameMap;
    
    State(): phase(REINFORCE), currentPlayer(NULL), gameMap(NULL) {};
    State(Phase phase, Player* player, GameMap* gameMap): phase(phase), currentPlayer(player), gameMap(gameMap) {};
    State(GameMap* gameMap): gameMap(gameMap) {};
    State(Phase phase): phase(phase) {};
};

class Observer {
public:
    virtual void update(State& state) = 0;
};


