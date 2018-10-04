#pragma once

#include <set>
#include <string>
#include <vector>
using namespace std;

class Country {
    private:
    string name;
    string continentName;
    int iterationCount;
    int playerId;
    int armiesCount;
    set<Country*> neighbors;

    public:
    Country();
    Country(string countryName, string continentName);
    string getName();
    string getContinentName();
    bool hasNeighbors();
    bool isNeighborOf(Country &country);
    void addNeighbor(Country &neighbor);
    int getNeighborCount();
    int getArmiesCount();
    void setOwner(int playerId);
    void setArmiesCount(int count);
    void resetIterator();
    bool hasNext();
    Country getNextNeighbor();
    vector<Country> getAllNeighbors();
};