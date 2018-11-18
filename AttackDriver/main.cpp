//
//  main.cpp
//  AttackDriver
//
//  Created by Matthew Salaciak 29644490
//  ASSIGNMENT #2
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "attackphase.h"
#include "strategy.h"




using namespace std;

//mock game, creates 2 players, assigns them countries and armies on countries
//tests functions to make sure enemy neighbours are correct, amount of armies are correct, and transfer of country after winning is correct
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
    gameMap->getCountry("Colombia")->setArmiesCount(4);
    gameMap->getCountry("Panama")->setArmiesCount(2);
    gameMap->getCountry("Nicaragua")->setArmiesCount(2);

    player->addCountry(gameMap->getCountry("Costa Rica"));
    player->addCountry(gameMap->getCountry("Colombia"));
    player->addCountry(gameMap->getCountry("Nicaragua"));
    
    player2->addCountry(gameMap->getCountry("Venezuela"));
    player2->addCountry(gameMap->getCountry("Panama"));
    
}

int main(int argc, const char * argv[]) {

    //creates 2 players with player ID's
    //creates gamemap and attackphase class
    Strategy* strategy(new AggressiveStrategy);
    Player player(1);
    Player player2(2,strategy);
    GameMap gameMap;
    AttackPhase attack(&player,&gameMap);
   
    
    
    
    
   
    
    //prints players ID just to check two players are playing
    cout << "Player #" << player.getPlayerId() << ":" << endl << endl;
    cout << "Player #" << player2.getPlayerId() << ":" << endl << endl;
    
    //creates the mockup test game
    initMockGameMapAndPlayer(&gameMap, &player, &player2);
    

    //calls attack loop
//    attack.attackLoop();
    player.attack(&gameMap);
    player2.attack(&gameMap);
    

    
    return 0;
}
