#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

class Maploader{
private:
    string filename;
    ifstream fstream;
    vector<string> token;
    int points;
    int xcoord;
    int ycoord;
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
    void readmapfile();
    void parser(string line);
    void parseContinent(string line);
    void parseTerritory(string line);
};
