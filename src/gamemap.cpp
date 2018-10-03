#include "gamemap.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/*  Continent */

Continent::Continent() {
    this->name = "";
    this->points = 0;
}

Continent::Continent(string name, int points) {
    this->name = name;
    this->points = points;
}

/* Country */

Country::Country() {
    name = "";
    continentName = "";
    armiesCount = 0;
}

Country::Country(string countryName, string continentName) {
    this->name = countryName;
    this->continentName = continentName;
    armiesCount = 0;
}

inline string Country::getName() {
    return name;
}

inline string Country::getContinentName() {
    return continentName;
}

inline bool Country::hasNeighbors() {
    return !neighbors.empty();
}

inline int Country::getNeighborCount() {
    return neighbors.size();
}

inline void Country::setOwner(int playerId) {
    this->playerId = playerId;
}

inline void Country::setArmiesCount(int count) {
    this->armiesCount = count;
}

bool Country::isNeighborOf(Country &country) {
    return neighbors.count(&country) != 0;
}

void Country::addNeighbor(Country &country) {
    neighbors.insert(&country);
}

vector<Country> Country::getAllNeighbors() {
    vector<Country> countries = vector<Country>();
    for ( auto &country : neighbors ) {
        countries.push_back(*country);
    }

    return countries;
}

inline void Country::resetIterator() {
    iterationCount = 0;
}

bool Country::hasNext() {
    set<Country*>::iterator iterator;
    return iterator != neighbors.end();
}

Country Country::getNextNeighbor() {
    set<Country*>::iterator iterator = neighbors.begin();
    advance(iterator, iterationCount);
    iterationCount++;
    return *(*iterator);
}

/*  GameMap */

void GameMap::addContinent(Continent continent) {
    continents[continent.name] = continent;
}

inline Continent GameMap::getContinent(string name) {
    return continents[name];
}

inline Country* GameMap::getCountry(string countryName) {
    return countries[countryName];
}

vector<Country*> GameMap::getAllByContinent(string continentName) {
    vector<Country*> byContinent;
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        if(it->second->getContinentName() == continentName) {
            byContinent.push_back(it->second);
        }
    }
    return byContinent;
}

void GameMap::addEdge(Country &fromCountry, Country &toCountry) {
    fromCountry.addNeighbor(toCountry);
    toCountry.addNeighbor(fromCountry);
}

void GameMap::addAll(Country &fromCountry, vector<string> &neighborNames) {
    for(int i = 0; i < neighborNames.size(); ++i) {
        Country* neighborPointer = getCountry(neighborNames[i]);
        if(neighborPointer != nullptr) {
            addEdge(fromCountry, *neighborPointer);
        }
    }
}

void GameMap::addCountry(string countryName, string continentName, vector<string> neighborNames) {
    Country* countryPointer = getCountry(countryName);
    if(countryPointer != nullptr) {
        addAll(*countryPointer, neighborNames);
    } else {
        Country* country = new Country(countryName, continentName);
        countries[countryName] = country;
        addAll(*country, neighborNames);
    }
}

inline int GameMap::getCount() {
    return countries.size();
}

int GameMap::traverseAll(string startingCountry, bool isDebug = false) {
    map<string, bool> visited;
    
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        visited[it->first] = false;
    }

    int count = 0;
    traverseHelper(countries[startingCountry], visited, count, isDebug);

    return count;
}

void GameMap::traverseHelper(Country* country, map<string, bool> &visited, int &count, bool isDebug = false) {
    
    visited[country->getName()] = true;
    count++;
    vector<Country> neighbors = country->getAllNeighbors();

    if(isDebug) {
        cout << "Country " << count << ": " << country->getName() << ", Continent: " << country->getContinentName() << " with " << country->getNeighborCount() << " neighbors:\n";

        for(int i = 0; i < neighbors.size(); i++) {
            cout << neighbors[i].getName() << "\n";
        }

        cout << "------------------------------\n";
    }

    for(int i = 0; i < neighbors.size(); i++) {
        if(!visited[neighbors[i].getName()]) {
            traverseHelper(&neighbors[i], visited, count, isDebug);
        }
    }
}

int GameMap::traverseContinent(string startingCountry, string continent, bool isDebug = false) {
    map<string, bool> visited;
    
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        visited[it->first] = false;
    }

    int count = 0;
    continentTraverseHelper(countries[startingCountry], visited, continent, count, isDebug);

    return count;
}

void GameMap::continentTraverseHelper(Country* country, map<string, bool> &visited, string continent, int &count, bool isDebug) {
    
    visited[country->getName()] = true;
    count++;
    vector<Country> neighbors = country->getAllNeighbors();

    if(isDebug) {
        cout << "Country " << count << ": " << country->getName() << ", Continent: " << country->getContinentName() << " with " << country->getNeighborCount() << " neighbors:\n";
    
        for(int i = 0; i < neighbors.size(); i++) {
            cout << neighbors[i].getName() << "\n";
        }
        cout << "------------------------------\n";
    }

    for(int i = 0; i < neighbors.size(); i++) {
        if(!visited[neighbors[i].getName()] && neighbors[i].getContinentName() == continent) {
            continentTraverseHelper(&neighbors[i], visited, continent, count, isDebug);
        }
    }
}

bool GameMap::isValid() {
    if(countries.size() > 0) {
        map<string, Country*>::iterator it = countries.begin();
        return traverseAll(it->first) == countries.size();
    }

    return false;
}

/*  Free functions  */

 int main(int argc, char const *argv[])
 {

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

     return 0;
 }
 