
#include "cardsdeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    srand(time(NULL));
    Deck deck1;
    Hand hand1 = Hand();
    
    const int initalNumOfCardsInDeck = deck1.getTotalCardsInDeck();
    int infantryCounter = 0;
    int artilleryCounter = 0;
    int cavalryCounter = 0;
    
    for(int i=0; i < initalNumOfCardsInDeck; i++)
    {
        deck1.draw(&hand1);
        if(deck1.getCardTypeDrawn() == "infantry")
            infantryCounter++;
        if(deck1.getCardTypeDrawn() == "artillery")
            artilleryCounter++;
        if(deck1.getCardTypeDrawn() == "cavalry")
            cavalryCounter++;
    }
    cout << "Number of infantry cards in deck: " + to_string(infantryCounter) << endl;
    cout << "Number of artillery cards in deck: " + to_string(artilleryCounter) << endl;
    cout << "Number of cavalry cards in deck: " + to_string(cavalryCounter) << endl;
    
    hand1 = NULL;
    
    cout << "" << endl;
    
    Deck deck2;
    Hand hand2 = Hand();
    
    infantryCounter = 0;
    artilleryCounter = 0;
    cavalryCounter = 0;
    
    for(int i=0; i < 9; i++)
    {
        deck2.draw(&hand2);
        if(deck2.getCardTypeDrawn() == "infantry")
            infantryCounter++;
        if(deck2.getCardTypeDrawn() == "artillery")
            artilleryCounter++;
        if(deck2.getCardTypeDrawn() == "cavalry")
            cavalryCounter++;
    }
    cout << "Number of infantry cards in deck: " + to_string(infantryCounter) << endl;
    cout << "Number of artillery cards in deck: " + to_string(artilleryCounter) << endl;
    cout << "Number of cavalry cards in deck: " + to_string(cavalryCounter) << endl;
    
    cout << "" << endl;
    
    cout << "Exchange#1 armies recieved: " + to_string(hand2->exchange("1 of each Card Type")) << endl;
    cout << "Exchange#2 armies recieved: " + to_string(hand2->exchange("3 Infantry Cards")) << endl;
    cout << "Exchange#3 armies recieved: " + to_string(hand2->exchange("3 Artillery Cards")) << endl;
    cout << "Exchange#4 armies recieved: " + to_string(hand2->exchange("3 Cavalry Cards")) << endl;
    
    cout << "Total number of armies: " + to_string(hand2->getTotalNumOfArmies()) << endl;
    
    return 0;
}
