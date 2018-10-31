#include "player.h"
#include "cardsdeck.h"
#include "country.h"
#include "gamemap.h"
#include "fortifycontroller.h"
#include "attackphase.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void Player::attack(GameMap *gameMap) {
    cout << "This is attack" << endl;
    AttackPhase playerAttack(this, gameMap);
    playerAttack.attackLoop();
    
    
                             
    
}

void Player::fortify() {
    cout << "This is fortify" << endl;
}

void Player::reinforce(GameMap* gameMap) {
    FortifyController fortifyController = FortifyController(this, gameMap);
    fortifyController.start();
}

void Player::addCountry(Country *country) {
    country->setOwner(id);
    countries[country->getName()] = country;
}

void Player::drawCard(Deck* deck) {
    deck->draw(&hand);
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

bool Player::controlsContinent(string name, GameMap *gameMap) {
    return getCountriesByContinent(name).size() == gameMap->getAllByContinent(name).size();
}
