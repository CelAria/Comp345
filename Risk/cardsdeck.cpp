// Team project assignment #1 - Part 5
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
// Description: cpp file for the deck and hand
// ------------------------------------------------------
#include "cardsdeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//implementing the constroctor for Deck
Deck::Deck(int numberofcards) {
    totalNumberOfCards = numberofcards;
    //checking if the deck can be evenly divisible by 3
    if(totalNumberOfCards % 3 == 0)
    {
        infantryCards = (totalNumberOfCards/3);
        artilleryCards = (totalNumberOfCards/3);
        cavalryCards = (totalNumberOfCards/3);
    }
    else if(totalNumberOfCards % 3 == 1)
    {
        //initializing a random number between 0 and 2 to determine which type of card recives the reminder/extra
        int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
        string extraCard;
        if(randNum == 0)
            extraCard = "001";
        else if(randNum == 1)
            extraCard = "010";
        else if(randNum == 2)
            extraCard = "100";
        //add +0 or +1 to each type of card to ensure all cards are evenly and randomly distributed
        infantryCards = ((totalNumberOfCards/3) + (extraCard.at(0)-48));
        artilleryCards = ((totalNumberOfCards/3) + (extraCard.at(1)-48));
        cavalryCards = ((totalNumberOfCards/3) + (extraCard.at(2)-48));
    }
    else if(totalNumberOfCards % 3 == 2)
    {
        //initializing a random number between 0 and 2 to determine which type of card recives the reminder/extra
        int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
        string extraCard;
        if(randNum == 0)
            extraCard = "110";
        else if(randNum == 1)
            extraCard = "101";
        else if(randNum == 2)
            extraCard = "011";
        //add +0 or +1 to each type of card to ensure all cards are evenly and randomly distributed
        infantryCards = ((totalNumberOfCards/3) + (extraCard.at(0)-48));
        artilleryCards = ((totalNumberOfCards/3) + (extraCard.at(1)-48));
        cavalryCards = ((totalNumberOfCards/3) + (extraCard.at(2)-48));
    }
}

//determining how many type of each cards are left in the deck
int Deck::howManyCardTypesLeft(){
    if(infantryCards > 0 && artilleryCards > 0 && cavalryCards > 0)
        return 3;
    else if((infantryCards == 0 && artilleryCards > 0 && cavalryCards > 0) || (infantryCards > 0 && artilleryCards == 0 && cavalryCards > 0) || (infantryCards > 0 && artilleryCards > 0 && cavalryCards == 0))
        return 2;
    else if((infantryCards == 0 && artilleryCards == 0 && cavalryCards > 0) || (infantryCards == 0 && artilleryCards > 0 && cavalryCards == 0) || (infantryCards > 0 && artilleryCards == 0 && cavalryCards == 0))
        return 1;
    else if(infantryCards == 0 && artilleryCards == 0 && cavalryCards == 0)
        return 0;
    else
        return 0;
}

//implementing the draw method in Deck
void Deck::draw(Hand *hand)
{
    //check if the number of cards left in the deck is equal to 3 or equal to 2 or equal to 1
    if(howManyCardTypesLeft() == 3)
    {
        //initializing a random number between 0 and 2 to determine which type of card the hand recives
        int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
        if(randNum == 0)
        {
            infantryCardMinusOne();
            cardTypeBeingDrawn = "infantry";
            hand->infantryPlusOne();
        }
        else if(randNum == 1)
        {
            artilleryCardMinusOne();
            cardTypeBeingDrawn = "artillery";
            hand->artilleryPlusOne();
        }
        else if(randNum == 2)
        {
            cavalryCardMinusOne();
            cardTypeBeingDrawn = "cavalry";
            hand->cavalryPlusOne();
        }
    }
    else if(howManyCardTypesLeft() == 2)
    {
        //initializing a random number between 0 and 1 to determine which type of card the hand recives
        int randNum = (0 + (rand() % (int)(1 - 0 + 1)));
        //checks which type of cards are left from deck to determine which type of card the hand recives
        if(getNumOfInfantryCards() == 0 && getNumOfArtilleryCards() > 0 && getNumOfCavalryCards() > 0)
        {
            if(randNum == 0)
            {
                artilleryCardMinusOne();
                cardTypeBeingDrawn = "artillery";
                hand->artilleryPlusOne();
            }
            else if(randNum == 1)
            {
                cavalryCardMinusOne();
                cardTypeBeingDrawn = "cavalry";
                hand->cavalryPlusOne();
            }
        }
        else if(getNumOfInfantryCards() > 0 && getNumOfArtilleryCards() == 0 && getNumOfCavalryCards() > 0)
        {
            if(randNum == 0)
            {
                infantryCardMinusOne();
                cardTypeBeingDrawn = "infantry";
                hand->infantryPlusOne();
            }
            else if(randNum == 1)
            {
                cavalryCardMinusOne();
                cardTypeBeingDrawn = "cavalry";
                hand->cavalryPlusOne();
            }
        }
        else if(getNumOfInfantryCards() > 0 && getNumOfArtilleryCards() > 0 && getNumOfCavalryCards() == 0)
        {
            if(randNum == 0)
            {
                infantryCardMinusOne();
                cardTypeBeingDrawn = "infantry";
                hand->infantryPlusOne();
            }
            else if(randNum == 1)
            {
                artilleryCardMinusOne();
                cardTypeBeingDrawn = "artillery";
                hand->artilleryPlusOne();
            }
        }
    }
    else if(howManyCardTypesLeft() == 1)
    {
        //checks whiich type of card is left in the deck and gives that card to the hand
        if(getNumOfInfantryCards() > 0 && getNumOfArtilleryCards() == 0 && getNumOfCavalryCards() == 0)
        {
            infantryCardMinusOne();
            cardTypeBeingDrawn = "infantry";
            hand->infantryPlusOne();
        }
        else if(getNumOfInfantryCards() == 0 && getNumOfArtilleryCards() > 0 && getNumOfCavalryCards() == 0)
        {
            artilleryCardMinusOne();
            cardTypeBeingDrawn = "artillery";
            hand->artilleryPlusOne();
        }
        else if(getNumOfInfantryCards() == 0 && getNumOfArtilleryCards() == 0 && getNumOfCavalryCards() > 0)
        {
            cavalryCardMinusOne();
            cardTypeBeingDrawn = "cavalry";
            hand->cavalryPlusOne();
        }
    }
    else if(howManyCardTypesLeft() <= 0)
    {
        cout << "No more cards remaning in deck" << endl;
    }
}

//implementing the constroctor for Hand
Hand::Hand()
{
    totalNumOfCardsInHand = 0;
    numOfInfantryCards = 0;
    numOfArtilleryCards = 0;
    numOfCavalryCards = 0;
    numOfArmies = 0;
    totalNumberOfArmies = 0;
}

//return true if the number of cards in the hand is 0 and false otherwise
bool Hand::isHandEmpty()
{
    return(getTotalCardsInHand() == 0);
}

//returns true if the hand contains one type of each card and false otherwise
bool Hand::handContainsOneOfEachCardType()
{
    return(getNumOfInfantryCards() > 0 && getNumOfArtilleryCards() > 0 && getNumOfCavalryCards() > 0);
}

//returns ture is the hand contains 3 infrantry cards and false otherwise
bool Hand::handContains3InfantryCards()
{
    return(getNumOfInfantryCards() >= 3);
}

//returns tru if the hand contains 3 artillery cards and false otherwise
bool Hand::handContains3ArtilleryCards()
{
    return(getNumOfArtilleryCards() >= 3);
}

//returns true if the hand contains 3 cavarly cards and false otherwise
bool Hand::handContains3CavalryCards()
{
    return(getNumOfCavalryCards() >= 3);
}

//increments the number of armies the hand will recieve for the current and the next set of cards exchanged
void Hand::incrementNumOfArmies()
{
    numOfArmies = numOfArmies + 5;
    totalNumberOfArmies += numOfArmies;
}

//implementing the exchange method for Hand
int Hand::exchange(string s){
    //if and else if statments determines if the exchange requested by the hand is valid or not and returns the number of recieved armies
    if(!isHandEmpty() && s.compare("0") == 0 && handContainsOneOfEachCardType())
    {
        infantryMinusOne();
        artilleryMinusOne();
        cavalryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("1") == 0 && handContains3InfantryCards())
    {
        infantryMinusOne();
        infantryMinusOne();
        infantryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("2") == 0 && handContains3ArtilleryCards())
    {
        artilleryMinusOne();
        artilleryMinusOne();
        artilleryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("3") == 0 && handContains3CavalryCards())
    {
        cavalryMinusOne();
        cavalryMinusOne();
        cavalryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else
    {
        cout << "Invalid exchange!" << endl;
        return 0;
    }
}
