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
    //todo: store Player* (owner) pointer
    int armiesCount;
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
    void traverse(Country* country, map<string, bool> &visited);
    void continentTraverse(Country* country, map<string, bool> &visited, string continent);

    public:
    int getCount();
    void addContinent(Continent continent);
    void addCountry(string countryName, string continentName, vector<string> neighborNames);
    Country* getCountry(string countryName);
    vector<Country*> getAllByContinent(string continentName);
    Continent getContinent(string name);
    void traverseAll(string startingCountry);
    void traverseContinent(string startingCountry, string continent);
};