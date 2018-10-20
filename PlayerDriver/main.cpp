//
//  main.cpp
//  PlayerDriver
//
//  Created by Allan Pichardo on 10/4/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"

int main(int argc, const char * argv[]) {
    
    Player player;
    Country canada = Country("Canada", "North America");
    Deck deck = Deck();
    
    cout << "Player #" << player.getPlayerId() << ":" << endl << endl;
    
//    player.attack();
//    player.fortify();
//    player.reinforce();
    
    cout << endl;
    
    cout << "Player currently has " << player.getCountriesCount() << " countries..." << endl;
    player.addCountry(&canada);
    cout << "Player now has " << player.getCountriesCount() << " countries." << endl;
    vector<Country*> allCountries = player.getAllCountries();
    for(int i = 0; i < allCountries.size(); i++) {
        cout << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;
    
    cout << "Player's card count:  " << player.getCardsCount() << endl;
    cout << "Drawing one card..." << endl;
    
    player.drawCard(&deck);
    
    cout << "New card count is: " << player.getCardsCount() << endl;
    cout << "Artillery: " << player.getHand().getNumOfArtilleryCards()
    << " Cavalry: " << player.getHand().getNumOfCavalryCards()
    << " Infantry: " << player.getHand().getNumOfInfantryCards() << endl << endl;
    
    cout << "Rolling 1 die:" << endl;
    cout << "Rolled: " << player.rollDice(1) << endl << endl;
    
    cout << "Rolling 2 die:" << endl;
    cout << "Rolled: " << player.rollDice(2) << endl << endl;
    
    cout << "Rolling the 3 die:" << endl;
    cout << "Rolled: " << player.rollDice(3) << endl << endl;
    
    return 0;
}
