//
//  phaseview.h
//  Risk
//
//  Created by Allan Pichardo on 11/11/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "observer.h"
#include <string>

class PhaseView : public Observer {
private:
    State state;
    
    string getPhaseHeader();
    void clearScreen();
public:
    void print();
    void update(State& state);
    bool promptUserYesNo(string prompt);
    string getHeaderWith(string phaseName);
};
