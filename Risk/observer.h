//
//  observer.h
//  Risk
//
//  Created by Allan Pichardo on 11/10/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "gamemap.h"

class Player;

//Enum for keeping track of the game state
typedef enum : int {
    ATTACK,
    REINFORCE,
    FORTIFY,
    GAME_OVER,
    MOVE_COUNTRY
} Phase;

//A data structure that represents
//the game at a certain moment in time
class State {
public:
    Phase phase;
    Player* currentPlayer;
    GameMap* gameMap;
    
    State(): phase(REINFORCE), currentPlayer(NULL), gameMap(NULL) {};
    State(Phase phase, Player* player, GameMap* gameMap): phase(phase), currentPlayer(player), gameMap(gameMap) {};
    State(GameMap* gameMap): gameMap(gameMap), currentPlayer(NULL), phase(REINFORCE) {};
    State(Phase phase): phase(phase), gameMap(NULL), currentPlayer(NULL) {};
};

class Observer {
public:
    virtual void update(State& state) = 0; //update observer with the curren state of the game
};


