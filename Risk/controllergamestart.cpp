//
//  gamestart.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-10-22.
//  Copyright © 2018 comp345. All rights reserved.
//
// this file is to do the game start functions
#include "controllergamestart.h"
#include "maploader.h"
#include "gamemap.h"
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;


bool verifyInputStringIsInteger(string s){
    int tempint;
    if (boost::conversion::try_lexical_convert(s, tempint)){
        return true;
    }
    if (!boost::conversion::try_lexical_convert(s, tempint)){
        return false;
    }
    else return false;
};

// works but prints multiple times when the correct value is found?
const int GameStart::selectPlayers(){
    cout << "please input the number of players (2-6). Type using numbers such as 2,3,4,5,6." << endl;
    string tempinput;
    cin >> tempinput;
    
    if (verifyInputStringIsInteger(tempinput)==true){
        numberofplayers= stoi(tempinput);
        if(numberofplayers >=7 || numberofplayers <=1){
            numberofplayers= stoi(tempinput);
            cin.clear();
            cin.ignore(BC_STRING_MAX, '\n');
            tempinput.clear();
            tempinput.erase();
            cout << "value is less than 2 or greater than 7" << endl;
            cout << tempinput;
            selectPlayers();
        }
        else{
            cout << "(" <<  numberofplayers << ")" << " players have been created. Assign each player a unique player number ID between (1) and" << " (" << numberofplayers << ")." << " Player order will now be shuffled...\n" << endl;
            return numberofplayers;
        }
    }
    if (verifyInputStringIsInteger(tempinput)==false){
        cout << tempinput << endl;
        cout <<"not a integer number value. Select players (2-6). Enter an integer";
        cin.clear();
        tempinput.clear();
        tempinput.erase();
        cin.ignore(BC_STRING_MAX, '\n');
        selectPlayers();
        return numberofplayers;
    }
  
    return numberofplayers;
};


// returns vector array of player pointers
const vector<Player*> GameStart::createPlayers(){
    
    for(int j=1; j <= numberofplayers; j++){
        
        // create new player object (initialize with player ID= j and push into vector players
        players.push_back(new Player(j));
    }
    return players;
};

const Deck* GameStart::createDeck(GameMap* pointertogamemap){
    int numberofcards= (pointertogamemap)->getCount();
    Deck* gamedeck = new Deck(numberofcards);
    cout << "there are " << numberofcards << " cards in the deck" << endl;
    return gamedeck;
    
};

const vector<Player*> GameStart::playerOrder(){
    
    //srand(time(0));
    auto randomizer = default_random_engine {};
    shuffle(begin(players), end(players), randomizer);
    
    cout << "Order of Play: ";
    for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i){
        std::cout << "player " << (*i)->getPlayerId() << ", ";
    }
    cout << endl;
    return players;
};

const vector<Player*> GameStart::assignCountries(GameMap* pointertogamemap){
    //All countries in the map are randomly assigned to players one by one in a round-robin fashion.
    
    int size = pointertogamemap->getCount();
    vector<int> randomorder;
    //make a vector with integers of the number of countries.
    for (int j=0; j < size; j++){
        randomorder.push_back(j);
    }
    auto randomizer = default_random_engine {};
    //randomize the "random order" array!
    srand((unsigned)time(0));
    shuffle(begin(randomorder), end(randomorder), randomizer);
    //print
    for (int j=0; j < randomorder.size(); j++){
        cout <<  randomorder[j] << " "  << j << endl;
    }
    
    //
    vector<int>::iterator it;
    int i = 0;
    for(it = randomorder.begin(); it != randomorder.end(); it++,i++){
        cout << "assign country number " << *it << endl;
        
    }
    
        for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i){
            std::cout << " " << (*i)->getPlayerId() << ", ";
        }
//
//    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
//        visited[it->first] = false;
//    }
    
    return players;
};
