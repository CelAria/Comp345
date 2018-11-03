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
//    AttackPhase playerAttack(this,gameMap);
//    playerAttack.attackLoop();
    

                             
    
}

void Player::fortify(GameMap* gameMap) {
    cout << "This is fortify" << endl;
//    FortifyController fortifyController = FortifyController(this, gameMap);
//    fortifyController.start();
}

void Player::reinforce(GameMap* gameMap) {
    cout << "This is reinforce" << endl;
    int numOfCountriesOwned = getCountriesCount();
    int numOfArmiesRecieved = (numOfCountriesOwned/3);
    if(numOfArmiesRecieved <= 3)
        numOfArmiesRecieved = 3;
    
    cout << "Num of Armies (before exchange): " << numOfArmiesRecieved << endl;
    cout << "Player currently has " << getCountriesCount() << " countries" << endl;
    cout << "Player currently has " << getCardsCount() << " cards" << endl;
    cout << "Artillery: " << getHand().getNumOfArtilleryCards()
    << " Cavalry: " << getHand().getNumOfCavalryCards()
    << " Infantry: " << getHand().getNumOfInfantryCards() << endl;
    
    while(getCardsCount() > 5){
        string userInput;
        cout <<"Type of card exchange: ";
        getline (cin, userInput);
        numOfArmiesRecieved = numOfArmiesRecieved + hand.exchange(userInput);
    }
    cout << "Num of Armies (after exchange): " << numOfArmiesRecieved << endl;

    cout <<""<< endl;
    
    cout << "New card count is: " << getCardsCount() << endl;
    cout << "Artillery: " << getHand().getNumOfArtilleryCards()
    << " Cavalry: " << getHand().getNumOfCavalryCards()
    << " Infantry: " << getHand().getNumOfInfantryCards() << endl << endl;
    
    vector<Country*> allCountries = getAllCountries();
    int numOfArmiesToPlace = (numOfArmiesRecieved/allCountries.size());
    int numOfArmiesLeft = (numOfArmiesRecieved%allCountries.size());
    
    for(int i = 0; i < allCountries.size(); i++) {
        gameMap->getCountry(allCountries[i]->getName())->setArmiesCount((gameMap->getCountry(allCountries[i]->getName())->getArmiesCount()+numOfArmiesToPlace));
    }
    gameMap->getCountry("Costa Rica")->setArmiesCount((gameMap->getCountry("Costa Rica")->getArmiesCount()+numOfArmiesLeft));
    
    for(int i = 0; i < allCountries.size(); i++) {
        cout << allCountries[i]->getName() << ", " << allCountries[i]->getArmiesCount() << endl;
    }
    
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
