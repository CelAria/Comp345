#include "player.h"
#include "cardsdeck.h"
#include "country.h"
#include "gamemap.h"
#include "fortifycontroller.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void Player::attack() {
    cout << "This is attack" << endl;
}

void Player::fortify() {
    cout << "This is fortify" << endl;
}

void Player::reinforce(GameMap* gameMap) {
    FortifyController fortifyController = FortifyController(this, gameMap);
    fortifyController.start();
}

void Player::addCountry(Country *country) {
    countries[country->getName()] = country;
}

void Player::drawCard(Deck* deck) {
    deck->draw(&hand);
}

int Player::rollDice(int amountOfDice) {
    return dice.rollDice(amountOfDice);
}

vector<Country*> Player::getAllCountries() {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        theCountries.push_back(country.second);
    }
    return theCountries;
}

vector<Country*> Player::getCountriesByContinent(string continent) {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        if(country.second->getContinentName() == continent) {
            theCountries.push_back(country.second);
        }
    }
    return theCountries;
}
