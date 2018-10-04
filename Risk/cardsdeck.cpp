#include "cardsdeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

Deck::Deck() {
    totalNumberOfCards = 42;
    if(totalNumberOfCards % 3 == 0)
    {
        infantryCards = (totalNumberOfCards/3);
        artilleryCards = (totalNumberOfCards/3);
        cavalryCards = (totalNumberOfCards/3);
    }
    else if(totalNumberOfCards % 3 == 1)
    {
        int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
        string extraCard;
        if(randNum == 0)
            extraCard = "001";
        else if(randNum == 1)
            extraCard = "010";
        else if(randNum == 2)
            extraCard = "100";
        infantryCards = ((totalNumberOfCards/3) + (extraCard.at(0)-48));
        artilleryCards = ((totalNumberOfCards/3) + (extraCard.at(1)-48));
        cavalryCards = ((totalNumberOfCards/3) + (extraCard.at(2)-48));
    }
    else if(totalNumberOfCards % 3 == 2)
    {
        int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
        string extraCard;
        if(randNum == 0)
            extraCard = "110";
        else if(randNum == 1)
            extraCard = "101";
        else if(randNum == 2)
            extraCard = "011";
        infantryCards = ((totalNumberOfCards/3) + (extraCard.at(0)-48));
        artilleryCards = ((totalNumberOfCards/3) + (extraCard.at(1)-48));
        cavalryCards = ((totalNumberOfCards/3) + (extraCard.at(2)-48));
    }
}

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

void Deck::draw(Hand *hand)
{
    if(howManyCardTypesLeft() == 3)
    {
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
        int randNum = (0 + (rand() % (int)(1 - 0 + 1)));
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

Hand::Hand()
{
    totalNumOfCardsInHand = 0;
    numOfInfantryCards = 0;
    numOfArtilleryCards = 0;
    numOfCavalryCards = 0;
    numOfArmies = 0;
    totalNumberOfArmies = 0;
}

bool Hand::isHandEmpty()
{
    if(getTotalCardsInHand() == 0)
        return true;
    else
        return false;
}
bool Hand::handContainsOneOfEachCardType()
{
    if(getNumOfInfantryCards() > 0 && getNumOfArtilleryCards() > 0 && getNumOfCavalryCards() > 0)
        return true;
    else
        return false;
}
bool Hand::handContains3InfantryCards()
{
    if(getNumOfInfantryCards() >= 3)
        return true;
    else
        return false;
}
bool Hand::handContains3ArtilleryCards()
{
    if(getNumOfArtilleryCards() >= 3)
        return true;
    else
        return false;
}
bool Hand::handContains3CavalryCards()
{
    if(getNumOfCavalryCards() >= 3)
        return true;
    else
        return false;
}
void Hand::incrementNumOfArmies()
{
    numOfArmies = numOfArmies + 5;
    totalNumberOfArmies += numOfArmies;
}

int Hand::exchange(string s){
    if(!isHandEmpty() && s.compare("1 of each Card Type") == 0 && handContainsOneOfEachCardType())
    {
        infantryMinusOne();
        artilleryMinusOne();
        cavalryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("3 Infantry Cards") == 0 && handContains3InfantryCards())
    {
        infantryMinusOne();
        artilleryMinusOne();
        cavalryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("3 Artillery Cards") == 0 && handContains3ArtilleryCards())
    {
        artilleryMinusOne();
        artilleryMinusOne();
        artilleryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else if(!isHandEmpty() && s.compare("3 Cavalry Cards") == 0 && handContains3CavalryCards())
    {
        cavalryMinusOne();
        cavalryMinusOne();
        cavalryMinusOne();
        incrementNumOfArmies();
        return getNumOfArmies();
    }
    else
    {
        return 0;
    }
}
