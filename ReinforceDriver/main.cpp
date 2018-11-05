//
//  main.cpp
//  ReinforceDriver
//
//  Created by Martin-John Hearty on 2018-10-31.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"
#include "gamemap.h"
#include "cardsdeck.h"
#include "maploader.h"


int main(int argc, const char * argv[]) {
    cout << "Driver - Part 4: Main game loop: reinforcement phase" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    
    //instantiate a player, a game map and a deck of cards
    Player player(1);
    GameMap gameMap;
    Deck deck = Deck(42);
    
    //Maploader mymaoloader;
    //mymaoloader.readmapfile("/Users/martin-john/Documents/Comp345/MapLoaderDriver/World.map");
    //the following indented block of code is to fill up a test game map
    
        Continent centralAmerica = Continent("Central America", 3);
        Continent southAmerica = Continent("South America", 2);
        cout << "Game Map has 2 continents and 5 countries" << endl;
        cout<<endl;
    
        gameMap.addContinent(centralAmerica);
        gameMap.addContinent(southAmerica);
    
        vector<string> nicNeighbors;
        nicNeighbors.push_back("Costa Rica");
        gameMap.addCountry("Nicaragua", "Central America", nicNeighbors);
    
        vector<string> cosNeighbors;
        cosNeighbors.push_back("Nicaragua");
        cosNeighbors.push_back("Panama");
        gameMap.addCountry("Costa Rica", "Central America", cosNeighbors);
    
        vector<string> panNeighbors;
        panNeighbors.push_back("Costa Rica");
        panNeighbors.push_back("Colombia");
        gameMap.addCountry("Panama", "Central America", panNeighbors);
    
        vector<string> colNeighbors;
        colNeighbors.push_back("Panama");
        colNeighbors.push_back("Venezuela");
        gameMap.addCountry("Colombia", "South America", colNeighbors);
    
        vector<string> venNeighbors;
        venNeighbors.push_back("Colombia");
        gameMap.addCountry("Venezuela", "South America", venNeighbors);
    
        gameMap.getCountry("Costa Rica")->setArmiesCount(2);
        gameMap.getCountry("Venezuela")->setArmiesCount(4);
        gameMap.getCountry("Colombia")->setArmiesCount(1);
        gameMap.getCountry("Panama")->setArmiesCount(1);
        gameMap.getCountry("Nicaragua")->setArmiesCount(1);
    
    //add countries to player 1
    player.addCountry(gameMap.getCountry("Costa Rica"));
    player.addCountry(gameMap.getCountry("Venezuela"));
    player.addCountry(gameMap.getCountry("Colombia"));
    player.addCountry(gameMap.getCountry("Panama"));
  
    //number of countries owened by the player
    cout << "Player1 now has " << player.getCountriesCount() << " countries:" << endl;
    vector<Country*> allCountries = player.getAllCountries();
    //displays the countries and their continents player 1 owns
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;
    
    //gives player 1, six cards in its hand
    for(int i=0; i< 9; ++i)
    {
        player.drawCard(&deck);
    }
    //calls the reinforce method of the player to test it
    player.reinforce(&gameMap);
    
    return 0;
}
