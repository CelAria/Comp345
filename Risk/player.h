#pragma once

#include "cardsdeck.h"
#include "Dice.h"
#include "country.h"
#include "gamemap.h"
#include "strategy.h"
#include "HumanPlayerStrategy.h"
#include "aggressivestrategy.h"
#include "BenevolentStrategy.h"
#include "RandomStrategy.h"
#include "CheaterStrategy.h"
#include "observable.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Player : public Observable {
private:
    int id;
    Strategy* strategy;
    Hand* hand;
    Dice dice;
    map<string, Country*> countries;
    
    
public:
    Player(): id(1), dice(1), hand(new Hand), strategy(new HumanPlayerStrategy) {};
    Player(int playerId): id(playerId), dice(playerId), hand(new Hand), strategy(new HumanPlayerStrategy) {};
    Player(int playerId, Strategy* strategy): Player(playerId) {this->strategy = strategy;};
    void attack(GameMap* gameMap);
    void fortify(GameMap* gameMap);
    void reinforce(GameMap* gameMap);
    int getPlayerId() { return id; };
    void addCountry(Country* country);
    int getCardsCount() { return hand->getTotalCardsInHand(); };
    void drawCard(Deck* deck);
    //had to change this to fix dice container issue changed from int to void 
    void rollDice(int amountOfDice);
    void defendRollDice(int amountOfDice);
    void getDiceRollsAttack(int amountOfDice);
    void getDiceRollsDefend(int amountOfDice);
    Hand* getHand() { return hand; }
    int getCountriesCount() { return (int)countries.size(); }
    vector<Country*> getAllCountries();
    vector<Country*> getCountriesByContinent(string continent);
    bool controlsContinent(string name, GameMap* gameMap);
    
    inline int getAttackDice1() {return dice.getAttackDice1();}
    inline int getAttackDice2() {return dice.getAttackDice2();}
    inline int getAttackDice3() {return dice.getAttackDice3();}
    
    inline int getDefenseDice1() {return dice.getDefenseDice1();}
    inline int getDefenseDice2() {return dice.getDefenseDice2();}
    
    void transferCountryTo(string countryName, Player* player);
    Strategy* getStrategy() {return this->strategy;};
    void setStrategy(Strategy* strategy) {this->strategy = strategy;};
    
    void notifyObservers();
   
    ~Player() {delete hand;delete strategy;};
};
