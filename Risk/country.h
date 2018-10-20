#pragma once

#include <set>
#include <string>
#include <vector>
using namespace std;

/**
 Represents a node in the GameMap graph
 */
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
    string getName() {return name;};
    string getContinentName() {return continentName;};
    bool hasNeighbors(){ return !neighbors.empty(); };
    bool isNeighborOf(Country &country);
    void addNeighbor(Country &neighbor);
    int getNeighborCount() { return (int)neighbors.size(); };
    int getArmiesCount() { return armiesCount; };
    void setOwner(int playerId) { this->playerId = playerId; };
    int getOwner() { return playerId; }
    void setArmiesCount(int count) { this->armiesCount = count; };
    vector<Country*> getAllNeighbors();
};
