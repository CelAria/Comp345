//
//  phaseview.cpp
//  Risk
//
//  Created by Allan Pichardo on 11/11/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "phaseview.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string PhaseView::getPhaseHeader() {
    string phaseName = "";
    switch(state.phase) {
        case REINFORCE:
            phaseName = "Reinforce";
            break;
        case ATTACK:
            phaseName = "Attack";
            break;
        case FORTIFY:
            phaseName = "Fortify";
            break;
    }
    stringstream outstream;
    outstream << "Player " << state.currentPlayer->getPlayerId() << " - " << phaseName << " Phase:" << endl << endl;
    return outstream.str();
}

void PhaseView::print() {
    clearScreen();
    cout << getPhaseHeader();
}

void PhaseView::update(State &state) {
    this->state = state;
    print();
}

void PhaseView::clearScreen() {
    system("clear");
}
