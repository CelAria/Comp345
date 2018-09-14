#pragma once

#include <set>
#include <vector>
using namespace std;

class Country {
    private:
    int id;
    int continentId;
    int iterationCount;
    set<Country*> neighbors;

    public:
    Country(int id, int continentId);
    int getId();
    int getContinentId();
    bool hasNeighbors();
    bool isNeighborOf(Country &country);
    void addNeighbor(Country &neighbor);
    int getNeighborCount();
    bool hasNext();
    Country getNextNeighbor();
    vector<Country> getAllNeighbors();
};