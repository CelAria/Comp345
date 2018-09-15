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

Country::Country(string countryName, string continentName) {
    this->name = countryName;
    this->continentName = continentName;
    armiesCount = 0;
}

string Country::getName() {
    return name;
}

string Country::getContinentName() {
    return continentName;
}

bool Country::hasNeighbors() {
    return !neighbors.empty();
}

int Country::getNeighborCount() {
    return neighbors.size();
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

void Country::resetIterator() {
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

Continent GameMap::getContinent(string name) {
    return continents[name];
}

Country* GameMap::getCountry(string countryName) {
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

int GameMap::getCount() {
    return countries.size();
}

void GameMap::traverseAll(string startingCountry) {
    map<string, bool> visited;
    
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        visited[it->first] = false;
    }

    traverse(countries[startingCountry], visited);
}

void GameMap::traverse(Country* country, map<string, bool> &visited) {
    visited[country->getName()] = true;

    cout << "Country: " << country->getName() << ", Continent: " << country->getContinentName() << " with " << country->getNeighborCount() << " neighbors:\n";
    vector<Country> neighbors = country->getAllNeighbors();
    for(int i = 0; i < neighbors.size(); i++) {
        cout << neighbors[i].getName() << "\n";
    }
    cout << "\n------------------------------\n";

    for(int i = 0; i < neighbors.size(); i++) {
        if(!visited[neighbors[i].getName()]) {
            traverse(&neighbors[i], visited);
        }
    }
}

/*  Free functions  */

 int main(int argc, char const *argv[])
 {

     cout << "Testing map \n";

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

    cout << gameMap.getCount() << " countries\n";
    cout << "Starting DFS traversal of graph: \n";

    gameMap.traverseAll("Nicaragua"); 

     return 0;
 }
 