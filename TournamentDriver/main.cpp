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
   
const string directory = "/Users/celestepimm/git/Comp345-Xcode/StatsWinnerDriver";
Tournament tournament;
    
/*TO DO: finish select gamemode, tournament loop,
 FINISH PRINT (at end) ADD IN THE DIFFERENT STRATEGIES, ONCE THEY ARE MADE
 number of turns*/
    
    // tournament.selectgamemode();
tournament.inputmaps(directory);
tournament.selectstrategies();
tournament.selectnumgames();
tournament.selectnumturns();
    //tournament.tournamentloop();
    
}
