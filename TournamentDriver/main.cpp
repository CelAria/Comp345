//
//  main.cpp
//  TournamentDriver
//
//  Created by Celeste Pimm on 2018-11-26.
//  Copyright © 2018 comp345. All rights reserved.
//

#include <iostream>
#include "tournament.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string directory = "/Users/allanpichardo/Documents/Dev/Comp345/StatsWinnerDriver";
//   const string directory = "/Users/celestepimm/git/Comp345-newnew/StatsWinnerDriver";
    Tournament tournament;
    tournament.selectgamemode(directory);
    
}
