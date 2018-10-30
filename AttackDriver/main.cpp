//
//  main.cpp
//  AttackDriver
//
//  Created by Matthew Salaciak on 2018-10-30.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"

int main(int argc, const char * argv[]) {

    Player player;
    Country canada = Country("Canada", "North America");

    cout << "Player #" << player.getPlayerId() << ":" << endl << endl;
    
    
    cout << "Player currently has " << player.getCountriesCount() << " countries..." << endl;
    
    player.addCountry(&canada);
    
    cout << "Player now has " << player.getCountriesCount() << " countries." << endl;
    
    
    
    player.attack();
    
    
    
    return 0;
}
