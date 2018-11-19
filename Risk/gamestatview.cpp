//
//  gamestatview.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-11-11.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "gamestatview.h"
#include "player.h"
#include "observer.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//returns map of player ID and percentage owned
map<string,int> GameStatView::worlddominationview(){
    
    for(vector<Player*>:: iterator it= players.begin(); it != players.end(); ++it){
        //get the number of countries owned by each player
        int numcountries=(*it)->getAllCountries().size();
        worlddominationmap[to_string((*it)->getPlayerId())]= round((float(numcountries)/gameMap->getCount())*100.0);
    }
    return worlddominationmap;
};


//check the gamestate
void GameStatView::update(State& state){
    this->state = state;
    if(state.gameMap != NULL) {
        this->gameMap = state.gameMap;
    }
    print();
};

//tests if a player owns all the countries
bool GameStatView::testWinner(Player* player){
    if(player->getCountriesCount()==gameMap->getCount()){return true;}
    else return false;
};

// print function which outputs to the terminal
void GameStatView::print(){
    
    if(gameMap == NULL) return;

    cout << "\nWorld Domination View" << endl;
    cout << "************************" << endl;
    cout << "Order of Play: ";
    for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i){
        std::cout << "player " << (*i)->getPlayerId() << ", ";
    }
    cout << "\nTotal Countries in Map: " << gameMap->getCount();
    
    cout << "\nCountries owned: ";
    
   // "Countries Owned" printing
    //vector<Player*> a= players;
    vector<Player*>::iterator it;
    
    for ( it = players.begin(); it != players.end(); it++ )
    {
        cout << "Player " << (*it)->getPlayerId() << ":" << "[" << (*it)->getAllCountries().size() << "], ";
    }
    
    cout << endl;
    
    // PROGRESS BAR PRINTING
    for(int x=0; x < 100; x++){
        cout << "-";
    }
    cout << "| 100%" << endl;
    for( auto const& [player, owned] : worlddominationview())
    {
    //check that players own a country before printing (remove players from view)
    if(!owned==0){
        for(int x=0; x < owned; x++){
        cout << ".";
        }
        cout << "|  player " <<  player << ": " << owned << "%" << endl;
    }
    }
    cout << "************************" << endl;
    
    //Winner test
    if(state.phase== GAME_OVER){
        
        for (it = players.begin(); it != players.end(); it++){
            if(testWinner(*it)==true){
            cout << endl;
            cout<<"\n@@@@@@@@@@@@@@@@@@@@@@"<< endl;
            cout<<"! ! ! ! ! ! ! ! ! ! ! " << endl;
            cout<<"----------------------" << endl;
            cout << "WINNER IS PLAYER "<< (*it)->getPlayerId() << endl;
            cout<<"----------------------" << endl;
            cout<<"! ! ! ! ! ! ! ! ! ! ! " << endl;
            cout<<"@@@@@@@@@@@@@@@@@@@@@@"<< endl;

            cout << R"(
            __/\\\______________/\\\__/\\\\\\\\\\\__/\\\\\_____/\\\__/\\\\\_____/\\\__/\\\\\\\\\\\\\\\____/\\\\\\\\\_____
            _\/\\\_____________\/\\\_\/////\\\///__\/\\\\\\___\/\\\_\/\\\\\\___\/\\\_\/\\\///////////___/\\\///////\\\___
            _\/\\\_____________\/\\\_____\/\\\_____\/\\\/\\\__\/\\\_\/\\\/\\\__\/\\\_\/\\\_____________\/\\\_____\/\\\___
            _\//\\\____/\\\____/\\\______\/\\\_____\/\\\//\\\_\/\\\_\/\\\//\\\_\/\\\_\/\\\\\\\\\\\_____\/\\\\\\\\\\\/____
            __\//\\\__/\\\\\__/\\\_______\/\\\_____\/\\\\//\\\\/\\\_\/\\\\//\\\\/\\\_\/\\\///////______\/\\\//////\\\____
            ___\//\\\/\\\/\\\/\\\________\/\\\_____\/\\\_\//\\\/\\\_\/\\\_\//\\\/\\\_\/\\\_____________\/\\\____\//\\\___
            ____\//\\\\\\//\\\\\_________\/\\\_____\/\\\__\//\\\\\\_\/\\\__\//\\\\\\_\/\\\_____________\/\\\_____\//\\\__
            _____\//\\\__\//\\\_______/\\\\\\\\\\\_\/\\\___\//\\\\\_\/\\\___\//\\\\\_\/\\\\\\\\\\\\\\\_\/\\\______\//\\\_
            ______\///____\///_______\///////////__\///_____\/////__\///_____\/////__\///////////////__\///________\///__
            )" << endl;
            }
        }
    }
};

