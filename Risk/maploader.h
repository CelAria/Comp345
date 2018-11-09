#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include "gamemap.h"

using namespace std;

class Maploader{
private:
    string filename;
    ifstream fstream;
    vector<string> token;
    int points;
    string xcoord;
    string ycoord;
    string name;
    string line;
    string neighbor;
    vector<string> neighbors;
    istringstream mystream(string);
    string continents= "[Continents]\r";
    string territories= "[Territories]\r";
    string countryname;
    string continentname;
  
    
public:
    Maploader(){};
    ~Maploader(){};
    string selectMap(string directory);
    void printDirectory(string directory);
    GameMap* readmapfile(string file, string directory);
    void parser(string line);
    void parseContinent(string line);
    void parseTerritory(string line);
    GameMap* ptrgamemap;
    
};
