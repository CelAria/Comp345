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

//returns
map<string,int> GameStatView::worlddominationview(){
    
    for(vector<Player*>:: iterator it= maingame->getPlayers().begin(); it != maingame->getPlayers().end(); ++it){
        //get the number of countries owned by each player
        int numcountries=(*it)->getAllCountries().size();
        worlddominationmap[to_string((*it)->getPlayerId())]= round((float(numcountries)/maingame->getGameMap()->getCount())*100.0);
    }
    return worlddominationmap;
};

//void GameStatView::clearScreen() {
//    system("clear");
//};

//check the gamestate
void GameStatView::update(State& state){
    this->state = state;
    print();
};

//tests if a player owns all the countries
bool GameStatView::testWinner(Player* player){
    if(player->getCountriesCount()==maingame->getGameMap()->getCount()){return true;}
    else return false;
};

// print function which outputs to the terminal
void GameStatView::print(){
   // clearScreen();
    cout << "\nWorld Domination View" << endl;
    cout << "************************" << endl;
    cout << "Order of Play: ";
    for (vector<Player*>::const_iterator i = maingame->getPlayers().begin(); i != maingame->getPlayers().end(); ++i){
        std::cout << "player " << (*i)->getPlayerId() << ", ";
    }
    cout << "\nTotal Countries in Map: " << maingame->getGameMap()->getCount();
    
    cout << "\nCountries owned: ";
    
   
    vector<Player*> a= maingame->getPlayers();
    vector<Player*>::iterator it;
    int j=0;
    for ( it = a.begin(); it != a.end(); it++ )
    {
        cout << "Player " << (*it)->getPlayerId() << ":" << "[" << (*it)->getAllCountries().size() << "], ";
        
        if(testWinner(*it)==true){
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@"<< endl;
            cout << "WINNER IS PLAYER "<< (*it)->getPlayerId() << endl;
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@"<< endl;
            exit(0);
        }
        j++;
    }
    cout << endl;
    
    // PROGRESS BAR PRINTING
    for(int x=0; x < 100; x++){
        cout << "-";
    }
    cout << "| 100%" << endl;
    for( auto const& [player, owned] : worlddominationview())
    {
    if(!owned==0){
        for(int x=0; x < owned; x++){
        cout << ".";
        }
        cout << "|  player " <<  player << ": " << owned << "%" << endl;
    }
    }
    cout << "************************" << endl;
};

