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
#include "country.h"

using namespace std;

void FortifyView::presentFortify() {
    cout << "Fortify phase:" << endl << endl;
    
    Country* toCountry = showCountrySelectList(player->getAllCountries());
    
}

Country* FortifyView::showCountrySelectList(vector<Country*> countries) {
    cout << "Select a country:" << endl << endl;
    for(int i = 0; i < countries.size(); ++i) {
        cout << i + 1 << ".\t" << countries[i]->getName() << "\t\t(" << countries[i]->getArmiesCount() << " Armies)" << endl;
    }
    cout << endl;
    
    int selection;
    cin >> selection;
    
    if(!cin.good() || selection < 1 || selection > countries.size()) {
        return NULL;
    }

    return countries[selection];
}
