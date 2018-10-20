//
//  main.cpp
//  FortifyControllerDriver
//
//  Created by Allan Pichardo on 10/19/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "fortifycontroller.h"
#include "Dice.h"
#include "cardsdeck.h"
#include "continent.h"
#include "fortifyview.h"
#include "player.h"
#include "gamemap.h"
#include "country.h"

using namespace std;

void initMockGameMap(GameMap* gameMap) {
    Continent centralAmerica = Continent("Central America", 3);
    Continent southAmerica = Continent("South America", 2);
    
    gameMap->addContinent(centralAmerica);
    gameMap->addContinent(southAmerica);
    
    vector<string> nicNeighbors;
    nicNeighbors.push_back("Costa Rica");
    gameMap->addCountry("Nicaragua", "Central America", nicNeighbors);
    
    vector<string> cosNeighbors;
    cosNeighbors.push_back("Nicaragua");
    cosNeighbors.push_back("Panama");
    gameMap->addCountry("Costa Rica", "Central America", cosNeighbors);
    
    vector<string> panNeighbors;
    panNeighbors.push_back("Costa Rica");
    panNeighbors.push_back("Colombia");
    gameMap->addCountry("Panama", "Central America", panNeighbors);
    
    vector<string> colNeighbors;
    colNeighbors.push_back("Panama");
    colNeighbors.push_back("Venezuela");
    gameMap->addCountry("Colombia", "South America", colNeighbors);
    
    vector<string> venNeighbors;
    venNeighbors.push_back("Colombia");
    gameMap->addCountry("Venezuela", "South America", venNeighbors);
}

int main(int argc, const char * argv[]) {
    
    Player player;
    Deck deck = Deck();
    GameMap gameMap;
    
    initMockGameMap(&gameMap);
    
    FortifyView view = FortifyView(&player);
    
    view.showCountrySelectList(gameMap.getAllByContinent("Central America"));
}


