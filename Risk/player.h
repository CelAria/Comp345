#pragma once

#include "cardsdeck.h"
#include "Dice.h"
#include "country.h"

#include <map>
#include <vector>
#include <string>
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
    int getPlayerId() { return id; };
    void addCountry(Country* country);
    int getCardsCount() { return hand.getTotalCardsInHand(); };
    void drawCard(Deck* deck);
    int rollDice(int amountOfDice);
    Hand getHand() { return hand; }
    int getCountriesCount() { return (int)countries.size(); }
    vector<Country*> getAllCountries();
    vector<Country*> getCountriesByContinent(string continent);
};
