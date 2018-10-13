
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

/* WHEN THE DRIVER ASKS FOR THE FILE, MUST PASTE THE ENTIRE FILE PATH*/

using namespace std;

int main(int argc, const char * argv[]) {
    
Maploader mymaploader;
    
//example using hardcoding
    
//this example will print invalid
   mymaploader.readmapfile("./MapLoaderDriver/Brazil(brokenmap).map");
    
//these examples will work
   mymaploader.readmapfile("./MapLoaderDriver/Canada.map");
   mymaploader.readmapfile("./MapLoaderDriver/World.map");

    
    //example of "user input" style with terminal using filepaths
    try
    {
    mymaploader.readmapfile();
    cout << "read mapfile runs" << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() <<endl;
    }

    return 0;
}
