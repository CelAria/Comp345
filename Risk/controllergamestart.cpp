//
//  gamestart.cpp
//  Risk
//
//  Created by Celeste Pimm on 2018-10-22.
//  Copyright © 2018 comp345. All rights reserved.
//
// this file is to do the game start functions
#include "controllergamestart.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <fstream>
#include <iostream>

using namespace std;

//read in using string stream, turn into integer, return integer value for number of players
int GameStart::selectPlayers(){
    cout << "please input the number of players (2-6). Type using numbers such as 1,2,3,4." << endl;
    cin >> numberofplayers;
    
    if(numberofplayers){
        
    }
    
    return numberofplayers;
};








