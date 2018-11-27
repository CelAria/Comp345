//
//  tournament.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-11-26.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "tournament.h"
#include "maingame.h"
#include "maploader.h"


void selectgamemode(){
    cout << "would you like to enter GAME mode or TOURNAMENT mode?" << endl;
    cout << "1. GAME MODE" << endl;
    cout << "2. TOURNAMENT MODE" << endl;
    int input;
    cin >> input;
    if(cin.good()){
        if(input < 0 || input > 2){
            cout << "invalid value. Try again" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            selectgamemode();
        }
        else{
            cout << "Invalid. Try again";
            cin.clear();
            cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
            selectgamemode();
        }
        if(input == 1){
           // START GAME
        }
        else if(input == 2){
            // START TOURNAMENT
        }
    }
}

int Tournament::inputnumMaps(){
    cout << "How many maps would you like to select? Enter an integer between 1 and 5" << endl;
    cin >> nummaps;
    if(cin.good())
    {
    if(nummaps < 0 || nummaps > 5) {
        cout << "Bad value. Enter a value between 1 and 5";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        inputnumMaps();
        }
    }
    else{
    cout << "Not an integer.";
    cin.clear();
    cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
    inputnumMaps();
    }
    return nummaps;
}


//asks for user input for maps, then stores in an array.
vector<string> Tournament::inputmaps(const string directory){
    //display directory
    //get number of maps
    inputnumMaps();
    cout << nummaps << endl;
    printDirectory(directory);
    
    string map;
    //loop and push each map string into vector
    for (int i=0; i < nummaps; i++){
        map=selectMap(directory);
        selectedmaps.push_back(map);
    }
    return selectedmaps;
};

int Tournament::inputnumStrategies(){
    cout << "How many strateges would you like to select? Enter an integer between 2 and 4" << endl;
    cin >> numstrategies;
    if(cin.good())
    {
        if(numstrategies < 2 || numstrategies > 4 ) {
            cout << "Bad value. Enter a value between 2 and 4";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            inputnumStrategies();
        }
    }
    else{
        cout << "Not an integer.";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        inputnumStrategies();
    }
    return numstrategies;
}

void Tournament::printStrategies(){
    cout << "Available Strategies:" << endl << "1.Aggresive Player" << endl << "2.Benevolent Player" << endl << "3.Cheater" << endl << "4.Random";
}



vector<Strategy*> Tournament::selectstrategies(){
    inputnumStrategies();
    printStrategies();
    for (int i=0; i < numstrategies; i++){
        Strategy* s;
        selectedstrategies.push_back(s);
    }
    return selectedstrategies;
}



int selectnumgames();
int selectnumturns();
void tournamentloop();
void print();

