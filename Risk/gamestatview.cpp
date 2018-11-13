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

map<string,int> GameStatView::worlddominationview(MainGame* main){
    stringstream outstream;
    map<Player*, int> worlddom;
    
    for(vector<Player*>:: iterator it= main->getPlayers().begin(); it != main->getPlayers().end(); ++it){
        //get the number of countries owned by each player
        int numcountries=(*it)->getAllCountries().size();
        worlddominationmap[to_string((*it)->getPlayerId())]= round((float(numcountries)/main->getGameMap()->getCount())*100.0);
    }
    return worlddominationmap;
};

void GameStatView::clearScreen() {
    system("clear");
};

void GameStatView::print(MainGame* main){
   // clearScreen();
    cout << "\nWorld Domination View" << endl;
    cout << "************************" << endl;
    
    cout << "Countries owned: ";
    
    vector<Player*> a= main->getPlayers();
    vector<Player*>::iterator it;
    for ( it = a.begin(); it != a.end(); it++ )
    {
        cout << "Player " << (*it)->getPlayerId() << ":" << "[" << (*it)->getCountriesCount() << "], ";
        
    }
    cout << endl;
    
    // PROGRESS BAR PRINTING
    for(int x=0; x < 100; x++){
        cout << "-";
    }
    cout << "| 100%" << endl;
    for( auto const& [player, owned] : worlddominationview(main))
    {
        for(int x=0; x < owned; x++){
            cout << ".";
        }
        cout << "|  player " <<  player << ": " << owned << "%" << endl;
    }
     cout << "************************" << endl;
};

