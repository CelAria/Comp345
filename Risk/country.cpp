#include "country.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

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

void Country::setOwner(int playerId) {
    this->playerId = playerId;
}

void Country::setArmiesCount(int count) {
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