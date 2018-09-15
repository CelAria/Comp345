#include "gamemap.h"
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

/*  Continent */

Continent::Continent(string name, int points) {
    this->name = name;
    this->points = points;
}

/* Country */

Country::Country(string countryName, string continentName) {
    this->name = countryName;
    this->continentName = continentName;
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
    map<string, Country*>::iterator countryIt = countries.find(countryName);
    if(countryIt != countries.end()) {
        return countryIt->second;
    } else {
        return nullptr;
    }
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
        Country country = Country(countryName, continentName);
        addAll(country, neighborNames);
    }
}

int GameMap::getCount() {
    return countries.size();
}