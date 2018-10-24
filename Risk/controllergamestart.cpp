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
    string tempinput;
    cin >> tempinput;
    numberofplayers= stoi(tempinput);
    
    if (cin.fail()){
        cout <<"not a valid player amount. Select players (2-6). Enter an integer";
        cin.clear();
        selectPlayers();
    }
    
    if(numberofplayers== 1 || numberofplayers== 2 ||numberofplayers== 3 ||numberofplayers== 4 ||numberofplayers== 5 ||numberofplayers== 6){
        cout << numberofplayers << " has been created" << endl;
    }
    return numberofplayers;
};








