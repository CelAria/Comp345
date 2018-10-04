#include "continent.h"
#include <string>

using namespace std;

Continent::Continent() {
    this->name = "";
    this->points = 0;
}

Continent::Continent(string name, int points) {
    this->name = name;
    this->points = points;
}