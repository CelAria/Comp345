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
    vector<string> token;
    int points;
    string name;
    string line;
    istringstream mystream(string);
    string continents= "[Continents]";
    string territories= "[Territories]";
    
public:
    
    static void readmapfile();
    static void parser(ifstream mystream);
    
/* void tokenizeTerritories(const string& str, vector<string>& tokens);
void tokenizeContinents(const string& str, vector<string>& tokens, const string& delimiters = "=");
 */
};
