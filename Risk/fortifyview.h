//
//  fortifyview.hpp
//  Risk
//
//  Created by Allan Pichardo on 10/20/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "country.h"
#include <vector>
#include <string>

using namespace std;

class FortifyView {
    
private:
    
public:
    Country* promptCountrySelect(string prompt, vector<Country*> countries, bool oneline = false);
    void presentFortify();
    Country* promptUserForOrigin(vector<Country*> countries);
    Country* promptUserForDestination(vector<Country*> countries);
    int promptUserForAmountOfArmies(Country* fromCountry);
    string countryToString(Country* country);
    bool promptUserYesNo(string prompt);
};

