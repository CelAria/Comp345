#pragma once

#include "cardsdeck.h"
#include "Dice.h"
#include "country.h"

#include <map>
#include <set>
using namespace std;

class Player {
private:
    int id;
    Hand hand;
    Dice dice;
    set<string, Country*> countries;
    
public:
    Player();
    Player(int playerId): id(playerId), dice(playerId) {}
    void attack();
    void fortify();
    void reinforce();
};
