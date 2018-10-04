//
//  main.cpp
//  GameMapDriver
//
//  Created by Allan Pichardo on 10/3/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

#include "continent.h"
#include "country.h"
#include "gamemap.h"
#include "Dice.h"

int main(int argc, const char * argv[]) {
    
    cout << "Testing map: " << endl << endl;;
    
    Continent centralAmerica = Continent("Central America", 3);
    Continent southAmerica = Continent("South America", 2);
    
    GameMap gameMap;
    
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
    
    cout << "Created " << gameMap.getCount() << " countries" << endl;
    cout << "Expecting traversal of graph to visit " << gameMap.getCount() << " nodes" << endl << endl;
    cout << "Starting full DFS traversal:" << endl << endl;
    
    int countriesVisited = gameMap.traverseAll("Costa Rica", true);
    
    cout << endl << "Actual visited nodes: " << countriesVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (countriesVisited == gameMap.getCount()) << endl << endl;
    
    cout << "Expecting traversal of Central America to visit 3 countries." << endl;
    cout << "Starting continent DFS traversal of subgraph for Central America: " << endl << endl;
    
    int centralVisited = gameMap.traverseContinent("Panama", "Central America", true);
    
    cout << endl << "Actual visited nodes: " << centralVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (centralVisited == 3) << endl << endl;
    
    cout << "Expecting traversal of South America to visit 2 countries." << endl;
    cout << "Starting continent DFS traversal of subgraph for South America: " << endl << endl;
    
    int southVisited = gameMap.traverseContinent("Venezuela", "South America", true);
    
    cout << endl << "Actual visited nodes: " << southVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (southVisited == 2) << endl << endl;
    
    cout << "Finished testing map." << endl << endl;
    
    return 0;
}
