
#include "maploader.h"
#include "Dice.h"
#include "gamemap.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Maploader mymaploader;
    //mymaploader.readmapfile();
    
    Dice dice3(1);
    dice3.rollDice(3);
    cout << dice3.getDiceValue() << endl;
    dice3.rollDice(3);
    cout << dice3.getDiceValue() << endl;
    dice3.rollDice(3);
    cout << dice3.getDiceValue() << endl;
    dice3.rollDice(3);
    cout << dice3.getDiceValue() << endl;
    
//    try
//    {
//    //mymaploader.readmapfile();
//    //cout << "read mapfile runs" << endl;
//    }
//    catch (runtime_error e)
//    {
//        cout << e.what() <<endl;
//    }
    
    return 0;
}
