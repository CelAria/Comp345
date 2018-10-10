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
    string name;
    string line;
    istringstream mystream(string);
    string continents= "[Continents]";
    string territories= "[Territories]";
    string countryname;
    string continentname;

    
public:
    Maploader();
    ~Maploader();
    void readmapfile();
    void parser(string line);
    
/* void tokenizeTerritories(const string& str, vector<string>& tokens);
void tokenizeContinents(const string& str, vector<string>& tokens, const string& delimiters = "=");
 */
};
