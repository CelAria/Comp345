//
//  main.cpp
//  FortifyControllerDriver
//
//  Created by Allan Pichardo on 10/19/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include <stdio.h>
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

void initMockGameMapAndPlayer(GameMap* gameMap, Player* player) {
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
    
    gameMap->getCountry("Costa Rica")->setArmiesCount(2);
    gameMap->getCountry("Venezuela")->setArmiesCount(4);
    gameMap->getCountry("Colombia")->setArmiesCount(1);
    
    player->addCountry(gameMap->getCountry("Costa Rica"));
    player->addCountry(gameMap->getCountry("Venezuela"));
    player->addCountry(gameMap->getCountry("Colombia"));
}

int main(int argc, const char * argv[]) {
    
    Player player;
    Deck deck = Deck();
    GameMap gameMap;
    
    initMockGameMapAndPlayer(&gameMap, &player);
    
    FortifyController controller = FortifyController(&player, &gameMap);
    
    controller.start();
    
    cout << "Result:" << endl << endl;
    
    vector<Country*> cs = player.getAllCountries();
    for(int i = 0; i < cs.size(); ++i) {
        cout << cs[i]->toString() << endl;
    }
    
    return 0;
}


