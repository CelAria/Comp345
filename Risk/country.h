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
    int stratType;
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
    void setStrat(int stratType) {this->stratType = stratType;};
    int getStrat(){return stratType;}
    void setArmiesCount(int count) { this->armiesCount = count; };
    void IncrementArmiesCount() {this->armiesCount++;}
    vector<Country*> getAllNeighbors();
    string toString();
};
