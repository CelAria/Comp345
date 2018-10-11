// Team project assignment #1 - Part 5
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
// Description: header file for the deck and hand
// ------------------------------------------------------
#pragma once
#include <string>
using namespace std;

/*Declaring Hand class*/
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
    //exchange mehthod with string parameter to indicate what exchange the player wants to do
    int exchange(string s);
    int getNumOfArmies(){ return numOfArmies; }
    int getTotalNumOfArmies(){ return totalNumberOfArmies; }
    //increment the number of arimes every time a set of cards is exchanged
    void incrementNumOfArmies();
    //getter methods
    int getTotalCardsInHand(){ return totalNumOfCardsInHand; }
    int getNumOfInfantryCards(){ return numOfInfantryCards; }
    int getNumOfArtilleryCards(){ return numOfArtilleryCards; }
    int getNumOfCavalryCards(){ return numOfCavalryCards; }
    //increment and decrement number of cards of a certain type in a hand
    void infantryPlusOne(){ numOfInfantryCards++; totalNumOfCardsInHand++; }
    void artilleryPlusOne(){ numOfArtilleryCards++; totalNumOfCardsInHand++; }
    void cavalryPlusOne(){ numOfCavalryCards++; totalNumOfCardsInHand++; }
    void infantryMinusOne(){ numOfInfantryCards--; totalNumOfCardsInHand--; }
    void artilleryMinusOne(){ numOfArtilleryCards--; totalNumOfCardsInHand--; }
    void cavalryMinusOne(){ numOfCavalryCards--; totalNumOfCardsInHand--; }
    //methods that check the current status of a hand
    bool isHandEmpty();
    bool handContainsOneOfEachCardType();
    bool handContains3InfantryCards();
    bool handContains3ArtilleryCards();
    bool handContains3CavalryCards();
};

/*Declaring Deck class*/
class Deck {
private:
    int infantryCards;
    int artilleryCards;
    int cavalryCards;
    int totalNumberOfCards;
    string cardTypeBeingDrawn;
    
public:
    Deck();
    //draw method that has a Hand parameter being passed by pointer
    void draw(Hand *hand);
    //getter methods
    string getCardTypeDrawn(){ return cardTypeBeingDrawn; }
    int getTotalCardsInDeck(){ return totalNumberOfCards; }
    int getNumOfInfantryCards(){ return infantryCards; }
    int getNumOfArtilleryCards(){ return artilleryCards; }
    int getNumOfCavalryCards(){ return cavalryCards; }
    //decrement the type of cards in deck
    void infantryCardMinusOne(){ infantryCards--; totalNumberOfCards--; }
    void artilleryCardMinusOne(){ artilleryCards--; totalNumberOfCards--; }
    void cavalryCardMinusOne(){ cavalryCards--; totalNumberOfCards--; }
    //methods that check the current status of a deck
    int howManyCardTypesLeft();
};
