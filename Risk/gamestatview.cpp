//
//  gamestatview.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-11-11.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "gamestatview.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// notes* doesn't return the worlddominationmap

string GameStatView::worlddominationview(MainGame* main){
    stringstream outstream;
    
    for(vector<Player*>:: iterator it= main->getPlayers().begin(); it != main->getPlayers().end(); ++it){
        //get the number of countries owned by each player
        int numcountries=(*it)->getAllCountries().size();
        worlddominationmap[*it]= numcountries;
        outstream << "Player " << (*it)->getPlayerId() << " has " << numcountries << " countries" << endl;
    }
    return outstream.str();
};

void GameStatView::clearScreen() {
    system("clear");
};

void GameStatView::print(MainGame* main){
   // clearScreen();
    cout << worlddominationview(main);
};

