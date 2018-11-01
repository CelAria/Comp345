//
//  main.cpp
//  AttackDriver
//
//  Created by Matthew Salaciak on 2018-10-30.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "attackphase.h"

using namespace std;


void initMockGameMapAndPlayer(GameMap* gameMap, Player* player, Player* player2) {
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
    gameMap->getCountry("Panama")->setArmiesCount(3);

    player->addCountry(gameMap->getCountry("Costa Rica"));
    player->addCountry(gameMap->getCountry("Venezuela"));
    player->addCountry(gameMap->getCountry("Colombia"));
    player2->addCountry(gameMap->getCountry("Panama"));
}

int main(int argc, const char * argv[]) {

    Player player(1);
    Player player2(2);
    GameMap gameMap;
    AttackPhase attack(&player,&gameMap);
    
    
    cout << "Player #" << player.getPlayerId() << ":" << endl << endl;
    cout << "Player #" << player2.getPlayerId() << ":" << endl << endl;
    
    initMockGameMapAndPlayer(&gameMap, &player, &player2);
    attack.attackLoop();
    
    
    
    

    
    
    
    
    
    return 0;
}
