//
//  main.cpp
//  ReinforceDriver
//
//  Created by Martin-John Hearty on 2018-10-31.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "gamemap.h"
#include "cardsdeck.h"
#include "maploader.h"


int main(int argc, const char * argv[]) {
    Player player;
    GameMap gameMap;
    Deck deck = Deck(42);
    //Maploader mymaoloader;
    //mymaoloader.readmapfile("/Users/martin-john/Documents/Comp345/MapLoaderDriver/World.map");
    Continent centralAmerica = Continent("Central America", 3);
    Continent southAmerica = Continent("South America", 2);
    
    gameMap.addContinent(centralAmerica);
    gameMap.addContinent(southAmerica);
    
    vector<string> nicNeighbors;
    nicNeighbors.push_back("Costa Rica");
    gameMap.addCountry("Nicaragua", "Central America", nicNeighbors);
    
    vector<string> cosNeighbors;
    cosNeighbors.push_back("Nicaragua");
    cosNeighbors.push_back("Panama");
    gameMap.addCountry("Costa Rica", "Central America", cosNeighbors);
    
    vector<string> panNeighbors;
    panNeighbors.push_back("Costa Rica");
    panNeighbors.push_back("Colombia");
    gameMap.addCountry("Panama", "Central America", panNeighbors);
    
    vector<string> colNeighbors;
    colNeighbors.push_back("Panama");
    colNeighbors.push_back("Venezuela");
    gameMap.addCountry("Colombia", "South America", colNeighbors);
    
    vector<string> venNeighbors;
    venNeighbors.push_back("Colombia");
    gameMap.addCountry("Venezuela", "South America", venNeighbors);
    
    gameMap.getCountry("Costa Rica")->setArmiesCount(2);
    gameMap.getCountry("Venezuela")->setArmiesCount(4);
    gameMap.getCountry("Colombia")->setArmiesCount(1);
    
    player.addCountry(gameMap.getCountry("Costa Rica"));
    player.addCountry(gameMap.getCountry("Venezuela"));
    player.addCountry(gameMap.getCountry("Colombia"));
  
    cout << endl;
    cout << "Player now has " << player.getCountriesCount() << " countries." << endl;
    vector<Country*> allCountries = player.getAllCountries();
    for(int i = 0; i < allCountries.size(); i++) {
        cout << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;
    
    for(int i=0; i< 6; ++i)
    {
        player.drawCard(&deck);
    }
    
     player.reinforce(&gameMap);
    
    
    return 0;
}
