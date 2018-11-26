#include "maploader.h"
#include "gamemap.h"
#include "viewgamestart.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

static void printDirectory(string directory){
    boost::filesystem::path p(directory);
    int counter=1;
    for(auto & p : boost::filesystem::directory_iterator(directory)){
        cout << counter << "." << p << endl;
        counter++;
    }
}

string Maploader::selectMap(string directory){
    cout << "Select which map you would like to load by typing the index number value" << endl;
    int a;
    cin >> a;
    string selectedmap;
    int counter=0;
    
    boost::filesystem::path p(directory);
    for(auto & p : boost::filesystem::directory_iterator(directory)){
        counter++;
    }
    
    if (cin.good())
    {
        if(a > (counter) || a ==0 || a < 0){
            cout << "value does not exist in list. Try again" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            return selectMap(directory);
        }
        else
        {
            cout << "\nmap number " << a << " selected" << endl;
            int counter2=0;
            for(auto & p : boost::filesystem::directory_iterator(directory)){
                counter2++;
                if(counter2==a){
                    selectedmap.assign(p.path().string());
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    return selectedmap;
                }
            }
        }
        return selectMap(directory);
    }
    else
    {
        cout << "Not an integer." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
        return selectMap(directory);
    }
}

GameMap* Maploader::readmapfile(string file, string directory){
   ptrgamemap = new GameMap();
    
    filename = file;
    //string variable for each line parsed by fstream
    string line;
    //uses filename and fstream
   
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map.";
        delete ptrgamemap;
        ptrgamemap= NULL;
        filename.clear();
        readmapfile(selectMap(directory), directory);
        
    }
    
    fstream.open(filename);
    
    //if file opens succesfully
    if(fstream.is_open()){
        
        bool isInContinent = false;
        bool isInTerritory = false;
        
        while(!fstream.eof()){
            
            getline(fstream,line);
            
            //Removing the windows \r character"
            if(!line.empty() && *line.rbegin() == '\r') {
                line.erase( line.length()-1, 1);
            }
            
            if(line == "[Continents]") {
                isInContinent = true;
                isInTerritory = false;
                continue;
                
            } else if(line == "[Territories]") {
                isInContinent = false;
                isInTerritory = true;
                continue;
                
            } else if(line == "") {
                continue;
            }
            
            if(isInContinent) {
                parseContinent(line);
            }
            if(isInTerritory) {
                parseTerritory(line);
            }
            
        }
        
        fstream.close();
        
        
        //If map invalid, reject and offer readmap() again, if valid, accept
        
        if(ptrgamemap->isValid()){
            ptrgamemap->traverseAll(false);
            cout << "This gamemap is valid! \n";
        }
        
        
        if(!ptrgamemap->isValid()){
            cout << "gamemap is invalid. It has been deleted. Try again with a valid map file\n";
            delete ptrgamemap;
            ptrgamemap= NULL;
            readmapfile(selectMap(directory), directory);
        }
        
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile(selectMap(directory), directory);
    }
    return ptrgamemap;
}


void Maploader::parseContinent(string line) {
    //for each token, push into the array of tokens.
    
    std::string token;
    char delimiter = '=';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    
    std::getline(ss, token, delimiter);
    points = stoi(token);
    
    Continent continent = Continent(name, points);
    ptrgamemap->addContinent(continent);
}

void Maploader::parseTerritory(string line) {
   
    std::string token;
    char delimiter = ',';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    
    std::getline(ss, token, delimiter);
    xcoord = token;
    
    std::getline(ss, token, delimiter);
    ycoord = token;
    
    std::getline(ss, token, delimiter);
    continentname = token;
   
    while(std::getline(ss, token, delimiter)){
         neighbor = token;
         neighbors.push_back(token);
    }
    
    ptrgamemap->addCountry(name, continentname, neighbors);
    neighbors.clear();
}

