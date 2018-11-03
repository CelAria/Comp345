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
    int selectPlayers(); //return the number of players selected by user
    vector<Player*> createPlayers(int amount, GameMap* gameMap);  //return vector of pointers to player objects
    Deck* createDeck(GameMap* pointertogamemap);
    
    
private:
    int numberofplayers;  //number of players in game
    vector<Player*> players; //vector of all players that has been created
    
    vector<Player*> assignCountries(GameMap* pointertogamemap); //assign countries to each player round robin style
    vector<Player*> playerOrder(); //return vector of randomly ordered players ??
    vector<Player*> placeArmies(GameMap* pointertogamemap); //assign armies to each country round robin style
};

bool verifyInputStringIsInteger(string s);
//const Deck* createDeck(GameMap* pointertogamemap);
