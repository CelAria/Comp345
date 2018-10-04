#include "player.h"
#include "cardsdeck.h"

#include <iostream>
#include <string>
using namespace std;

void Player::attack() {
    cout << "This is attack" << endl;
}

void Player::fortify() {
    cout << "This is fortify" << endl;
}

void Player::reinforce() {
    cout << "This is reinforce" << endl;
}

int Player::getPlayerId() {
    return id;
}

void Player::addCountry(Country *country) {
    countries[country->getName()] = country;
}

int Player::getCardsCount() {
    return hand.getTotalCardsInHand();
}

void Player::drawCard(Deck* deck) {
    deck->draw(&hand);
}

int Player::rollDice(int amountOfDice) {
    return dice.rollDice(amountOfDice);
}
