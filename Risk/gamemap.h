#pragma once

#include "country.h"
#include "continent.h"
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

class GameMap {
    private:
    map<string, Country*> countries;
    map<string, Continent> continents;
    void addEdge(Country &fromCountry, Country &toCountry);
    void addAll(Country &fromCountry, vector<string> &neighborNames);
    void traverseHelper(Country* country, map<string, bool> &visited, int &count, bool isDebug);
    void continentTraverseHelper(Country* country, map<string, bool> &visited, string continent, int &count, bool isDebug);

    public:
    ~GameMap();
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
