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

    std::random_device rng;
    std::mt19937 urng(rng());
    shuffle(begin(players), end(players), urng);
    
    cout << "Order of Play: ";
    for (vector<Player*>::const_iterator i = players.begin(); i != players.end(); ++i){
        std::cout << "player " << (*i)->getPlayerId() << ", ";
    }
    cout << endl;
    return players;
};

const vector<Player*> GameStart::placeArmies(GameMap* pointertogamemap){
    /*Players are given a number of armies (A), to be placed one by one in a round-robin fashion*/
    int numArmies= 0;
    int i= players.size();

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
    cout << "\n number of armies:" << numArmies << endl;

    //loop through players array repeatedly
    
    for(int playerid=1; playerid <= players.size(); playerid++){
        
        // print the countries owned by that player ID
        CountriesOwned(pointertogamemap, playerid);
        
        cout << "Player " << playerid << " pick country to place army" << endl;
        int num = (CountriesOwned(pointertogamemap, playerid)).size();
        //generate a random number between 0 and amount of countries they own
        int randomnum = (rand() % ( num + 1 ));
        cout << "add army to Country number " << randomnum << endl;
        //increment number of armies on that country by 1
        (CountriesOwned(pointertogamemap, playerid).at(randomnum))->IncrementArmiesCount();
    //go to next player
    playerid++;
        if((playerid > players.size())){
            playerid= 1;
        }
    }
    cout << "return players";
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
    
    std::random_device rng;
    std::mt19937 urng(rng());
    //randomize the "random order" array!
    shuffle(begin(randomorder), end(randomorder), urng);
    for(vector<int>::const_iterator it = randomorder.begin(); it != randomorder.end(); it++){
      //  cout <<"random " << *it << endl;
    }
    
    vector<int>::iterator it;
    int m = 0;
    int i = 0;
    for(it = randomorder.begin(); it != randomorder.end(); it++,i++){
        cout << "assign country number " << *it << " to player ID" << m % players.size() + 1 << endl;
        //HOW TO GO TO EACH COUNTRY IN THE GAMEMAP ONE BY ONE?
        
        for (auto const& x : pointertogamemap->getAllCountries()){
            players.at(m)->addCountry(x);
        }
        m++;
        if(m == players.size()) m=0;
    }
    return players;
};

const vector<Country*> GameStart::CountriesOwned(GameMap* pointertogamemap, int playerid){
   
    vector<Country*> countriesowned;
    for (auto const& x : pointertogamemap->getAllCountries()){
        if(x->getOwner()== playerid) countriesowned.push_back(x);
    }
    cout << "Player " << playerid << " owns Countries:" << endl;
    for (vector<Country*>::const_iterator it = countriesowned.begin(); it != countriesowned.end(); ++it){
        cout << (*it)->getName() << endl;
        cout << "^name";
    }
    return countriesowned; 
};
