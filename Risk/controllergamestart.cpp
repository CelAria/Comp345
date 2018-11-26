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
#include <cstdlib>
#include <ctime>

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
int GameStart::selectPlayers(){
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
//            cout << "(" <<  numberofplayers << ")" << " players have been created. Assign each player a unique player number ID between (1) and" << " (" << numberofplayers << ")." << " Player order will now be shuffled...\n" << endl;
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
vector<Player*> GameStart::createPlayers(int amount, GameMap* gameMap){
    
    for(int j=1; j <= numberofplayers; j++){
        // create new player object (initialize with player ID= j and push into vector players
        players.push_back(new Player(j));
    }
    
    playerOrder();
    assignCountries(gameMap);
    placeArmies(gameMap);
    
    return players;
};

Deck* GameStart::createDeck(GameMap* pointertogamemap){
    int numberofcards= (pointertogamemap)->getCount();
    Deck* gamedeck = new Deck(numberofcards);
    cout << "there are " << numberofcards << " cards in the deck" << endl;
    return gamedeck;
    
};

vector<Player*> GameStart::playerOrder(){

    std::random_device rng;
    std::mt19937 urng(rng());
    shuffle(begin(players), end(players), urng);
    
//    cout << "Order of Play: ";
//    for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i){
//        std::cout << "player " << (*i)->getPlayerId() << ", ";
//    }
//    cout << endl;
    return players;
};

vector<Player*> GameStart::placeArmies(GameMap* pointertogamemap){
    /*Players are given a number of armies (A), to be placed one by one in a round-robin fashion*/
    int numArmies= 0;

    switch(players.size()){
        case 2: numArmies=40;
            break;
        case 3: numArmies=35;
            break;
        case 4: numArmies=30;
            break;
        case 5: numArmies=25;
            break;
        case 6: numArmies=20;
            break;
    }

    //For each player one by one
    for(int i = 0; i < players.size(); i++){
        //get the player's countries
        Player* player = players[i];
        vector<Country*> playerCountries = player->getAllCountries();
        
        //check that one army is placed on each country owned
        for(int k=0; k <playerCountries.size(); k++){
          playerCountries[k]->IncrementArmiesCount();
        }
        //as long as there are remaining armies to give
        for(int j = 0; j < (numArmies-playerCountries.size()); j++) {
            //place one army at a random country
            int randomnum = rand() %  playerCountries.size();
            //cout << "add army to " << playerCountries[randomnum]->getName() << endl;
            playerCountries[randomnum]->IncrementArmiesCount();
        }
    }
    
    return players;
};


vector<Player*> GameStart::assignCountries(GameMap* pointertogamemap){
    //All countries in the map are randomly assigned to players one by one in a round-robin fashion.
    
    int size = pointertogamemap->getCount();
    vector<int> randomorder;
    //make a vector with integers of the number of countries.
    for (int j=0; j < size; j++){
        randomorder.push_back(j);
    }
    
    std::random_device rng;
    std::mt19937 urng(rng());
    //randomize the "random order" array!
    shuffle(begin(randomorder), end(randomorder), urng);
    
    
    int m = 0;
    vector<Country*> allCountries = pointertogamemap->getAllCountries();
    
    for(int i = 0; i < randomorder.size(); i++) {
        Country* toBeAssigned = allCountries[randomorder[i]];
        
        players.at(m % players.size())->addCountry(toBeAssigned);
        
        m++;
    }
    
    return players;
};

GameMap* GameStart::createGameMap(string directory) {
    Maploader maploader;
    printDirectory(directory);
    string mapPath = maploader.selectMap(directory);
    return maploader.readmapfile(mapPath, directory);
}

void GameStart::addPlayerObservers(Observer* obs){
    vector<Player*>::iterator it;
    for(it= players.begin(); it!= players.end(); it++){
        (*it)->addObserver(obs);
    }
}
