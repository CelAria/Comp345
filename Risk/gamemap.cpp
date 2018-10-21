#include "gamemap.h"
#include "country.h"
#include "continent.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/**
 Return a vector of all countries belonging to a given continent
 */
vector<Country*> GameMap::getAllByContinent(string continentName) {
    vector<Country*> byContinent;
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        if(it->second->getContinentName() == continentName) {
            byContinent.push_back(it->second);
        }
    }
    return byContinent;
}

/*
 Creates an edge in the graph between two countries
 */
void GameMap::addEdge(Country &fromCountry, Country &toCountry) {
    fromCountry.addNeighbor(toCountry);
    toCountry.addNeighbor(fromCountry);
}

/*
 Create edges from one given country to all the other neighboring countries
 */
void GameMap::addAll(Country &fromCountry, vector<string> &neighborNames) {
    for(int i = 0; i < neighborNames.size(); ++i) {
        Country* neighborPointer = getCountry(neighborNames[i]);
        if(neighborPointer != nullptr) {
            addEdge(fromCountry, *neighborPointer);
        }
    }
}

/**
 Add a country to the graph
 */
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

/**
 Performs a depth-first-search traversal of the graph and return the number
 of nodes visited
 */
int GameMap::traverseAll(bool isDebug = false) {
    map<string, bool> visited;
    
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        visited[it->first] = false;
    }

    int count = 0;
    srand(time(NULL));
    map<string, Country*>::iterator it = countries.begin();
    if(it->second != NULL) {
        traverseHelper(it->second, visited, count, isDebug);
    }

    return count;
}

void GameMap::traverseHelper(Country* country, map<string, bool> &visited, int &count, bool isDebug = false) {
    
    visited[country->getName()] = true;
    count++;
    vector<Country*> neighbors = country->getAllNeighbors();

    if(isDebug) {
        cout << "[ P" << country->getOwner() << ": " << country->getName() << ", " << country->getContinentName() << " (" << country->getArmiesCount() << " Armies) ]\t---> " << endl;
        
        for(int i = 0; i < neighbors.size(); i++) {
            cout << "{ P" << neighbors[i]->getOwner() << ": " << neighbors[i]->getName() << ", " << neighbors[i]->getContinentName() << " (" << neighbors[i]->getArmiesCount() << " Armies) }  ";
        }
        
        cout << endl << endl;
    }

    for(int i = 0; i < neighbors.size(); i++) {
        if(!visited[neighbors[i]->getName()]) {
            traverseHelper(neighbors[i], visited, count, isDebug);
        }
    }
}

/**
 Perform a depth-first-search traversal of a continent subgraph
 */
int GameMap::traverseContinent(string continent, bool isDebug = false) {
    map<string, bool> visited;
    
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        visited[it->first] = false;
    }

    int count = 0;
    Country* startingCountry = getAllByContinent(continent)[0];
    continentTraverseHelper(startingCountry, visited, continent, count, isDebug);

    return count;
}

void GameMap::continentTraverseHelper(Country* country, map<string, bool> &visited, string continent, int &count, bool isDebug) {
    
    visited[country->getName()] = true;
    count++;
    vector<Country*> neighbors = country->getAllNeighbors();

    if(isDebug) {
        cout << "[ P" << country->getOwner() << ": " << country->getName() << ", " << country->getContinentName() << " (" << country->getArmiesCount() << " Armies) ]\t---> " << endl;
        
        for(int i = 0; i < neighbors.size(); i++) {
            cout << "{ P" << neighbors[i]->getOwner() << ": " << neighbors[i]->getName() << ", " << neighbors[i]->getContinentName() << " (" << neighbors[i]->getArmiesCount() << " Armies) }  ";
        }
        
        cout << endl << endl;
    }

    for(int i = 0; i < neighbors.size(); i++) {
        if(!visited[neighbors[i]->getName()] && neighbors[i]->getContinentName() == continent) {
            continentTraverseHelper(neighbors[i], visited, continent, count, isDebug);
        }
    }
}

/**
 Return true if this map is a connected graph
 */
bool GameMap::isValid() {
    if(countries.size() > 0) {
        return traverseAll() == countries.size();
    }

    return false;
}
 
GameMap::~GameMap() {
    for(map<string, Country*>::iterator it = countries.begin(); it != countries.end(); it++) {
        delete it->second;
        it->second = NULL;
    }
}
