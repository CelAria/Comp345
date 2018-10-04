#pragma once

class Deck {
private:
    int totalNumberOfCards;
    int infantryCards;
    int artilleryCards;
    int cavalryCards;
    
public:
    Deck();
    void draw();
    void exchange();
    int getTotalCardsInDeck();
    int getNumOfInfantryCards();
    int getNumOfArtilleryCards();
    int getNumOfCavalryCards();
};
