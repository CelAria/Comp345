#pragma once

#include <string>
using namespace std;

class Continent {
    public:
    Continent();
    Continent(string name, int points);
    string name;
    int points;
};