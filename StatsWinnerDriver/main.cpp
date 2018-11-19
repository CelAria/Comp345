
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
  
    Maploader mymaploader;
    GameMap* gameMap= new GameMap;
    Continent NA = Continent("NA", 2);
    gameMap->addContinent(NA);
    
    vector<string> N2;
    vector<string> N1;
    N1.push_back("Canada");
    N2.push_back("USA");
    gameMap->addCountry("Canada", "NA", N2);
    gameMap->addCountry("USA", "NA", N1);
    gameMap->getCountry("Canada")->setArmiesCount(1);
    gameMap->getCountry("USA")->setArmiesCount(20);
    
    vector<Player*> players;
    Player* p1 = new Player(1);
    Player* p2 = new Player(2);
    players.push_back(p1);
    players.push_back(p2);
    p1->addCountry(gameMap->getCountry("Canada"));
    p1->addCountry(gameMap->getCountry("USA"));
    
    vector<Country*> p1Countries = p1->getAllCountries();
    vector<Country*> p2Countries = p2->getAllCountries();

    GameStart game;
    //create game deck of cards
    Deck* deck =game.createDeck(gameMap);

    MainGame* mainGame = new MainGame(gameMap, players, deck);
    GameStatView* statsView= new GameStatView(gameMap, players);
    mainGame->addObserver(statsView);
    p1->addObserver(statsView);
    p2->addObserver(statsView);
    mainGame->playGame();
    
}

