//
//  main.cpp
//  PlayerDriver
//
//  Created by Allan Pichardo on 10/4/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "player.h"

int main(int argc, const char * argv[]) {
    
    Player player;
    
    cout << "Player #" << player.getPlayerId() << ":" << endl;
    
    player.attack();
    player.fortify();
    player.reinforce();
    
    cout << "Player's card count:  " << player.getCardsCount() << endl;
    cout << "Drawing one card..." << endl;
    
    //player.drawCard(<#Deck *deck#>)
    
    count << "New card count is: " << player.getCardsCount() << endl << endl;
    
    return 0;
}
