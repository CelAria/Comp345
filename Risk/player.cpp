#include "player.h"
#include "cardsdeck.h"
#include "country.h"
#include "gamemap.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void Player::attack(GameMap *gameMap) {
    strategy->attack(this, gameMap);
}

void Player::fortify(GameMap* gameMap) {
    strategy->fortify(this, gameMap);
}

void Player::reinforce(GameMap* gameMap) {
    strategy->reinforce(this, gameMap);
}

void Player::addCountry(Country *country) {
    country->setOwner(id);
    country->setStrat(strategy->getType());
    countries[country->getName()] = country;
    
}


void Player::drawCard(Deck* deck) {
    deck->draw(hand);
}

void Player::rollDice(int amountOfDice) {
    dice.rollDice(amountOfDice);
}

void Player::defendRollDice(int amountOfDice) {
    dice.defendRollDice(amountOfDice);
}

void Player:: getDiceRollsAttack(int amountOfDice){
    dice.getDiceValuesAttack(amountOfDice);
}

void Player:: getDiceRollsDefend(int amountOfDice){
    dice.getDiceValuesDefend(amountOfDice);
}

void Player::transferCountryTo(string countryName, Player *player) {
    Country* toBeTransfered = countries[countryName];
    toBeTransfered->setOwner(player->getPlayerId());
    
    map<string,Country*>::iterator it = countries.find(countryName);
    countries.erase(it);
    
    player->addCountry(toBeTransfered);
}

vector<Country*> Player::getAllCountries() {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        if(country.second->getOwner() != this->id) {
            countries.erase(country.second->getName());
        } else {
            theCountries.push_back(country.second);
        }
    }
    return theCountries;
}

vector<Country*> Player::getCountriesByContinent(string continent) {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        if(country.second->getContinentName() == continent) {
            if(country.second->getOwner() != this->id) {
                countries.erase(country.second->getName());
            } else {
                theCountries.push_back(country.second);
            }
        }
    }
    return theCountries;
}




bool Player::controlsContinent(string name, GameMap *gameMap) {
    return getCountriesByContinent(name).size() == gameMap->getAllByContinent(name).size();
}



