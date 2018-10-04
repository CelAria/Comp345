#include "gamemap.h"
#include "country.h"
#include "continent.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

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
 
