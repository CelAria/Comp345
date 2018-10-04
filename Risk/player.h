#pragma once

#include "cardsdeck.h"
#include "Dice.h"
#include "country.h"

#include <map>
using namespace std;

class Player {
private:
    int id;
    Hand hand;
    Dice dice;
    map<string, Country*> countries;
    
public:
    Player(): id(1), dice(1) {};
    Player(int playerId): id(playerId), dice(playerId) {};
    void attack();
    void fortify();
    void reinforce();
    int getPlayerId();
    void addCountry(Country* country);
    int getCardsCount();
    void drawCard(Deck* deck);
};
