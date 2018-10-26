//
//  viewgamestart.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-10-23.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "viewgamestart.h"

#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;

//print the available maps
void printMapDirectory(const string& name){
    cout << "here are all the maps in the directory:" << endl;
    boost::filesystem::path p(name);
    for(auto & p : boost::filesystem::directory_iterator(name)){ std::cout << p << std::endl; }
};

void printDeck(Deck* deck){
    cout << "there are " << deck->getTotalCardsInDeck() << " cards in the deck" << endl;
//    cout << "there are " << deck->getNumOfCavalryCards() << " cards in the deck" << endl;
//    cout << "there are " << deck->getNumOfInfantryCards() << " cards in the deck" << endl;
//    cout << "there are " << deck->getNumOfArtilleryCards() << " cards in the deck" << endl;
};




