//
//  gamestart.hpp
//  Risk
//
//  Created by Celeste Pimm on 2018-10-22.
//  Copyright © 2018 comp345. All rights reserved.

#pragma once

#include "maploader.h"
#include "player.h"
#include "gamemap.h"
#include "country.h"
#include "cardsdeck.h"
#include "Dice.h"

class GameStart{
    
public:
    
    int selectPlayers(); //return the number of players selected by user
    
    static vector<Player*> createPlayers();  //return vector of pointers to player objects
    static Player* createPlayerHand();        //return pointer to each player
    static vector<Player*> playerOrder(); //return vector of randomly ordered players ??
    
    static Deck* createDeck();              //return pointer to global deck
    static GameMap* createGameMap();        //return pointer to global gamemap
    static Player* assignCountries();          //assign countries to each player round robin style
    static Player* placeArmies();              //assign armies to each country round robin style
    
private:
    int numberofplayers;  //number of players in game
    static Deck* gamedeck;     //pointer to global deck
    static GameMap* map;       //pointer to global map
    
};
