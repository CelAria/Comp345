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

public:
    
static void readmapfile(); 
static void parser(ifstream mystream);
    
/* void tokenizeTerritories(const string& str, vector<string>& tokens);
void tokenizeContinents(const string& str, vector<string>& tokens, const string& delimiters = "=");
 */
};
