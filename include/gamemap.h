#pragma once

#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Continent {
    public:
    Continent();
    Continent(string name, int points);
    string name;
    int points;
};

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

class GameMap {
    private:
    map<string, Country*> countries;
    map<string, Continent> continents;
    void addEdge(Country &fromCountry, Country &toCountry);
    void addAll(Country &fromCountry, vector<string> &neighborNames);
    void traverseHelper(Country* country, map<string, bool> &visited, bool isDebug);
    void continentTraverseHelper(Country* country, map<string, bool> &visited, string continent, bool isDebug);

    public:
    int getCount();
    void addContinent(Continent continent);
    void addCountry(string countryName, string continentName, vector<string> neighborNames);
    Country* getCountry(string countryName);
    vector<Country*> getAllByContinent(string continentName);
    Continent getContinent(string name);
    int traverseAll(string startingCountry, bool isDebug);
    int traverseContinent(string startingCountry, string continent, bool isDebug);
    bool isValid();
};