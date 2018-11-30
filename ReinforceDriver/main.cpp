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
#include "strategy.h"


int main(int argc, const char * argv[]) {
    cout << "Driver - Part 4: Main game loop: reinforcement phase" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    
    //instantiate a player, a game map and a deck of cards
    Strategy* strategy1(new RandomStrategy);
    Strategy* strategy2(new BenevolentStrategy);
    Strategy* strategy3(new AggressiveStrategy);
    
    //declare 3 players with 3 different strategies
    Player player1(1, strategy1);
    Player player2(2, strategy2);
    Player player3(3, strategy3);
    //declare a game map
    GameMap gameMap;
    //declare a deck
    Deck deck = Deck(42);
    
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
    
        //sets the army count
        gameMap.getCountry("Costa Rica")->setArmiesCount(2);
        gameMap.getCountry("Venezuela")->setArmiesCount(4);
        gameMap.getCountry("Colombia")->setArmiesCount(1);
        gameMap.getCountry("Panama")->setArmiesCount(1);
        gameMap.getCountry("Nicaragua")->setArmiesCount(1);
    
    //case 1 - human strategy
    //add countries to player 1
    player1.addCountry(gameMap.getCountry("Costa Rica"));
    player1.addCountry(gameMap.getCountry("Venezuela"));
    player1.addCountry(gameMap.getCountry("Colombia"));
    player1.addCountry(gameMap.getCountry("Panama"));
  
    //number of countries owened by the player
    cout << "Player1 now has " << player1.getCountriesCount() << " countries:" << endl;
    vector<Country*> allCountries = player1.getAllCountries();
    //displays the countries and their continents player 1 owns
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;
    
    //gives player 1, six cards in its hand
    for(int i=0; i< 9; ++i)
    {
        player1.drawCard(&deck);
    }
    //calls the reinforce method of the player to test it
    player1.reinforce(&gameMap);
    
    //case 2 - agressive strategy
    //add countries to player 1
    player2.addCountry(gameMap.getCountry("Costa Rica"));
    player2.addCountry(gameMap.getCountry("Venezuela"));
    player2.addCountry(gameMap.getCountry("Colombia"));
    player2.addCountry(gameMap.getCountry("Panama"));
    
    //resets the army count
    gameMap.getCountry("Costa Rica")->setArmiesCount(2);
    gameMap.getCountry("Venezuela")->setArmiesCount(4);
    gameMap.getCountry("Colombia")->setArmiesCount(1);
    gameMap.getCountry("Panama")->setArmiesCount(1);
    gameMap.getCountry("Nicaragua")->setArmiesCount(1);

    //number of countries owened by the player
    cout << "Player2 now has " << player2.getCountriesCount() << " countries:" << endl;
    allCountries = player2.getAllCountries();
    //displays the countries and their continents player 1 owns
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;

    //gives player 1, six cards in its hand
    for(int i=0; i< 9; ++i)
    {
        player2.drawCard(&deck);
    }
    //calls the reinforce method of the player to test it
    player2.reinforce(&gameMap);
    
    //case 3 - passive strategy
    //add countries to player 1
    player3.addCountry(gameMap.getCountry("Costa Rica"));
    player3.addCountry(gameMap.getCountry("Venezuela"));
    player3.addCountry(gameMap.getCountry("Colombia"));
    player3.addCountry(gameMap.getCountry("Panama"));
    
    //resets the army count
    gameMap.getCountry("Costa Rica")->setArmiesCount(2);
    gameMap.getCountry("Venezuela")->setArmiesCount(4);
    gameMap.getCountry("Colombia")->setArmiesCount(1);
    gameMap.getCountry("Panama")->setArmiesCount(1);
    gameMap.getCountry("Nicaragua")->setArmiesCount(1);
    
    //number of countries owened by the player
    cout << "Player2 now has " << player3.getCountriesCount() << " countries:" << endl;
    allCountries = player3.getAllCountries();
    //displays the countries and their continents player 1 owns
    for(int i = 0; i < allCountries.size(); i++)
    {
        cout << "\t• " << allCountries[i]->getName() << ", " << allCountries[i]->getContinentName() << endl;
    }
    cout << endl;
    
    //gives player 1, six cards in its hand
    for(int i=0; i< 9; ++i)
    {
        player3.drawCard(&deck);
    }
    //calls the reinforce method of the player to test it
    player3.reinforce(&gameMap);
    
    
    return 0;
}
