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
    
    cout << "Testing valid map________________ " << endl << endl;;
    
    /*
     We create 5 countries in 2 continents and add them
     to the GameMap
     */
    
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
    
    /*
     Traverse the graph. If the graph is connected, then we should
     visit all 5 countries
     */
    
    cout << "Created " << gameMap.getCount() << " countries" << endl;
    cout << "Expecting traversal of graph to visit " << gameMap.getCount() << " nodes" << endl << endl;
    cout << "Starting full DFS traversal:" << endl << endl;
    
    int countriesVisited = gameMap.traverseAll(true);
    
    cout << endl << "Actual visited nodes: " << countriesVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (countriesVisited == gameMap.getCount()) << endl << endl;
    
    /*
     Traversing only an individual continent
     */
    
    cout << "Expecting traversal of Central America to visit 3 countries." << endl;
    cout << "Starting continent DFS traversal of subgraph for Central America: " << endl << endl;
    
    int centralVisited = gameMap.traverseContinent("Central America", true);
    
    cout << endl << "Actual visited nodes: " << centralVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (centralVisited == 3) << endl << endl;
    
    cout << "Expecting traversal of South America to visit 2 countries." << endl;
    cout << "Starting continent DFS traversal of subgraph for South America: " << endl << endl;
    
    int southVisited = gameMap.traverseContinent("South America", true);
    
    cout << endl << "Actual visited nodes: " << southVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (southVisited == 2) << endl << endl;
    
    /*
     If we reassign a country with a different continent, it will
     be ignored since continent assignment can only occur once.
     */
    
    cout << "Testing duplication of continent____________________" << endl << endl;
    
    gameMap.addCountry("Venezuela", "Australia", venNeighbors);
    
    cout << "Starting full DFS traversal:" << endl << endl;
    
    countriesVisited = gameMap.traverseAll(true);
    
    cout << endl << "Actual visited nodes: " << countriesVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << (countriesVisited == gameMap.getCount()) << endl << endl;
    
    /*
     Adding a country that has no adjacent edges will break the
     connection of the graph. Traversing the graph should visit
     less than 6 countries
     */
    
    cout << "Testing invalid map__________________" << endl << endl;
    
    cout << "Adding 1 unconnected country..." << endl;
    
    gameMap.addCountry("Australia", "Australia", {});
    
    cout << "Map now cointains " << gameMap.getCount() << " nodes" << endl;
    cout << "Expecting DFS traversal of graph to visit 5 nodes..." << endl << endl;
    
    int ausVisited = gameMap.traverseAll(true);
    
    cout << endl << "Actual visited nodes: " << ausVisited << endl;
    cout << "Connected graph (1 = yes / 0 = no): " << gameMap.isValid() << endl << endl;
    
    
    cout << "Finished testing map." << endl << endl;
    
    return 0;
}
