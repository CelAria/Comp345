//
//  fortifyview.cpp
//  Risk
//
//  Created by Allan Pichardo on 10/20/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include "fortifyview.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "country.h"

using namespace std;

void FortifyView::presentFortify() {
    cout << "Fortify phase:" << endl << endl;
}

Country* FortifyView::promptUserForOrigin(vector<Country *> countries) {
    return promptCountrySelect("Choose a country to move armies from:", countries);
}

Country* FortifyView::promptUserForDestination(vector<Country *> countries) {
    return promptCountrySelect("Choose a country to move armies to:", countries, true);
}

int FortifyView::promptUserForAmountOfArmies(Country* fromCountry) {
    cout << "You can move up to " << fromCountry->getArmiesCount() - 1 << " armies." << endl;
    cout << "How many will you move?" << endl;
    
    cout << "> ";
    int amount;
    cin >> amount;
    
    if(!cin.good() || amount < 1 || amount > fromCountry->getArmiesCount() - 1) {
        //handle invalid input
    }
    
    return amount;
}

Country* FortifyView::promptCountrySelect(string prompt, vector<Country*> countries, bool oneline) {
    cout << prompt << endl << endl;
    for(int i = 0; i < countries.size(); ++i) {
        cout << i + 1 << ".\t" << countries[i]->toString() << endl;
        
        if(!oneline) {
            vector<Country*> neighbors = countries[i]->getAllNeighbors();
            for(int j = 0; j < neighbors.size(); j++) {
                cout << "\t|" << endl;
                cout << "\t -- ";
                cout << neighbors[j]->toString() << endl;
            }
        }
        
        cout << endl;
    }
    cout << endl;
    
    cout << "> ";
    int selection;
    cin >> selection;
    
    if(!cin.good() || selection < 1 || selection > countries.size()) {
        return NULL;
    }
    
    return countries[selection - 1];
}
