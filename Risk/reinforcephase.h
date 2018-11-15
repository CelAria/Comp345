// Team project assignment #2 - Part 4
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
// Description: header file for the deck and hand
// ------------------------------------------------------
#pragma once

#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "reinforceview.h"

//ReinforceController class definition
class ReinforceController {
private:
    ReinforceView view;
    Player* player;
    GameMap* gameMap;
        
public:
    //ReinforceController constructor including a player and gameMap passed as parameters
    ReinforceController(Player* player, GameMap* gameMap){
        this->player = player;
        this->gameMap = gameMap;
        view = ReinforceView();
    };
    //start method to indicate the ReinforceController to start the reinforce method of the player
    void start();
};
