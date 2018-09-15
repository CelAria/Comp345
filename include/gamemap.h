#pragma once

#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Continent {
    Continent(string name, int points);
    string name;
    int points;
};

class Country {
    private:
    string name;
    string continentName;
    int iterationCount;
    //todo: store Player* (owner) pointer
    int armiesCount = 0;
    set<Country*> neighbors;

    public:
    Country(string countryName, string continentName);
    string getName();
    string getContinentName();
    bool hasNeighbors();
    bool isNeighborOf(Country &country);
    void addNeighbor(Country &neighbor);
    int getNeighborCount();
    int getArmiesCount();
    //todo: set owner Player*
    //todo: get owner Player
    void resetIterator();
    bool hasNext();
    Country getNextNeighbor();
    vector<Country> getAllNeighbors();
};

class GameMap {
    private:
    map<string, Country*> countries;
    map<string, Continent> continents;
    void addEdge(Country &fromCountry, Country &toCountry);
    void addAll(Country &fromCountry, vector<string> &neighborNames);

    public:
    int getCount();
    void addContinent(Continent continent);
    void addCountry(string countryName, string continentName, vector<string> neighborNames);
    Country* getCountry(string countryName);
    vector<Country*> getAllByContinent(string continentName);
    Continent getContinent(string name);
};