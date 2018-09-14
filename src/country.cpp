#include "country.h"
#include <set>
#include <vector>
using namespace std;

Country::Country(int id, int continentId) {
    this->id = id;
    this->continentId = continentId;
}

int Country::getId() {
    return id;
}

int Country::getContinentId() {
    return continentId;
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

bool Country::hasNext() {
    set<Country*>::iterator iterator;
    return iterator != neighbors.end();
}

Country Country::getNextNeighbor() {
    set<Country*>::iterator iterator = neighbors.begin();
    advance(iterator, iterationCount);
    return *(*iterator);
}