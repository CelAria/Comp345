//
//  main.cpp
//  AttackDriver
//
//  Created by Matthew Salaciak 29644490
//  ASSIGNMENT #3
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "attackphase.h"
#include "strategy.h"




using namespace std;

//mock game, creates 3 players, assigns them countries and armies on countries
//tests players strategies
//tests functions to make sure enemy neighbours are correct, amount of armies are correct, and transfer of country after winning is correct
void initMockGameMapAndPlayer(GameMap* gameMap, Player* player, Player* player2, Player* player3,Player* player4) {
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

    gameMap->getCountry("Costa Rica")->setArmiesCount(3);
    gameMap->getCountry("Venezuela")->setArmiesCount(4);
    gameMap->getCountry("Colombia")->setArmiesCount(4);
    gameMap->getCountry("Panama")->setArmiesCount(5);
    gameMap->getCountry("Nicaragua")->setArmiesCount(3);

    player->addCountry(gameMap->getCountry("Costa Rica"));
    player2->addCountry(gameMap->getCountry("Colombia"));

    player2->addCountry(gameMap->getCountry("Nicaragua"));
    player3->addCountry(gameMap->getCountry("Panama"));
    player4->addCountry(gameMap->getCountry("Venezuela"));
    
}

int main(int argc, const char * argv[]) {

    //creates 3 players with player ID's and strategies
    //creates gamemap, strategy and attackphase class
    
    Strategy* strategyCheater(new CheaterStrategy);
    Strategy* strategyBenevolent(new BenevolentStrategy);
    Strategy* strategyAgressive(new AggressiveStrategy);
    Strategy* strategyRandom(new RandomStrategy);

    Player player(1,strategyCheater);
    Player player2(2,strategyRandom);
    Player player3(3,strategyBenevolent);
    Player player4(4,strategyAgressive);
    GameMap gameMap;
    AttackPhase attack(&player,&gameMap);
   
 
    
    //prints players ID just to check 3 players are playing
    cout << "Player #" << player.getPlayerId() << " : Cheater" << endl << endl;
    cout << "Player #" << player2.getPlayerId() << " : Random" << endl << endl;
    cout << "Player #" << player3.getPlayerId() << " : Benevolent" << endl << endl;
    cout << "Player #" << player4.getPlayerId() << " : Agressive" << endl << endl;

    
    //creates the mockup test game
    initMockGameMapAndPlayer(&gameMap, &player, &player2,&player3,&player4);
    

    //calls attack loop for human, benevolent and agressive strategy

    player.attack(&gameMap);

    player2.attack(&gameMap);
    player3.attack(&gameMap);
   
    
    
    player4.attack(&gameMap);
  
    

    
    return 0;
}
