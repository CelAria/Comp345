//
//  phaseview.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/11/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "phaseview.h"
#include "player.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string PhaseView::getPhaseHeader() {
    string phaseName = "";
    switch(state.phase) {
        case REINFORCE:
            return getHeaderWith("Reinforce");
            break;
        case ATTACK:
            return getHeaderWith("Attack");
            break;
        case FORTIFY:
            return getHeaderWith("Fortify");
            break;
        case MOVE_COUNTRY:
            return "";
            break;
        case GAME_OVER:
            return "";
    }
}

string PhaseView::getHeaderWith(string phaseName) {
    stringstream outstream;
    outstream << "****************************************************" << endl;
    outstream << "Player " << state.currentPlayer->getPlayerId() << " - " << phaseName << " Phase:" << endl;
    outstream << "****************************************************" << endl << endl;
    return outstream.str();
}

void PhaseView::print() {
    clearScreen();
    if(state.phase == REINFORCE) {
        cout << endl;
        cout << "****************************************************" << endl;
        cout << "Player " << state.currentPlayer->getPlayerId() << " Turn Start" << endl;
        cout << "****************************************************" << endl;
        cout << endl;
        if(state.currentPlayer->getStrategy()->getType() == 0) {
            if(promptUserYesNo("Would you like to see the game map? (y/n)")) {
                state.gameMap->traverseAll(true);
            }
        }
    }
    cout << getPhaseHeader();
}

void PhaseView::update(State &state) {
    this->state = state;
    if(state.currentPlayer->getAllCountries().size() > 0) {
        print();
    }
}

void PhaseView::clearScreen() {
    //system("clear");
}

bool PhaseView::promptUserYesNo(string prompt) {
    cout << prompt << endl;
    
    char answer;
    cin >> answer;
    
    if(cin.good()) {
        if(answer == 'y' || answer == 'Y') {
            return true;
        } else if(answer == 'n' || answer == 'N') {
            return false;
        } else {
            return promptUserYesNo(prompt);
        }
    } else {
        return false;
    }
}
