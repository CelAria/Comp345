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

void printvecString(vector<string> vec){
    vector<string>::iterator it;
    for(it=vec.begin(); it !=vec.end(); it++){
        cout << *it << " ";
    }
}

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
            cin.ignore(INT_MAX, '\n');
            selectgamemode();
        }
        if(input == 1){
            // TO DO: START GAME
        }
        else if(input == 2){
            //TO DO: START TOURNAMENT
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
    printvecString(selectedmaps);
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
    cout << "Available Strategies:" << endl << "1.Aggresive Player" << endl << "2.Benevolent Player" << endl << "3.Cheater" << endl << "4.Random" << endl;
}


void Tournament::StrategySwitch(){
    cout << "enter selection" << endl;
    int selection;
    cin >> selection;
    if(cin.good()){
        if(selection < 1 || selection > 4){
            cout << "bad value! Try again" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            StrategySwitch();
        }
    switch(selection){
        case 1:
            selectedstrategies.push_back("Aggressive");
            return;
        case 2:
             selectedstrategies.push_back("Benevolent");
            return;
        case 3:
            selectedstrategies.push_back("Cheater");
            return;
        case 4:
            selectedstrategies.push_back("Random");
            return;
        }
    }
    else{
        cout << "Not an integer.";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        StrategySwitch();
    }
}

vector<string> Tournament::selectstrategies(){
    inputnumStrategies();
    printStrategies();
    for (int i=0; i < numstrategies; i++){
        StrategySwitch();
    }
    printvecString(selectedstrategies);
    return selectedstrategies;
}

int Tournament::inputnumGames(){
    cout << "How many Games per maps? Enter an integer between 1 and 5" << endl;
    cin >> numgames;
    if(cin.good())
    {
        if(numgames < 1 || numgames > 5) {
            cout << "Bad value. Enter a value between 1 and 5";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            inputnumGames();
        }
    }
    else{
        cout << "Not an integer.";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        inputnumGames();
    }
    return numgames;
}

int Tournament::selectnumgames(){
    inputnumGames();
    return numgames;
}

int Tournament::inputnumTurns(){
    cout << "How many Turns per Game? Enter an integer between 10 and 50" << endl;
    cin >> numturns;
    if(cin.good())
    {
        if(numturns < 10 || numturns > 50) {
            cout << "Bad value. Enter a value between 1 and 5";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            inputnumTurns();
        }
    }
    else{
        cout << "Not an integer.";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        inputnumTurns();
    }
    return numturns;
}
int Tournament::selectnumturns(){
    inputnumTurns();
    return numturns;
}

void tournamentloop();

//final print of 
void print();

