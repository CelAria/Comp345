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
    int getCount() { return (int)countries.size(); };
    void addContinent(Continent continent) { continents[continent.name] = continent; };
    void addCountry(string countryName, string continentName, vector<string> neighborNames);
    Country* getCountry(string countryName) { return countries[countryName]; };
    vector<Country*> getAllByContinent(string continentName);
    Continent getContinent(string name) { return continents[name]; };
    int traverseAll(bool isDebug);
    int traverseContinent(string continent, bool isDebug);
    bool isValid();
};
