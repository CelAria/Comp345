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
#include "viewgamestart.h"
#include "controllergamestart.h"
#include "phaseview.h"
#include "gamestatview.h"
#include <vector>

void printvecString(vector<string> vec){
    vector<string>::iterator it;
    for(it=vec.begin(); it !=vec.end(); it++){
        cout << *it << " ";
    }
}

void Tournament::selectgamemode(string directory){
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
            selectgamemode(directory);
        }
        if(input == 1){
            startSingleGame(directory);
        }
        else if(input == 2){
            startTournament(directory);
        }
        else{
            cout << "Invalid. Try again";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            selectgamemode(directory);
        }
    }
}

int Tournament::inputnumMaps(){
    cout << "\nHow many maps would you like to select? Enter an integer between 1 and 5" << endl;
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
    printDirectory(directory);
    
    string map;
    //loop and push each map string into vector
    for (int i=0; i < nummaps; i++){
        map=selectMap(directory);
        selectedmaps.push_back(map);
    }
    return selectedmaps;
};

int Tournament::inputnumPlayers(){
    cout << "\nHow many players would you like to select? Enter an integer between 2 and 4" << endl;
    cin >> numstrategies;
    if(cin.good())
    {
        if(numstrategies < 2 || numstrategies > 4 ) {
            cout << "Bad value. Enter a value between 2 and 4";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            inputnumPlayers();
        }
    }
    else{
        cout << "Not an integer.";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        inputnumPlayers();
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
                //aggresive
                selectedstrategies.push_back(1);
                return;
            case 2:
                //benevolent
                selectedstrategies.push_back(2);
                return;
            case 3:
                //cheater
                selectedstrategies.push_back(3);
                return;
            case 4:
                //random
                selectedstrategies.push_back(4);
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

vector<int> Tournament::selectstrategies(){
    inputnumPlayers();
    printStrategies();
    for (int i=0; i < numstrategies; i++){
        StrategySwitch();
    }
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

void Tournament::tournamentloop(string directory){
    
    //FOR EACH MAP
    for(int i=0; i < selectedmaps.size(); i++){
        //PLAY THIS NUMBER OF GAMES
        for(int j=0; j < numgames; j++){
            GameStart gameStart;
            Maploader maploader;
            
            //for the selected map
            string mapPath= selectedmaps.at(i);
            //make the gamemap
            GameMap* gameMap= gameStart.createGameMap(mapPath, directory);
            //Check if map is valid
            if(!gameMap->isValid()) {
                //if not valid, go to next map
                delete gameMap;
                continue;
            }
            //make the deck
            Deck* deck = gameStart.createDeck(gameMap);
            //make the players
            gameStart.setNumPlayers(numstrategies);
            vector<Player*> players = gameStart.createPlayers(numstrategies, gameMap);
            
            // ASSIGN STRATEGIES
            
            for(int m=0; m < players.size(); m++){
                
                switch(selectedstrategies.at(m)){
                    case 1:{
                        //aggresive
                        AggressiveStrategy aggressive;
                        players[m]->setStrategy(&aggressive);
                        break;
                    }
                    case 2:{
                        //benevolent
                        BenevolentStrategy benevolent;
                        players[m]->setStrategy(&benevolent);
                        break;
                    }
                    case 3:{
                        //cheater
                        CheaterStrategy cheater;
                        players[m]->setStrategy(&cheater);
                        break;
                    }
                    case 4:{
                        //random
                        RandomStrategy random;
                        players[m]->setStrategy(&random);
                        break;
                    }
                }
            }
            
            //initialize views
            MainGame mainGame = MainGame(gameMap, players, deck);
            GameStatView gameStatView(gameMap, players);
            PhaseView phaseView;
            
            //set observers
            for(int i = 0; i < players.size(); ++i) {
                players[i]->addObserver(&gameStatView);
            }
            mainGame.addObserver(&phaseView);
            //for THIS NUMBER OF TURNS
            mainGame.playGame(numturns);
            //INCREMENT COUNTER FOR NUMBER OF TURNS
            
            if(mainGame.getWinner() != NULL){
                winners.push_back(printStrategy(mainGame.getWinner()->getStrategy()));
                cout << "************* WINNER! " << printStrategy(mainGame.getWinner()->getStrategy()) << "*************";
            }
            if(mainGame.getWinner()== NULL){
                winners.push_back("DRAW");
                cout << "************* DRAW! *************" << endl;
            }
            
            //delete all objects
            cleanup(players, gameMap, deck);
        }
        //print all stats
        print();
        winners.clear();
    }
}

//Free memory used in the old game
void Tournament::cleanup(vector<Player*> players, GameMap* gameMap, Deck* deck) {
    for(int i = 0; i < players.size(); ++i) {
        delete players[i];
    }
    delete gameMap;
    delete deck;
    
}

//final print of 
void Tournament::printheader(){
    //output selected maps
    
    cout << "\nMaps:";
    for(vector<string>::const_iterator i = selectedmaps.begin(); i != selectedmaps.end(); ++i){
        extractFileName(*i);
    }
    //output selected players
    cout << "\nPlayers:";
    
    for(int i=0; i < selectedstrategies.size(); i++){
        switch(selectedstrategies.at(i)){
            case 1:{
                cout << "Agressive, ";
                break;
            }
            case 2:{
                //benevolent
                cout << "Benevolent, ";
                break;
            }
            case 3:{
                //cheater
                cout << "Cheater, ";
                break;
            }
            case 4:{
                //random
                cout << "Random, ";
                break;
            }
        }
    }
    
    cout << "\nGames:" << numgames;
    cout << "\nTurns:" << numturns;
}

// make a vector of size (# games) that stores "winner"
void Tournament::printcolumns(){
    cout << endl << endl;
    cout << "                  ";
    for(int i=1; i <= numgames; i++){
        cout << "Game " << i << "           ";
    }
    cout << endl;
    //top row for "games"
    for(vector<string>::const_iterator i = selectedmaps.begin(); i != selectedmaps.end(); ++i){
        extractFileName(*i);
        cout << "      ";
        //for each game, print winner.
        for (vector<string>::const_iterator it= winners.begin(); it !=winners.end(); it++){
            cout << *it <<"             ";
        }
        
        cout << endl;
    }
}

void Tournament::extractFileName(const string& fullPath)
{
    const size_t lastSlashIndex = fullPath.find_last_of("/\\");
    cout << fullPath.substr(lastSlashIndex + 1) << ", ";
}


void Tournament::print(){
    printheader();
    printcolumns();
}

void Tournament::startTournament(string directory){
    inputmaps(directory);
    selectstrategies();
    selectnumgames();
    selectnumturns();
    tournamentloop(directory);
}

void Tournament::startSingleGame(string directory){
    Maploader mymaploader;
    printDirectory(directory);
    GameMap* gameMap = mymaploader.readmapfile(selectMap(directory), directory);
    GameStart game;
    //create game deck of cards
    Deck* deck =game.createDeck(gameMap);
    //player input
    int numberOfPlayers = game.selectPlayers();
    //create player objects with hand of empty cards and dice facilities
    vector<Player*> players = game.createPlayers(numberOfPlayers, gameMap);
    MainGame* mainGame = new MainGame(gameMap, players, deck);
    GameStatView* statsView= new GameStatView(gameMap,players);
    mainGame->addObserver(statsView);
    game.addPlayerObservers(statsView);
    mainGame->playGame();
}

string Tournament::printStrategy(Strategy* strategy){
    switch(strategy->getType()){
        case 0:
            return "Human";
            
        case 1:
            return "Aggresive";
            
            
        case 2:
           return "Benevolent";
            
        case 3:
            return "Random";
            
        case 4:
            return "Cheater";
        
    }
    return "bad_value";
};
