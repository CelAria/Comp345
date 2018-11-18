#include "country.h"
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include "player.h"
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

/**
 Return true if this country shares a border with another country
 */
bool Country::isNeighborOf(Country &country) {
    return neighbors.count(&country) != 0;
}

void Country::addNeighbor(Country &country) {
    neighbors.insert(&country);
}

/**
 Returns pointers to all the countries that share a border
 with this country
 */
vector<Country*> Country::getAllNeighbors() {
    vector<Country*> countries = vector<Country*>();
    for ( auto &country : neighbors ) {
        countries.push_back(country);
    }
    return countries;
}

string Country::toString() {
    stringstream str;
    str << this->getName() << ", " << this->getContinentName() << "\t(" << this->getArmiesCount() << " Armies)" << " [P" << this->getOwner()->getPlayerId() << "]";
    return str.str();
}

