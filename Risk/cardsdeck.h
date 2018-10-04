#pragma once
#include <string>
using namespace std;

class Hand {
private:
    int totalNumOfCardsInHand;
    int numOfInfantryCards;
    int numOfArtilleryCards;
    int numOfCavalryCards;
    int numOfArmies;
    int totalNumberOfArmies;
    
public:
    Hand();
    int exchange(string s);
    int getNumOfArmies(){ return numOfArmies; }
    int getTotalNumOfArmies(){ return totalNumberOfArmies; }
    void incrementNumOfArmies();
    int getTotalCardsInHand(){ return totalNumOfCardsInHand; }
    int getNumOfInfantryCards(){ return numOfInfantryCards; }
    int getNumOfArtilleryCards(){ return numOfArtilleryCards; }
    int getNumOfCavalryCards(){ return numOfCavalryCards; }
    void infantryPlusOne(){ numOfInfantryCards++; totalNumOfCardsInHand++; }
    void artilleryPlusOne(){ numOfArtilleryCards++; totalNumOfCardsInHand++; }
    void cavalryPlusOne(){ numOfCavalryCards++; totalNumOfCardsInHand++; }
    void infantryMinusOne(){ numOfInfantryCards--; totalNumOfCardsInHand--; }
    void artilleryMinusOne(){ numOfArtilleryCards--; totalNumOfCardsInHand--; }
    void cavalryMinusOne(){ numOfCavalryCards--; totalNumOfCardsInHand--; }
    bool isHandEmpty();
    bool handContainsOneOfEachCardType();
    bool handContains3InfantryCards();
    bool handContains3ArtilleryCards();
    bool handContains3CavalryCards();
};

class Deck {
private:
    int infantryCards;
    int artilleryCards;
    int cavalryCards;
    int totalNumberOfCards;
    string cardTypeBeingDrawn;
    
public:
    Deck();
    void draw(Hand *hand);
    string getCardTypeDrawn(){ return cardTypeBeingDrawn; }
    int getTotalCardsInDeck(){ return totalNumberOfCards; }
    int getNumOfInfantryCards(){ return infantryCards; }
    int getNumOfArtilleryCards(){ return artilleryCards; }
    int getNumOfCavalryCards(){ return cavalryCards; }
    void infantryCardMinusOne(){ infantryCards--; totalNumberOfCards--; }
    void artilleryCardMinusOne(){ artilleryCards--; totalNumberOfCards--; }
    void cavalryCardMinusOne(){ cavalryCards--; totalNumberOfCards--; }
    int howManyCardTypesLeft();
};
