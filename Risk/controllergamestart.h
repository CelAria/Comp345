//
//  gamestart.hpp
//  Risk
//
//  Created by Celeste Pimm on 2018-10-22.
//  Copyright © 2018 comp345. All rights reserved.

#pragma once

#include "maploader.h"
#include <boost/filesystem.hpp>
#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "cardsdeck.h"
#include "Dice.h"

class GameStart{
    
public:
    
    const int selectPlayers(); //return the number of players selected by user
    const vector<Player*> createPlayers();  //return vector of pointers to player objects
    const Player* createPlayerHand();       //return pointer to each player
    const vector<Player*> playerOrder(); //return vector of randomly ordered players ??
    
    const Deck* createDeck();              //return pointer to global deck
    const GameMap* createGameMap();        //return pointer to global gamemap
    const Player* assignCountries();          //assign countries to each player round robin style
    const Player* placeArmies();              //assign armies to each country round robin style
    
private:
    int numberofplayers;  //number of players in game
    static Deck* gamedeck;     //pointer to global deck
    static GameMap* map;       //pointer to global map
    vector<Player*> players;    //vector of all players that has been created
};

bool verifyInputStringIsInteger(string s);
