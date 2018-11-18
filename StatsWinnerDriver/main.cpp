
#include "maploader.h"
#include "Dice.h"
#include "gamemap.h"
#include "viewgamestart.h"
#include "controllergamestart.h"
#include "gamestatview.h"
#include "maingame.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <math.h>

/* WHEN THE DRIVER ASKS FOR THE FILE, MUST PASTE THE ENTIRE FILE PATH*/

using namespace std;

int main(int argc, const char * argv[]) {
    

    
//    //Type in the full file path to the file you want to open
//
//    //example of "user input" style with terminal using filepaths
//    try
//    {
//    mymaploader.readmapfile();
//    cout << "read mapfile runs" << endl;
//    }
//    catch (runtime_error e)
//    {
//        cout << e.what() <<endl;
//    }
//
//    return 0;
    
    //directory where maps are stored
    const string directory = "/Users/celestepimm/git/Comp345-Xcode/MapLoaderDriver";
    //printMapDirectory(directory);
    
    //open map and test if valid, if valid, create map object
    
    Maploader mymaploader;
    mymaploader.printDirectory(directory);
    // mymaploader.selectMap(directory);
    
    //GameMap* gameMap = mymaploader.readmapfile(mymaploader.selectMap(directory), directory);
    GameMap* gameMap= new GameMap;
    Continent NA;
    vector<string> N2;
    vector<string> N1;
    N1.push_back("Canada");
    N2.push_back("USA");
    gameMap->addCountry("Canada", "NA", N2);
    gameMap->addCountry("USA", "NA", N1);
    Player* p1 = new Player();
    Player* p2 = new Player();
    vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);
    Country* Canada = new Country("Canada" ,"NA");
    Country* USA = new Country("USA", "NA");
    p1->addCountry(Canada);
    p2->addCountry(USA);
    Canada->addNeighbor(*USA);
    USA->addNeighbor(*Canada);
    
    vector<Country*> p1Countries = p1->getAllCountries();
    vector<Country*> p2Countries = p2->getAllCountries();
    p1Countries[0]->IncrementArmiesCount();
    p1Countries[0]->IncrementArmiesCount();
    p2Countries[0]->IncrementArmiesCount();
    
    
    GameStart game;
    //create game deck of cards
    Deck* deck =game.createDeck(gameMap);
    //player input
    //int numberOfPlayers = game.selectPlayers();
    //create player objects with hand of empty cards and dice facilities
    
    //vector<Player*> players = game.createPlayers(numberOfPlayers, gameMap);
    MainGame* main= new MainGame(gameMap, players, deck);
    GameStatView* gamestatview= new GameStatView(main);
    gamestatview->print();
    delete main;
    //players.at(1).
    MainGame* mainGame = new MainGame(gameMap, players, deck);
    GameStatView* statsView= new GameStatView(mainGame);
    mainGame->addObserver(statsView);
    mainGame->playGame();
    
    
}

