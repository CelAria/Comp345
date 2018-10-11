#include "cardsdeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    cout << "Part 5: Cards deck/hand" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    srand(time(NULL));
    Deck testDeck;
    Hand testHand = Hand();
    
    cout << "Number of countries: 42" << endl;
    cout << "Number of cards in deck: " << testDeck.getTotalCardsInDeck() << endl;
    
    const int initalNumOfCardsInDeck = testDeck.getTotalCardsInDeck();
    int infantryCounter = 0;
    int artilleryCounter = 0;
    int cavalryCounter = 0;
    
    for(int i = 0; i < initalNumOfCardsInDeck; ++i)
    {
        testDeck.draw(&testHand);
        if(testDeck.getCardTypeDrawn() == "infantry")
            infantryCounter++;
        if(testDeck.getCardTypeDrawn() == "artillery")
            artilleryCounter++;
        if(testDeck.getCardTypeDrawn() == "cavalry")
            cavalryCounter++;
    }
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Deck of Risk cards that is composed of an equal share of infantry, artillery and cavalry cards: " << endl;
    cout << "\tNumber of infantry cards in deck: " + to_string(infantryCounter) << endl;
    cout << "\tNumber of artillery cards in deck: " + to_string(artilleryCounter) << endl;
    cout << "\tNumber of cavalry cards in deck: " + to_string(cavalryCounter) << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    Deck deck1;
    Hand hand1 = Hand();
    
    infantryCounter = 0;
    artilleryCounter = 0;
    cavalryCounter = 0;
    
    for(int i = 0; i < 11; ++i)
    {
        deck1.draw(&hand1);
        if(deck1.getCardTypeDrawn() == "infantry")
            infantryCounter++;
        if(deck1.getCardTypeDrawn() == "artillery")
            artilleryCounter++;
        if(deck1.getCardTypeDrawn() == "cavalry")
            cavalryCounter++;
    }
    
    cout << "New hand of Risk cards containg 11 cards to test the exchange method: " << endl;
    cout << "\tNumber of infantry cards in hand1: " << infantryCounter << endl;
    cout << "\tNumber of artillery cards in hand1: " << artilleryCounter << endl;
    cout << "\tNumber of cavalry cards in hand1: " << cavalryCounter << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Number of armies recieved from exchanging crads: " << endl;
    cout << "\tExchange#1 (1 of each Card Type) -> armies recieved: " << hand1.exchange("1 of each Card Type") << endl;
    cout << "\tExchange#2 (3 Infantry Cards) -> armies recieved: " << hand1.exchange("3 Infantry Cards") << endl;
    cout << "\tExchange#3 (3 Artillery Cards) -> armies recieved: " <<hand1.exchange("3 Artillery Cards") << endl;
    cout << "\tExchange#4 (3 Cavalry Cards) -> armies recieved: " << hand1.exchange("3 Cavalry Cards") << endl;
    cout << "Total number of armies recieved: " << hand1.getTotalNumOfArmies() << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    
    Deck deck2;
    Hand hand2 = Hand();
    
    infantryCounter = 0;
    artilleryCounter = 0;
    cavalryCounter = 0;
    
    for(int i = 0; i < 6; ++i)
    {
        deck2.draw(&hand2);
        if(deck2.getCardTypeDrawn() == "infantry")
            infantryCounter++;
        if(deck2.getCardTypeDrawn() == "artillery")
            artilleryCounter++;
        if(deck2.getCardTypeDrawn() == "cavalry")
            cavalryCounter++;
    }
    
    cout << "New hand of Risk cards containg 6 cards to test the exchange method once more: " << endl;
    cout << "\tNumber of infantry cards in hand2: " << infantryCounter << endl;
    cout << "\tNumber of artillery cards in hand2: " << artilleryCounter << endl;
    cout << "\tNumber of cavalry cards in hand2: " << cavalryCounter << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Number of armies recieved from exchanging crads: " << endl;
    cout << "\tExchange#1 (1 of each Card Type) -> armies recieved: " << hand2.exchange("1 of each Card Type") << endl;
    cout << "\tExchange#2 (3 Infantry Cards) -> armies recieved: " << hand2.exchange("3 Infantry Cards") << endl;
    cout << "\tExchange#3 (3 Artillery Cards) -> armies recieved: " <<hand2.exchange("3 Artillery Cards") << endl;
    cout << "\tExchange#4 (3 Cavalry Cards) -> armies recieved: " << hand2.exchange("3 Cavalry Cards") << endl;
    cout << "Total number of armies recieved: " << hand2.getTotalNumOfArmies() << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    return 0;
}
