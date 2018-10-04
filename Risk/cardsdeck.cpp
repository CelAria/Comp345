#include "cardsdeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string randDistributingExtraTypeCards()
{
    int randNum = (0 + (rand() % (int)(2 - 0 + 1)));
    if(randNum == 0)
    {
        return "001";
    }
    else if(randNum == 1)
    {
        return "010";
    }
    else if(randNum == 2)
    {
        return "100";
    }
}

Deck::Deck() {
    totalNumberOfCards = 43;
    
    if(totalNumberOfCards % 3 == 0)
    {
        infantryCards = (totalNumberOfCards/3);
        artilleryCards = (totalNumberOfCards/3);
        cavalryCards = (totalNumberOfCards/3);
    }
    else if(totalNumberOfCards % 3 == 1)
    {
        string extraCard = randDistributingExtraTypeCards();
        infantryCards = ((totalNumberOfCards/3) + (int)(extraCard.at(0)));
        artilleryCards = ((totalNumberOfCards/3) + (int)(extraCard.at(1)));
        cavalryCards = ((totalNumberOfCards/3) + (int)(extraCard.at(2)));
    }
    else if(totalNumberOfCards % 3 == 2)
    {
        string extraCard = randDistributingExtraTypeCards();
        infantryCards = ((totalNumberOfCards/3) + stoi(extraCard));
        artilleryCards = ((totalNumberOfCards/3) + stoi(extraCard));
        cavalryCards = ((totalNumberOfCards/3) + stoi(extraCard));
    }
    cout << infantryCards << endl;
    cout << artilleryCards << endl;
    cout << artilleryCards << endl;
    
    
}



