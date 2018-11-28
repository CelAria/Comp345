//
//  tournament.h
//  Risk
//
//  Created by Celeste Pimm on 2018-11-26.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once
#include <vector>
#include <string>
#include "gamemap.h"
#include "strategy.h"


using namespace std;
/*
A tournament starts with the user choosing M = 1 to 5 different maps, P = 2 to 4 different computer players
strategies, G = 1 to 5 games to be played on each map, D = 10 to 50 maximum number of turns for each game. A
tournament is then automatically played by playing G games on each of the M different maps between the chosen
computer player strategies. In order to minimize run completion time, each game should be declared a draw after
D turns. Once started, the tournament plays all the games automatically without user interaction. At the end of the
tournament, a report of the results should be displayed, e.g.

 You must deliver a driver that demonstrates that (1) when the game starts, the user is given the choice between
 single game mode and tournament mode; (2) when the tournament mode is chosen, the user is asked to select
 (2a) from 1 to 5 maps; (2b) from 2 to 4 players which can be any of the computer player strategies (no human
 computer should be allowed in tournament mode); (2c) the number of games (from 1 to 5) to be played on each
 map; (2d) the number of turns after which each game is to be considered a draw (3 to 50 turns); (3) after being
 started, the tournament runs without any user interaction; (4) upon completion, the results of the tournament are
 displayed as depicted above. */

class Tournament{
    
private:
    vector<Player*> players;
    vector<string> selectedmaps;
    vector<int> selectedstrategies;
    int nummaps;
    int numstrategies;
    int numgames;
    int numturns;
    void assignStrategies();
    int inputnumMaps();
    int inputnumPlayers();
    int inputnumGames();
    int inputnumTurns();
    void StrategySwitch();
    void printheader();
    void printcolumns();
    void extractFileName(const string& fullPath);
    vector<Player*> winners; 
    
public:
    void selectgamemode();
    void printStrategies();
    int selectnumgames();
    int selectnumturns();
    void tournamentloop(string directory);
    vector<int> selectstrategies();
    vector<string> inputmaps(const string directory);
    void print();
    
    
};
