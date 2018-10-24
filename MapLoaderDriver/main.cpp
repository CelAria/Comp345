
#include "maploader.h"
#include "Dice.h"
#include "gamemap.h"
#include "viewgamestart.h"
#include "controllergamestart.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>

/* WHEN THE DRIVER ASKS FOR THE FILE, MUST PASTE THE ENTIRE FILE PATH*/

using namespace std;

int main(int argc, const char * argv[]) {
    
Maploader mymaploader;
    
//    //Type in the full file path to the file you want to open
//
//    //example of "user input" style with terminal using filepaths
//    try
//    {
//    mymaploader.readmapfile();
//    cout << "read mapfile runs" << endl;
//    }
//    catch (runtime_error e)
//    {
//        cout << e.what() <<endl;
//    }
//
//    return 0;
    GameStart game;
    game.selectPlayers();
    
}
